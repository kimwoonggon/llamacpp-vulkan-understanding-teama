"""Run Graphify on the pinned lab source, then add evidence/code navigation."""
from pathlib import Path
from collections import Counter, defaultdict
import argparse, base64, hashlib, importlib.metadata, json, re, shutil, subprocess, sys
from datetime import datetime, timezone
sys.stdout.reconfigure(encoding='utf-8')
from graphify.detect import detect, save_manifest
from graphify.benchmark import run_benchmark, print_benchmark
from graphify.extract import extract
from graphify.build import build_from_json
from graphify.cluster import cluster, score_all
from graphify.analyze import god_nodes, surprising_connections, suggest_questions
from graphify.report import generate
from graphify.export import to_html, to_json, to_obsidian, to_canvas
from tree_sitter import Language, Parser
import tree_sitter_cpp, tree_sitter_c

HERE=Path(__file__).resolve().parent
LAB=HERE.parent
SRC=LAB/'llama.cpp'
OUT=LAB/'graphify-out'
CORPUS=HERE/'corpus'
PIN='e6ab7c1a41054a888ada952eab4c886444c2f5ad'
FILES=['examples/simple/simple.cpp','src/llama-context.cpp','src/llama-model.cpp',
 'src/models/qwen2.cpp','src/llama-graph.cpp','ggml/src/ggml.c','ggml/src/ggml-backend.cpp',
 'ggml/src/ggml-vulkan/ggml-vulkan.cpp','ggml/src/ggml-vulkan/ggml-vulkan-common.h',
 'ggml/src/ggml-vulkan/ggml-vulkan-types.h',
 'ggml/src/ggml-vulkan/vulkan-shaders/vulkan-shaders-gen.cpp',
 'ggml/src/ggml-vulkan/vulkan-shaders/mul_mm.comp','ggml/src/ggml-vulkan/vulkan-shaders/mul_mm_cm2.comp',
 'ggml/src/ggml-vulkan/vulkan-shaders/mul_mat_vec.comp',
 'ggml/src/ggml-vulkan/vulkan-shaders/mul_mm_funcs.glsl','ggml/src/ggml-vulkan/vulkan-shaders/mul_mat_vec_base.glsl']
def dump(path,data): path.write_text(json.dumps(data,ensure_ascii=False,indent=2),encoding='utf-8')
args=argparse.ArgumentParser();args.add_argument('--reuse',action='store_true');args=args.parse_args()
if (SRC / '.git').exists():
    assert subprocess.check_output(['git', '-C', str(SRC), 'rev-parse', 'HEAD'], text=True).strip() == PIN
else:
    # The team repository includes the upstream working tree directly.
    assert json.loads((SRC / '.ua' / 'meta.json').read_text(encoding='utf-8-sig'))['gitCommitHash'] == PIN
OUT.mkdir(exist_ok=True)
manifest=[]; sources={}; spans={}
for f in FILES:
    raw=(SRC/f).read_bytes(); sources[f]=raw.decode('utf-8').splitlines()
    dest=CORPUS/f; dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(raw)
    manifest.append({'file':f,'sha256':hashlib.sha256(raw).hexdigest(),'lines':len(sources[f])})
    if Path(f).suffix not in ('.cpp','.c','.h'): continue
    parser=Parser(Language(tree_sitter_c.language() if f.endswith('.c') else tree_sitter_cpp.language()))
    root=parser.parse(raw).root_node; found=defaultdict(list);stack=[root]
    while stack:
        nd=stack.pop()
        if nd.type in ('function_definition','struct_specifier','class_specifier','enum_specifier','type_definition','declaration','preproc_def','preproc_function_def'):
            found[nd.start_point.row+1].append((nd.end_point.row+1,nd.type))
        stack.extend(nd.named_children)
    spans[f]=found
dump(OUT/'source-manifest.json',{'commit':PIN,'sourceRoot':str(SRC),'files':manifest})
detection=detect(CORPUS);dump(HERE/'detection.json',detection)
if detection['total_files']>200 or detection['total_words']>2000000:raise RuntimeError('Scope exceeds skill threshold')
if args.reuse: ex=json.loads((HERE/'ast.json').read_text(encoding='utf-8'))
else:
    ex=extract([Path(p) for p in detection['files']['code']],root=CORPUS)
    dump(HERE/'ast.json',ex)
ast_count=(len(ex['nodes']),len(ex['edges']))
shaderbase='ggml/src/ggml-vulkan/vulkan-shaders/'
for f in FILES:
    if f.endswith(('.comp','.glsl')):
        ex['nodes'].append({'id':'manual-file:'+f,'label':Path(f).name,'file_type':'code','source_file':f,'source_location':'L1','_origin':'manual-file-reference'})
gen=next(n['id'] for n in ex['nodes'] if n['source_file']==shaderbase+'vulkan-shaders-gen.cpp' and n['label']=='vulkan-shaders-gen.cpp')
for src,target,line,file in [(gen,'mul_mm.comp',502,'vulkan-shaders-gen.cpp'),(gen,'mul_mm_cm2.comp',502,'vulkan-shaders-gen.cpp'),(gen,'mul_mat_vec.comp',779,'vulkan-shaders-gen.cpp'),('manual-file:'+shaderbase+'mul_mm.comp','mul_mm_funcs.glsl',204,'mul_mm.comp'),('manual-file:'+shaderbase+'mul_mat_vec.comp','mul_mat_vec_base.glsl',5,'mul_mat_vec.comp')]:
    assert target in sources[shaderbase+file][line-1]
    ex['edges'].append({'source':src,'target':'manual-file:'+shaderbase+target,'relation':'references','confidence':'EXTRACTED','confidence_score':1,'source_file':shaderbase+file,'source_location':f'L{line}','weight':1,'_origin':'manual-source-reference'})
for n in ex['nodes']:
    f=n.get('source_file','').replace('\\','/');n['source_file']=f
    n['owner']='SS' if f.startswith('examples/') else 'WG' if '/ggml-vulkan/' in f or 'ggml-backend' in f else 'HR' if f else '외부 참조'
G=build_from_json(ex);communities=cluster(G);cohesion=score_all(G,communities)
labels={cid:(Path(Counter(G.nodes[n].get('source_file','') for n in members).most_common(1)[0][0]).stem or '외부 참조')+f' · {cid+1}' for cid,members in communities.items()}
gods=god_nodes(G);surprises=surprising_connections(G,communities);questions=suggest_questions(G,communities,labels)
to_json(G,communities,str(OUT/'graph.json'),force=True,built_at_commit=PIN,community_labels=labels,original_links=ex['edges'])
to_html(G,communities,str(OUT/'graphify-native.html'),community_labels=labels)
to_obsidian(G,communities,str(OUT/'obsidian'),community_labels=labels,cohesion=cohesion)
to_canvas(G,communities,str(OUT/'obsidian/graph.canvas'),community_labels=labels)
graph=json.loads((OUT/'graph.json').read_text(encoding='utf-8'))
metadata={};mapped=0;unresolved=0;bad=[]
for n in graph['nodes']:
    f=n.get('source_file','');match=re.fullmatch(r'L(\d+)(?:-L?(\d+))?',n.get('source_location') or '')
    row=int(match[1]) if match else None
    m={'id':n['id'],'label':n.get('label',n['id']),'file':f,'owner':n.get('owner','외부 참조'),'line':row,'end':row,'kind':'unresolved','origin':n.get('_origin','reference')}
    if f in sources and row and 1<=row<=len(sources[f]):
        m['kind']='source-point'
        if n.get('label')==Path(f).name:
            m['kind']='file';m['line']=1;m['end']=len(sources[f])
        else:
            candidates=spans.get(f,{}).get(row,[])
            defs=[(end,kind) for end,kind in candidates if kind in ('function_definition','struct_specifier','class_specifier','enum_specifier')]
            if defs:
                end,typ=max(defs);m['end']=end;m['kind']='definition' if typ=='function_definition' else 'type-definition'
            elif candidates:m['end']=max(candidates)[0]
        m['absolute']=str(SRC/f);m['url']=f'https://github.com/ggml-org/llama.cpp/blob/{PIN}/{f}#L{m["line"]}-L{m["end"]}'
        assert m['end']<=len(sources[f]);mapped+=1
    else:
        m['line']=None;m['end']=None;unresolved+=1
    metadata[n['id']]=m
links=[]
for e in ex['edges']:
    if e['source'] not in metadata or e['target'] not in metadata:continue
    f=e.get('source_file','');ml=re.match(r'^L(\d+)',e.get('source_location') or '')
    line=int(ml[1]) if ml else None
    if not (f in sources and line and 1<=line<=len(sources[f])):line=None
    links.append({'source':e['source'],'target':e['target'],'relation':e.get('relation','related'),'file':f,'line':line,'confidence':e.get('confidence','AMBIGUOUS')})
guide_specs=[('SS · 실행 시작','examples/simple/simple.cpp','main()'),('HR · decode 진입','src/llama-context.cpp','llama_decode()'),('HR · 그래프 생성/재사용','src/llama-context.cpp','llama_context::process_ubatch()'),('HR · Qwen2 블록','src/models/qwen2.cpp','llama_model_qwen2::graph::graph()'),('HR · 공통 행렬곱','src/llama-graph.cpp','llm_graph_context::build_lora_mm()'),('HR → WG · MUL_MAT 생성','ggml/src/ggml.c','ggml_mul_mat()'),('WG · backend 배정','ggml/src/ggml-backend.cpp','ggml_backend_sched_backend_id_from_cur()'),('WG · Vulkan 실행','ggml/src/ggml-vulkan/ggml-vulkan.cpp','ggml_backend_vk_graph_compute()'),('WG · matvec/matmul 분기','ggml/src/ggml-vulkan/ggml-vulkan.cpp','ggml_vk_mul_mat()'),('WG · pipeline 선택','ggml/src/ggml-vulkan/ggml-vulkan.cpp','ggml_vk_get_dequantize_mul_mat_vec()')]
guide=[]
for title,f,label in guide_specs:
    matches=[m for m in metadata.values() if m['file']==f and m['label']==label and m['line']]
    if len(matches)!=1:raise RuntimeError(f'Guide symbol missing/ambiguous: {label}')
    guide.append({'title':title,'id':matches[0]['id']})
data={'nodes':metadata,'sources':sources,'links':links,'guide':guide,'commit':PIN,'root':str(SRC),'mapped':mapped,'unresolved':unresolved}
dump(OUT/'source-map.json',data)
html=(OUT/'graphify-native.html').read_text(encoding='utf-8')
script=re.search(r'<script src="([^\"]+)"\s+integrity="sha384-([^\"]+)"\s+crossorigin="anonymous"></script>',html)
assert script,'Graphify vendor script not found'
vendor=(HERE/'vis-network-9.1.6.min.js').read_bytes()
assert base64.b64encode(hashlib.sha384(vendor).digest()).decode()==script[2]
html=html[:script.start()]+'<script>'+vendor.decode().replace('</script','<\\/script')+'</script>'+html[script.end():]
css=(HERE/'source-panel.css').read_text(encoding='utf-8')
js=(HERE/'source-panel.js').read_text(encoding='utf-8')
html=html.replace('<html lang="en">','<html lang="ko">').replace('</head>',f'<meta name="viewport" content="width=device-width,initial-scale=1"><style>{css}</style></head>')
payload=json.dumps(data,ensure_ascii=False).replace('</','<\\/')
html=html.replace('</body>',f'<script id="source-map-data" type="application/json">{payload}</script><script>{js}</script></body>')
html=re.sub(r'<title>.*?</title>','<title>Graphify · 노드와 실제 코드 위치</title>',html,count=1)
(OUT/'graph.html').write_text(html,encoding='utf-8')
native=(OUT/'graphify-native.html').read_text(encoding='utf-8')
native=native.replace(script[0],'<script>'+vendor.decode().replace('</script','<\\/script')+'</script>')
(OUT/'graphify-native.html').write_text(native,encoding='utf-8')
report=generate(G,communities,cohesion,labels,gods,surprises,detection,{'input':0,'output':0},str(CORPUS),suggested_questions=questions,built_at_commit=PIN)
intro=f'''# Graphify 코드 위치 연결

2026-11-11, Graphify {importlib.metadata.version('graphifyy')}를 실제 D드라이브 소스에 실행했습니다.
기준: {PIN}
범위: {len(FILES)}개 선택 파일. 다른 모델/백엔드와 생성된 빌드 파일은 제외했습니다.
자동 AST: {ast_count[0]} 노드, {ast_count[1]} 관계. Shader 파일 5개와 명시적 참조 5개는 수동 소스 확인으로 보완했습니다.

## 화면 보완

Graphify 기본 HTML은 파일 경로만 보여 줍니다. 동일한 native 네트워크에 코드 위치 패널을 추가했습니다.
Graphify의 시작 행을 추가 Tree-sitter 구문 범위와 대조하고 실제 소스의 줄 번호를 표시합니다.
함수/타입 정의, 파일 노드, 소스 지점, 정의 미확인을 구분합니다. 파일 노드를 함수 정의로 표시하지 않습니다.
코드는 추출 시점의 스냅샷입니다. 로컬 소스를 수정하면 04-rebuild-graphify.cmd를 실행하세요.

- 코드 연결: {mapped}개 노드
- 정의 위치 미확인: {unresolved}개 노드 (외부 타입/참조 포함). 가능한 호출/참조 위치만 표시합니다.
- 전역 선은 무방향 정적 관계입니다. 자동 추출 관계는 실제 GPU 런타임 경로를 증명하지 않습니다.
- C++ 매크로/함수 포인터/가상 호출은 누락될 수 있습니다. ggml-vulkan.cpp 파서 경고는 extraction.log에 보존합니다.
- GLSL/.comp 내부 함수는 자동 분석하지 않았습니다.
- 이전에 이 PC에서 실행한 Vulkan/CPU 로그는 ../logs/에 있지만 이 그래프의 추출 입력은 소스뿐입니다.
- 자동 AST/군집화의 LLM 토큰 0. 이 패널 작성에 사용한 대화 토큰은 측정되지 않았습니다.

'''
(OUT/'GRAPH_REPORT.md').write_text(intro+report,encoding='utf-8')
dump(OUT/'mapping-audit.json',{'commit':PIN,'sourceRoot':str(SRC),'files':len(FILES),'astNodes':ast_count[0],'astEdges':ast_count[1],'graphNodes':len(metadata),'edges':len(links),'mapped':mapped,'unresolved':unresolved,'communities':len(communities),'cohesion':cohesion,'guide':guide,'allSourceRangesValid':True,'runtimeCallTrace':False})
benchmark=run_benchmark(str(OUT/'graph.json'),corpus_words=detection['total_words'],questions=['llama_decode','ggml_mul_mat','ggml_vk_mul_mat','ggml_backend_sched','ggml_vk_get_dequantize_mul_mat_vec'])
dump(OUT/'benchmark.json',benchmark);print_benchmark(benchmark)
save_manifest(detection['files'],manifest_path=str(HERE/'manifest.json'),kind='ast',root=CORPUS)
costpath=OUT/'cost.json'
cost=json.loads(costpath.read_text(encoding='utf-8')) if costpath.exists() else {'runs':[],'total_input_tokens':0,'total_output_tokens':0,'scope':'AST extraction only; conversation tokens not measured'}
cost['runs'].append({'date':datetime.now(timezone.utc).isoformat(),'input_tokens':0,'output_tokens':0,'files':detection['total_files'],'reusedAst':args.reuse})
dump(costpath,cost)
print(json.dumps({'nodes':len(metadata),'mapped':mapped,'unresolved':unresolved,'guide':len(guide)},ensure_ascii=False))

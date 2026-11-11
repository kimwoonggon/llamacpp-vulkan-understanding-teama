#include "inspect.h"
#include <algorithm>
#include <charconv>
#include <ostream>
#include <set>

namespace {
// Only decimal metadata and numeric block IDs enter the SVG markup.
std::string dimension(const Inspection &m, const char *key) {
    for (const auto &kv : m.metadata) {
        if (kv.key == key && kv.type == "u32" && !kv.value.empty()
                && kv.value.find_first_not_of("0123456789") == std::string::npos)
            return kv.value;
    }
    return "?";
}

void node(std::ostream &o, int x, int y, int width, const char *id,
          const std::string &label, const std::string &caption, const char *group) {
    const int center = width / 2;
    o << "<g class='op " << group << "' data-op='" << id << "' role='button' tabindex='0'"
      << " aria-label='" << label << "' transform='translate(" << x << " " << y << ")'>"
      << "<rect width='" << width << "' height='52' rx='9'/><text x='" << center
      << "' y='22'>" << label << "</text><text class='small' x='" << center
      << "' y='41'>" << caption << "</text></g>\n";
}
}

void qwen2_map(std::ostream &o, const Inspection &m) {
    bool qwen = false;
    for (const auto &kv : m.metadata)
        if (kv.key == "general.architecture" && kv.value == "qwen2" && kv.type == "str") qwen = true;
    if (!qwen || m.tensors.empty()) return;
    std::set<unsigned> blocks;
    for (const auto &t : m.tensors) {
        if (t.name.compare(0,4,"blk.") != 0) continue;
        unsigned id = 0;
        const char *end = t.name.data() + t.name.size();
        auto p = std::from_chars(t.name.data()+4, end, id);
        if (p.ec == std::errc() && p.ptr != end && *p.ptr == '.') blocks.insert(id);
    }
    if (blocks.empty()) return;
    const auto layers = dimension(m,"qwen2.block_count");
    const auto hidden = dimension(m,"qwen2.embedding_length");
    const auto ff = dimension(m,"qwen2.feed_forward_length");
    const auto heads = dimension(m,"qwen2.attention.head_count");
    const auto kv_heads = dimension(m,"qwen2.attention.head_count_kv");
    o << R"MAP(<section id="model-map"><h2>Qwen2 연산과 가중치</h2>
<p>토큰 하나의 벡터가 바뀌는 과정을 화살표로 따라가세요. 연산을 선택하면 그 단계에서 읽는 GGUF 텐서가 아래에 표시됩니다.</p>
<label>자세히 볼 블록 <select id="map-layer">)MAP";
    for (auto id : blocks) o << "<option value='" << id << "'>blk." << id << "</option>";
    o << R"MAP(</select></label><style>
#model-map select{font:inherit;border:1px solid #81998c;padding:4px 10px;border-radius:6px}
#model-map .canvas{margin:12px 0 0;overflow:auto;border:1px solid #c6d7cc;border-radius:12px;background:#fff}
#model-map svg{display:block;width:100%;min-width:790px;height:auto}
#map-detail{padding:14px 18px;background:#fff;border-left:4px solid #28765e}
#map-detail p{margin:2px 0 8px}#map-detail a{color:#135d48}#map-detail li{margin:4px 0}
tr:target td{background:#fff1b8}</style>
<div class="canvas"><svg id="qwen-map" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1080 606" role="group" aria-labelledby="map-title map-desc">
<title id="map-title">Qwen2 토큰 처리와 블록 내부 연산</title>
<desc id="map-desc">위쪽은 임베딩에서 다음 토큰 점수까지의 경로입니다. 아래는 한 블록의 어텐션과 순방향 신경망, 두 잔차 연결입니다.</desc>
<style>
#qwen-map text{font:600 16px 'Segoe UI','Malgun Gothic',sans-serif;fill:#18382e}
#qwen-map .heading{font-size:18px}#qwen-map .note{font-size:13px;fill:#4d645a}
#qwen-map .op{cursor:pointer}#qwen-map .op text{text-anchor:middle;pointer-events:none}
#qwen-map .small{font-size:13px;font-weight:400}#qwen-map .op rect{stroke:#739688;fill:#fff}
#qwen-map .att rect{fill:#e6f4ef;stroke:#70a993}#qwen-map .ff rect{fill:#eef0fc;stroke:#9a9dc5}
#qwen-map .merge rect{fill:#fff4db;stroke:#c3a15a}
#qwen-map .op:hover rect,#qwen-map .op:focus rect,#qwen-map .active rect{stroke:#124d3d;stroke-width:3}
#qwen-map .wire{fill:none;stroke:#577569;stroke-width:1.8;marker-end:url(#tip)}
#qwen-map .skip{stroke-dasharray:6 4;stroke:#927639}
</style><defs><marker id="tip" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto"><path d="M0 0L7 3.5L0 7z" fill="#577569"/></marker></defs>
<rect width="1080" height="606" fill="#ffffff"/>
<text x="28" y="33" class="heading">모델 전체 경로</text>
<path class="wire" d="M144 84H186"/><path class="wire" d="M355 84H397"/><path class="wire" d="M609 84H651"/><path class="wire" d="M815 84H857"/>
)MAP";
    node(o,28,58,116,"input","입력 토큰","token ID","neutral");
    node(o,188,58,167,"embed","임베딩 조회",hidden + "차원 벡터","att");
    node(o,399,58,210,"block","Transformer 블록",layers + "개 순서대로","ff");
    node(o,653,58,162,"final","최종 RMSNorm","output_norm","neutral");
    node(o,859,58,193,"head","다음 토큰 점수","출력 투영 · logits","neutral");
    o << R"MAP(<rect x="12" y="136" width="1056" height="453" rx="14" fill="#f7faf8" stroke="#c7d9cf"/>
<text x="32" y="167" class="heading" id="block-title">)MAP" << "blk." << *blocks.begin() << R"MAP( 내부</text>
<text x="32" y="196" class="note">Self-attention · 이전 토큰의 정보를 읽어 현재 벡터에 합칩니다.</text>
<path class="wire" d="M51 298H93"/><path class="wire skip" d="M52 298V216H993V269"/>
<text x="796" y="210" class="note">블록 입력을 더함</text>
<path class="wire" d="M229 298H250V249H274"/><path class="wire" d="M229 298H274"/>
<path class="wire" d="M229 298H250V353H274"/>
<path class="wire" d="M421 249H449V280H484"/><path class="wire" d="M421 301H484"/>
<path class="wire" d="M421 353H449V320H484"/>
<path class="wire" d="M683 298H722"/><path class="wire" d="M893 298H944"/>
<path class="wire" d="M993 324V391H52V479H93"/>
<text x="552" y="384" class="note">어텐션 결과가 FFN의 입력이 됩니다.</text>
<text x="68" y="414" class="note">Feed-forward · 각 토큰의 특징을 확장하고 필요한 성분을 골라냅니다.</text>
<path class="wire skip" d="M52 479V554H993V508"/>
<text x="806" y="575" class="note">FFN 입력을 더함</text>
<path class="wire" d="M229 479H250V449H274"/><path class="wire" d="M229 479H250V512H274"/>
<path class="wire" d="M421 449H453V466H484"/><path class="wire" d="M421 512H453V492H484"/>
<path class="wire" d="M683 479H722"/><path class="wire" d="M893 479H944"/>
<circle cx="52" cy="298" r="4" fill="#577569"/><circle cx="52" cy="479" r="4" fill="#577569"/>
)MAP";
    node(o,95,272,134,"attn_norm","RMSNorm","attn_norm","att");
    // Compact branches keep Q, K and V separate through position encoding.
    node(o,276,221,145,"attn_q","Q · 질의","Q 투영 + RoPE","att");
    node(o,276,277,145,"attn_k","K · 키","K 투영 + RoPE","att");
    node(o,276,333,145,"attn_v","V · 값","V 투영","att");
    node(o,486,272,197,"attention","인과적 어텐션","Q " + heads + " · KV " + kv_heads + " 헤드","att");
    node(o,724,272,169,"attn_output","출력 투영","attn_output","att");
    node(o,946,272,94,"add1","＋","잔차 합","merge");
    node(o,95,453,134,"ffn_norm","RMSNorm","ffn_norm","ff");
    node(o,276,423,145,"ffn_gate","Gate + SiLU","ffn_gate","ff");
    node(o,276,486,145,"ffn_up","Up · 확장","ffn_up","ff");
    node(o,486,453,197,"multiply","원소별 곱","SwiGLU · " + ff + "차원","ff");
    node(o,724,453,169,"ffn_down","Down · 축소","ffn_down · " + hidden + "차원","ff");
    node(o,946,453,94,"add2","＋","잔차 합","merge");
    o << R"MAP(<text x="32" y="575" class="note">블록 출력 → 다음 블록의 입력 · 마지막 블록 출력 → 최종 RMSNorm</text>
</svg></div><div id="map-detail" aria-live="polite"></div></section><script>
document.addEventListener('DOMContentLoaded', () => {
    const svg = document.getElementById('qwen-map');
    const layer = document.getElementById('map-layer');
    const detail = document.getElementById('map-detail');
    const tensors = new Map();
    for (const row of document.querySelectorAll('#tensor-records tbody tr')) {
        row.id = 'tensor-' + tensors.size;
        tensors.set(row.cells[0].textContent, row);
    }
    const explanations = {
        input: '토크나이저가 입력 텍스트를 정수 ID 시퀀스로 바꿉니다.',
        embed: '토큰 ID에 해당하는 임베딩 벡터를 읽어 첫 블록에 전달합니다.',
        block: '각 블록은 자기 가중치를 사용하며, 앞 블록의 출력 벡터를 입력으로 받습니다. 위 선택기로 블록을 바꿀 수 있습니다.',
        final: '마지막 블록의 출력을 정규화한 뒤 어휘 점수 계산에 넘깁니다.',
        head: tensors.has('output.weight') ? '최종 벡터를 출력 행렬에 투영해 어휘 항목마다 다음 토큰 점수(logit)를 계산합니다.' :
            'Qwen2 로더는 별도 출력 행렬이 없으면 입력 임베딩을 출력 투영에도 사용합니다.',
        attn_norm: '블록 입력을 RMS 기준으로 정규화하고 학습된 스케일을 곱합니다. 같은 결과를 Q, K, V 세 갈래로 보냅니다.',
        attn_q: '현재 토큰이 찾을 특징을 질의 벡터로 투영합니다. bias를 더한 뒤 토큰 위치에 따라 RoPE 회전을 적용합니다.',
        attn_k: '각 토큰이 어떤 질의와 맞는지 비교할 키를 만듭니다. RoPE를 거친 키를 KV 캐시에 저장합니다.',
        attn_v: '각 토큰에서 꺼내 올 정보를 값 벡터로 투영하여 KV 캐시에 저장합니다.',
        attention: '각 Q 헤드가 대응하는 KV 헤드의 키와 내적합니다. 인과 마스크와 softmax를 적용한 비율로 현재·이전 토큰의 V를 가중합합니다.',
        attn_output: '헤드별 결과를 합쳐 모델의 은닉 차원으로 투영합니다.',
        add1: '어텐션 출력 투영 결과에 블록 입력을 더합니다. 이 합이 FFN의 입력입니다.',
        ffn_norm: '첫 잔차 합을 정규화합니다. 같은 벡터가 Gate와 Up 양쪽의 입력이 됩니다.',
        ffn_gate: 'Gate 행렬로 투영한 뒤 SiLU를 적용해 각 확장 차원의 통과량을 구합니다.',
        ffn_up: 'Up 행렬로 은닉 벡터를 FFN 차원으로 확장합니다. Gate와 병렬인 경로입니다.',
        multiply: 'SiLU(Gate(x))와 Up(x)의 대응 원소를 곱합니다. 이 곱의 결과가 Down의 입력입니다.',
        ffn_down: 'FFN 차원의 벡터를 다시 모델의 은닉 차원으로 줄여 잔차 덧셈이 가능하게 합니다.',
        add2: 'Down 출력에 FFN 입력을 더합니다. 이 결과를 다음 블록으로, 마지막 블록에서는 최종 RMSNorm으로 보냅니다.'
    };
    const operators = [...svg.querySelectorAll('[data-op]')];
    const weightSteps = new Set(['attn_norm','attn_q','attn_k','attn_v','attn_output','ffn_norm','ffn_gate','ffn_up','ffn_down']);
    function namesFor(op) {
        const prefix = 'blk.' + layer.value + '.';
        if (op === 'embed') return ['token_embd.weight'];
        if (op === 'final') return ['output_norm.weight'];
        if (op === 'head') return [tensors.has('output.weight') ? 'output.weight' : 'token_embd.weight','output.bias'];
        if (!weightSteps.has(op)) return [];
        let stem = prefix + op;
        if (['attn_q','attn_k','attn_v'].includes(op) && tensors.has(prefix + 'attn_qkv.weight')) stem = prefix + 'attn_qkv';
        return ['weight','bias','scale','input_scale'].map(suffix => stem + '.' + suffix);
    }
    let selected = 'attn_q';
    function show(op) {
        selected = op;
        for (const g of operators) {
            const active = g.dataset.op === op;
            g.classList.toggle('active',active);
            g.setAttribute('aria-pressed',String(active));
        }
        document.getElementById('block-title').textContent = 'blk.' + layer.value + ' 내부';
        const title = document.createElement('strong');
        const group = operators.find(g => g.dataset.op === op);
        title.textContent = (weightSteps.has(op) ? 'blk.' + layer.value + '  ·  ' : '') + group.getAttribute('aria-label');
        const info = document.createElement('p');
        info.textContent = explanations[op];
        detail.replaceChildren(title,info);
        const list = document.createElement('ul');
        const names = namesFor(op);
        for (const name of names) {
            const row = tensors.get(name);
            if (!row) continue;
            const li = document.createElement('li');
            const a = document.createElement('a');
            a.textContent = name;
            a.href = '#' + row.id;
            a.onclick = () => {
                const search = document.getElementById('q');
                search.value = '';
                search.dispatchEvent(new Event('input'));
            };
            li.append(a,'  ·  ' + row.cells[1].textContent + '  ·  ' + row.cells[2].textContent
                + '  ·  파일 위치 ' + BigInt(row.cells[5].textContent).toLocaleString('ko-KR') + ' B');
            list.append(li);
        }
        if (list.childElementCount) detail.append(list);
        else if (names.length) detail.append('이 GGUF에서 대응하는 텐서를 찾을 수 없습니다.');
    }
    for (const g of operators) {
        g.onclick = () => show(g.dataset.op);
        g.onkeydown = e => {
            if (e.key === 'Enter' || e.key === ' ') { e.preventDefault(); show(g.dataset.op); }
        };
    }
    layer.onchange = () => show(selected);
    show(selected);
});
</script>
)MAP";
}

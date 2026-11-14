# llama-simple의 Vulkan 로그와 CDB 호출 스택 재현하기

[학습용 HTML](simple-q-projection-vulkan-trace.html)에서 **Q 투영 하나**를 고르면 서로 다른 두 기록을 볼 수 있다. **dispatch 2번**은 Vulkan에 어떤 명령을 기록했는지를 보여 준다. **호출 스택 → Q의 명령을 기록하는 함수**는 `simple.cpp`의 어떤 호출이 그 명령을 기록하는 함수까지 왔는지를 보여 준다.

| 알고 싶은 것 | 기록한 도구와 읽을 곳 |
|---|---|
| 첫 Q 투영에 어떤 파이프라인을 골랐고 몇 그룹을 실행하도록 기록했나? | Vulkan SDK의 **API Dump**. 기존 보고용 로그 690–692행에서 연산 이름, 파이프라인, `vkCmdDispatch`를 순서대로 읽는다. |
| `llama_decode`에서 Vulkan까지 어떤 C++ 함수를 거쳤나? | Microsoft **CDB**. 같은 모델과 프롬프트로 두 번 실행해 총 20곳에서 호출 스택을 저장했다. |
| GPU가 계산한 `Q[0,0]`의 값은 어디서 왔나? | HTML의 수치는 같은 입력을 사용한 **별도 텐서 관찰 실행**에서 읽었다. API Dump가 남기는 것은 명령과 인수이고, CDB 스택은 그 시점의 CPU 쪽 함수 목록이다. |

**문서 사용법**　예전 결과만 확인하려면 [보관된 보고용 로그](logs/report-vulkan-dispatch-20261111-101620.log)를 열어 `MUL_MAT Qcur-0`를 검색한다. 직접 얻으려면 Visual Studio에서 **보기 → 터미널**을 열어 PowerShell을 선택하고 아래 1절부터 실행한다. 모든 PowerShell 블록은 같은 터미널에서 실행한다.

## 1. 모델, 실행 파일, 저장 폴더 준비

기준은 **Windows x64 · Visual Studio 2022 · Debug · Qwen2.5-1.5B-Instruct FP16 · RTX 2070 SUPER**다. 프롬프트 전체를 프로그램의 마지막 인수 하나로 전달한다. `-ngl 99`는 GPU에 올릴 레이어 수의 요청값이고, 이 실행의 로드 결과는 `offloaded 29/29 layers to GPU`였다. `-n 3`으로 세 토큰을 생성한다. Visual Studio 프로젝트의 기본 프롬프트와 `-n 48`을 그대로 사용하면 입력과 반복 횟수가 달라진다.

~~~powershell
Set-Location 'D:\llama-vulkan-lab'
$lab = (Get-Location).Path
$bin = Join-Path $lab 'build\bin\Debug'
$exe = Join-Path $bin 'llama-simple.exe'
$model = Join-Path $lab 'models\qwen2.5-1.5b-instruct-fp16.gguf'
$promptText = 'The capital of South Korea is Seoul. The capital of France is'
$runDir = Join-Path $lab ('logs\q-trace-' + (Get-Date -Format 'yyyyMMdd-HHmmss-fff'))
New-Item -ItemType Directory -Path $runDir | Out-Null
$exe, $model | ForEach-Object {
    if (-not (Test-Path -LiteralPath $_ -PathType Leaf)) { throw "Missing: $_" }
}
$runDir
~~~

실행 파일이 없으면 프로젝트 루트의 `.\01-build.cmd`를 실행해 `llama-simple`을 Debug로 빌드한 뒤 위 블록을 다시 실행한다. API 기록에는 Vulkan SDK의 `VkLayer_api_dump.json`과 같은 폴더의 DLL, 아래 수집 예제에는 Python 3가 필요하다. CDB 실습에는 Windows SDK의 **Debugging Tools for Windows**와 이번 빌드의 PDB 파일을 쓴다. [프로젝트 빌드 스크립트](scripts/build.ps1) · [Microsoft 디버거 안내](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debuggers-in-the-debugging-tools-for-windows-package)

## 2. 기존 보고용 로그를 얻은 방법으로 실행하기

기존 수집기는 `llama-simple.exe`를 자식 프로세스로 띄워 **Vulkan API Dump의 표준 출력과 프로그램의 표준 오류를 같은 스트림으로** 받았다. 이 스트림에서 정규식에 맞는 줄만 UTF-8 파일로 저장했다. 따라서 `report-vulkan-dispatch-20261111-101620.log`의 행 번호는 **필터링 후의 행 번호**다. 일반 `02-run-vulkan.cmd`는 모델 로드·추론 출력을 저장한다. 아래 수집기가 API Dump와 연산 마커를 추가로 켠다. [일반 실행 스크립트](scripts/run.ps1)

| 설정 | 이 실행에서 하는 일 |
|---|---|
| `VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_api_dump`, `VK_LAYER_PATH` | Vulkan 로더가 SDK의 API Dump 레이어를 찾아 사용하게 한다. 이 레이어가 `vkCmdDispatch`와 `vkQueueSubmit` 등의 호출을 출력한다. |
| `GGML_VK_DEBUG_MARKERS=1` | 백엔드가 `VK_EXT_debug_utils`로 GGML 연산·텐서 이름과 파이프라인·작업 그룹 크기를 명령 옆에 붙인다. |
| `VK_APIDUMP_DETAILED=true`, `VK_APIDUMP_FLUSH=false` | 구조체 내부의 `pLabelName`까지 출력하고 매 API 호출마다 출력을 강제로 비우는 동작을 끈다. |
| `GGML_VK_VISIBLE_DEVICES=0`, `GGML_VK_PERF_LOGGER=1` | 실습의 0번 Vulkan 장치를 선택하고 백엔드의 연산 시간 요약도 출력한다. |

아래 블록은 기존 캡처의 실행 인수·환경 설정·필터를 사용한다. SDK 위치는 이 PC의 기본값을 넣었다. 다른 설치 경로를 쓰면 `$sdkBin`을 해당 `Bin` 폴더로 바꾼다. 실행이 끝나면 새 폴더의 `vulkan-dispatch.log`에 결과가 남는다. [LunarG API Dump 설정](https://vulkan.lunarg.com/doc/view/1.4.304.0/windows/api_dump_layer.html)

~~~powershell
$sdkBin = if ($env:VULKAN_SDK) { Join-Path $env:VULKAN_SDK 'Bin' } else { 'D:\VulkanSDK\1.4.363.0\Bin' }
foreach ($name in 'VkLayer_api_dump.json','VkLayer_api_dump.dll') {
    if (-not (Test-Path (Join-Path $sdkBin $name))) { throw "Missing Vulkan SDK layer: $sdkBin\$name" }
}
$apiLog = Join-Path $runDir 'vulkan-dispatch.log'
@'
import os, re, subprocess, sys

exe, model, prompt, sdk, log = sys.argv[1:]
args = [exe, "-m", model, "-ngl", "99", "-n", "3", prompt]
env = dict(os.environ, GGML_VK_VISIBLE_DEVICES="0", GGML_VK_DEBUG_MARKERS="1",
           GGML_VK_PERF_LOGGER="1", VK_INSTANCE_LAYERS="VK_LAYER_LUNARG_api_dump",
           VK_LAYER_PATH=sdk, VK_APIDUMP_DETAILED="true", VK_APIDUMP_FLUSH="false")
keep = re.compile(r"pLabelName|vkCmdDispatch\(|vkQueueSubmit\(|offloaded |model buffer size|"
                  r"MUL_MAT.* m=|prompt eval time|main: decoded|0 = NVIDIA|"
                  r"The capital of South Korea|api_dump.*(failed|error)", re.I)
with open(log, "w", encoding="utf-8") as out:
    print("Command:", subprocess.list2cmdline(args), file=out)
    print("Filtered Vulkan API dump and llama-simple output", file=out)
    with subprocess.Popen(args, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                          text=True, encoding="utf-8", errors="replace") as proc:
        for line in proc.stdout:
            if keep.search(line):
                out.write(line)
        status = proc.wait()
    print("Exit code", status, file=out)
print(log)
sys.exit(status)
'@ | python - $exe $model $promptText $sdkBin $apiLog
if ($LASTEXITCODE -ne 0) { throw "Vulkan capture failed. See $apiLog" }
~~~

### `Qcur-0`이라는 이름은 어디서 나오나?

1. `ggml_vk_debug_label`이 그래프 노드의 연산 이름 `MUL_MAT`와 텐서 이름 `Qcur-0`을 이어 붙인다. 이 문자열이 첫 번째 `pLabelName`이 된다. [연산 이름을 만드는 코드](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan.cpp#L16213)
2. `ggml_vk_dispatch_pipeline`이 실제로 고른 `pipeline->name`과 `wg0, wg1, wg2`를 두 번째 마커에 넣는다. 바로 다음 줄의 `dispatch(wg0, wg1, wg2)`가 Vulkan API 호출로 기록된다. 그래서 로그에서 **텐서 → 셰이더 파이프라인 → 작업 그룹**을 연결할 수 있다. [파이프라인 마커와 dispatch](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan-common.h#L278)

### 첫 블록의 Q 투영을 찾고 563개를 직접 세기

기존 파일에서는 다음 세 줄이 한 묶음이다. `(48,1,1)`은 X·Y·Z 방향의 **작업 그룹 개수**다. `vkCmdDispatch`는 명령 버퍼에 GPU 작업을 기록한다. 이후 `vkQueueSubmit`에서 명령 버퍼를 큐에 제출한다. 한 제출에 여러 dispatch가 들어갈 수 있다. [보고용 로그 690행](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/logs/report-vulkan-dispatch-20261111-101620.log#L690) · [마커와 dispatch를 나란히 기록하는 C++ 코드](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan-common.h#L278)

~~~text
690  pLabelName = "MUL_MAT Qcur-0"
691  pLabelName = "matmul_f16_f32_f16acc_aligned_0 (48,1,1)"
692  vkCmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ)
~~~

새 로그에서는 **연산 이름**으로 찾는다. 아래 명령은 첫 그래프 실행 마커에서 시작해 첫 `MUL_MAT result_output`의 dispatch까지 센다. 이 범위가 첫 **13토큰** 프롬프트 처리다. 파일 끝까지 세면 이어지는 **1토큰** 생성 호출까지 포함한다.

~~~powershell
$lines = @(Get-Content -LiteralPath $apiLog -Encoding UTF8)
$start = $lines | Select-String -SimpleMatch '"ggml_backend_vk_graph_compute"' | Select-Object -First 1
if (-not $start) { throw 'Graph marker missing. Check API Dump and GGML_VK_DEBUG_MARKERS.' }
$graph = @($lines | Select-Object -Skip ($start.LineNumber - 1))
$q = $graph | Select-String -SimpleMatch '"MUL_MAT Qcur-0"' | Select-Object -First 1
$last = $graph | Select-String -SimpleMatch '"MUL_MAT result_output"' | Select-Object -First 1
if (-not $q -or -not $last) { throw 'Q or result_output marker missing.' }
$graph | Select-Object -Skip ($q.LineNumber - 1) -First 3
$afterOutput = @($graph | Select-Object -Skip $last.LineNumber)
$finalDispatch = $afterOutput | Select-String '^vkCmdDispatch\(' | Select-Object -First 1
if (-not $finalDispatch) { throw 'Final dispatch missing.' }
$firstDecode = $graph | Select-Object -First ($last.LineNumber + $finalDispatch.LineNumber)
'First decode dispatches = ' + @($firstDecode | Select-String '^vkCmdDispatch\(').Count
$lines | Select-String 'offloaded |prompt eval time|Exit code'
~~~

기준 캡처의 결과는 **563개**, Q 투영은 **2번째**, 마지막은 **`result_output`**이다. GPU·모델 자료형·토큰 수·백엔드 버전이 바뀌면 파이프라인 선택과 dispatch 개수도 바뀔 수 있다. 측정한 시간에는 API 기록 비용도 들어간다.

## 3. CDB로 C++ 호출 스택 얻기

**CDB는 Microsoft Console Debugger**다. Visual Studio에서 `F9`로 중단점을 걸고 `F5`로 실행한 뒤 **호출 스택** 창을 여는 작업을 터미널 명령으로 할 수 있다. PDB는 실행 중인 주소를 `ggml_vk_matmul` 같은 함수 이름과 소스 행으로 바꾸는 데 쓰인다. CDB는 CPU에서 실행 중인 Vulkan 백엔드 함수까지 보여 준다. GLSL 연산은 GPU에서 실행되므로 학습용 HTML에서 같은 dispatch의 셰이더 소스와 대응시켰다. [Microsoft CDB 설명](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/debuggers-in-the-debugging-tools-for-windows-package)

| CDB 입력 | Visual Studio와 연결해 읽기 |
|---|---|
| `bu llama!llama_decode` | `llama` 모듈의 `llama_decode` 함수에 중단점을 건다. `모듈!심볼` 형태이고 DLL이 나중에 로드되어도 해석할 수 있다. |
| `g` / `bc *` | 다음 중단점까지 실행 / 현재 중단점 전부 지우기. 아래에서는 현재 지점을 지나간 뒤 다음 목표에 새로 건다. |
| `kn 35` | 현재 스레드의 호출 스택에 프레임 번호를 붙여 출력한다. CDB의 기본 수 표기는 16진수다. `00`이 현재 멈춘 함수이고 아래로 갈수록 호출자다. HTML은 `main`에서 시작하도록 순서를 뒤집었다. |
| `dt ggml_base!ggml_tensor @rdx name` | 해당 중단점에서 레지스터가 가리키는 텐서의 `name` 필드를 출력한다. 인수 위치는 함수마다 다르다. |
| `.echo @@QDISPATCH` | 저장 파일에서 다시 찾을 수 있도록 해당 스택 바로 앞에 이름표를 출력한다. |

**왜 먼저 `llama_decode`에서 멈추나?** 컨텍스트를 준비할 때도 그래프 빌더가 실행된다. 실제 프롬프트 호출 안에서 첫 번째 블록의 Q를 잡으려면 `llama_decode`에 도착한 뒤 `ggml_mul_mat` 조건부 중단점을 건다. 이 실습은 `blk.0.attn_q.weight`와 `attn_norm-0`을 인수에서 확인하고, 이후 Vulkan 행렬곱 및 dispatch 함수에서 다시 멈췄다.

### 처음 써 본다면 한 곳만 멈춰 보기

전체 캡처 전에 손으로 시험하려면 1절의 PowerShell에서 아래 한 줄을 실행한다. `-logo`가 현재 세션을 `one-stack.log`에 저장하고 `-G`는 대상 프로그램이 정상 종료되면 디버거도 끝나게 한다. [CDB 로그 저장 옵션](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/keeping-a-log-file-in-cdb)

~~~powershell
& 'C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe' -G -lines -y $bin -logo (Join-Path $runDir 'one-stack.log') $exe -m $model -ngl 99 -n 3 $promptText
~~~

`0:000>` 같은 **CDB 프롬프트**가 나타나면 다음을 한 줄씩 입력한다. 첫 `g`에서 모델 로드를 마치고 `llama_decode`에 멈춘다. `kn` 결과의 첫 줄은 `llama!llama_decode`, 그 아래 호출자는 `llama_simple!main`이며 디버그 심볼에 `simple.cpp @ 173`이 보인다. `bc *`와 마지막 `g`는 중단점을 지우고 남은 추론을 끝까지 실행한다.

~~~text
bu llama!llama_decode
g
kn
bc *
g
~~~

### 20개 스택을 다시 캡처하기

아래 접힌 부분은 두 번의 실제 캡처에 쓴 **CDB 명령 파일 전문**이다. 펼쳐서 코드 블록을 한 번 실행하면 `steps.txt`와 `detail.txt`가 새 기록 폴더에 생긴다. 이름 비교에 쓰인 `@rdx+100` 등의 오프셋은 **이번 x64 빌드와 PDB 기준의 16진수**다. 소스를 바꾸고 다시 빌드했다면 CDB에서 `dt ggml_base!ggml_tensor name`으로 필드 위치를 대조한다.

<details>
<summary>PowerShell로 두 명령 파일 만들기</summary>

~~~powershell
@'
bu llama!llama_decode
g
.echo @@DECODE
kn 30
bc *
bu ggml_base!ggml_mul_mat ".if (poi(@rdx+106)==0x772e715f6e747461 && wo(@rdx+104)==0x2e30) {} .else {gc}"
g
.echo @@QBUILD
dt ggml_base!ggml_tensor @rdx name
dt ggml_base!ggml_tensor @r8 name
kn 35
bc *
bu ggml_base!ggml_new_tensor_impl
g
.echo @@QALLOC
kn 35
bc *
bu ggml_base!ggml_backend_cpu_buffer_set_tensor ".if (poi(@rdx+100)==0x656b6f745f706e69) {} .else {gc}"
g
.echo @@TOKENS
kn 32
bc *
bu ggml_vulkan!ggml_backend_vk_cpy_tensor_async ".if (dwo(@r8+100)==0x64626d65) {} .else {gc}"
g
.echo @@EMBD
dt ggml_base!ggml_tensor @r8 name
dt ggml_base!ggml_tensor @r9 name
kn 32
bc *
bu ggml_vulkan!ggml_vk_mul_mat_q_f16 ".if (poi(@r8+106)==0x772e715f6e747461 && wo(@r8+104)==0x2e30) {} .else {gc}"
g
.echo @@QVK
kn 35
bc *
bu ggml_vulkan!ggml_vk_matmul
g
.echo @@QMAT
kn 35
bc *
bm ggml_vulkan!*dispatch_pipeline*mat_mat_push_constants*
g
.echo @@QDISPATCH
kn 35
bc *
bu ggml_vulkan!ggml_vk_submit
g
.echo @@SUBMIT
kn 35
bc *
bu ggml_vulkan!ggml_backend_vk_get_tensor_async ".if (poi(@rdx+100)==0x6f5f746c75736572) {} .else {gc}"
g
.echo @@READBACK
dt ggml_base!ggml_tensor @rdx name
kn 35
bc *
bu llama!llama_get_logits_ith
g
.echo @@RAWLOGITS
kn 35
bc *
bu llama!llama_sampler_greedy_apply
g
.echo @@GREEDY
kn 35
bc *
bu llama!llama_token_to_piece
g
.echo @@PIECE
kn 35
bc *
g
q
'@ | Set-Content -LiteralPath (Join-Path $runDir 'steps.txt') -Encoding ascii

@'
bu llama!llama_decode
g
bc *
bu ggml_base!ggml_mul_mat ".if (poi(@rdx+106)==0x772e715f6e747461 && wo(@rdx+104)==0x2e30) {} .else {gc}"
g
bc *
bu ggml_base!ggml_new_object
g
.echo @@QOBJECT
kn 35
bc *
bu ggml_cpu!ggml_compute_forward_get_rows_f16
g
.echo @@GETROWS
kn 35
bc *
bu ggml_vulkan!ggml_backend_vk_cpy_tensor_async ".if (dwo(@r8+100)==0x64626d65) {} .else {gc}"
g
bc *
bu ggml_vulkan!ggml_vk_buffer_write_2d
g
.echo @@EMBDWRITE
kn 35
bc *
bu ggml_vulkan!ggml_vk_mul_mat_q_f16 ".if (poi(@r8+106)==0x772e715f6e747461 && wo(@r8+104)==0x2e30) {} .else {gc}"
g
bc *
bu ggml_vulkan!ggml_vk_compute_forward
g
bc *
bu ggml_vulkan!ggml_vk_submit
g
.echo @@BATCHSUBMIT
kn 35
bc *
bu ggml_vulkan!ggml_backend_vk_get_tensor_2d_async ".if (poi(@rdx+100)==0x6f5f746c75736572) {} .else {gc}"
g
bc *
bu ggml_vulkan!ggml_vk_buffer_read_2d_async
g
.echo @@LOGITREAD
kn 35
bc *
bu llama!llama_sampler_sample
g
bc *
bu llama!llama_context::synchronize
g
.echo @@SAMPLEWAIT
kn 35
bc *
bu llama!llama_token_to_piece
g
bc *
bm llama!*llama_vocab*token_to_piece*
g
.echo @@PIECEBODY
kn 35
bc *
g
q
'@ | Set-Content -LiteralPath (Join-Path $runDir 'detail.txt') -Encoding ascii
~~~

</details>

두 패스를 **차례로** 실행한다. `-y`는 우리 Debug DLL과 PDB가 있는 위치, `-lines`는 소스 행 표시, `-cf`는 시작할 때 읽을 명령 파일이다. 기존 캡처처럼 `*>`로 세션 출력을 파일에 보낸다. 실행 중에는 콘솔이 잠시 조용할 수 있다. [CDB 명령줄 옵션](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/cdb-command-line-options) · [중단점과 호출 스택 명령](https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/commands)

~~~powershell
$cdb = Join-Path ([Environment]::GetFolderPath('ProgramFilesX86')) 'Windows Kits\10\Debuggers\x64\cdb.exe'
if (-not (Test-Path -LiteralPath $cdb)) { throw "Install Debugging Tools for Windows (x64): $cdb" }
foreach ($name in 'llama-simple','llama','ggml-base','ggml-cpu','ggml-vulkan') {
    if (-not (Test-Path (Join-Path $bin "$name.pdb"))) { throw "Missing Debug PDB: $name" }
}
foreach ($pass in 'steps','detail') {
    $commandFile = Join-Path $runDir "$pass.txt"
    $logName = if ($pass -eq 'steps') { 'debug.log' } else { 'detail.log' }
    $log = Join-Path $runDir $logName
    & $cdb -y $bin -lines -cf $commandFile $exe -m $model -ngl 99 -n 3 $promptText *> $log
    if ($LASTEXITCODE -ne 0) { throw "CDB failed. See $log" }
    $markers = @(Select-String -LiteralPath $log -Pattern '^@@[A-Z]+$')
    "$logName : $($markers.Count) snapshots"
}
~~~

첫 패스 `debug.log`는 **13곳**, 둘째 패스 `detail.log`는 **7곳**이다. 두 기록은 같은 프롬프트를 처음부터 각각 실행해 얻었다. 별도 프로세스이므로 스택 주소는 실행마다 달라져도 된다.

~~~powershell
Select-String -LiteralPath (Join-Path $runDir 'debug.log') -Pattern '^@@QBUILD$' -Context 0,12
Select-String -LiteralPath (Join-Path $runDir 'debug.log') -Pattern '^@@QDISPATCH$' -Context 0,17
Select-String -LiteralPath (Join-Path $runDir 'detail.log') -Pattern '^@@LOGITREAD$' -Context 0,12
~~~

`@@QDISPATCH` 다음 스택에서 **맨 위**의 `ggml_vk_dispatch_pipeline<vk_mat_mat_push_constants>`가 중단된 함수다. 그 아래 `ggml_vk_matmul`, `ggml_vk_mul_mat_q_f16`, 더 아래 `llama_decode`와 `simple.cpp:173`의 `main`이 보인다. 위에서 아래로 읽으면 “누가 나를 불렀나”, `main`에서 위로 읽으면 “내 코드가 어떤 함수로 들어갔나”가 된다. HTML은 애플리케이션 진입부터 중단점까지의 프레임을 표시한다.

## 4. Visual Studio에서 같은 Q를 직접 멈춰 보기

1. `build\llama-vulkan-lab.sln`을 열고 `Debug | x64`에서 `llama-simple`을 시작 프로젝트로 지정한다.
2. `llama-simple` 프로젝트 속성 → **디버깅 → 명령 인수**에 아래 한 줄을 넣는다. `simple.cpp:173`의 `llama_decode(ctx, batch)`에 `F9`를 누르고 `F5`로 실행한다.

   ~~~text
   -m "D:\llama-vulkan-lab\models\qwen2.5-1.5b-instruct-fp16.gguf" -ngl 99 -n 3 "The capital of South Korea is Seoul. The capital of France is"
   ~~~

3. 첫 decode에서 `batch.n_tokens == 13`을 확인한다. 이제 `llama-graph.cpp:1689`의 `Qcur = build_lora_mm(layer.wq, cur, layer.wq_s);`에 중단점(조건 `il == 0`)을 켜고 `F5`를 누른다. 조사식에서 `layer.wq->name`과 `cur->name`을 확인한다. 첫 블록의 Q 가중치와 정규화된 입력이다.
4. `ggml-vulkan.cpp`의 `ggml_vk_mul_mat_q_f16` 함수에 중단점을 켠다. 첫 Q 호출에서 가중치 텐서의 이름이 `blk.0.attn_q.weight`인지 확인한다. 이어서 `ggml-vulkan-common.h:279`의 `dispatch(wg0, wg1, wg2)`에서 멈추면 `wg0`, `wg1`, `wg2`를 본다. **디버그 → 창 → 호출 스택**에서 3절의 `@@QDISPATCH`와 호출자를 대조한다. [Q 노드 생성 코드](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/llama.cpp/src/llama-graph.cpp#L1689) · [Vulkan dispatch 코드](https://github.com/kimwoonggon/llamacpp-vulkan-understanding-teama/blob/235aca63994977f8a427b3c8a02d2edea51cc05f/llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan-common.h#L279)

**결과가 다를 때**　`vkCmdDispatch`는 보이는데 `Qcur-0`이 없으면 2절의 `GGML_VK_DEBUG_MARKERS`와 `VK_APIDUMP_DETAILED`를 확인한다. API 호출 자체가 없으면 SDK `Bin`의 레이어 파일과 Vulkan 장치 선택을 확인한다. CDB가 함수 이름을 찾지 못하면 `lm m ggml*`로 모듈을, `x ggml_vulkan!*ggml_vk_matmul*`로 심볼을 확인하고 실행 파일과 PDB가 같은 Debug 빌드인지 본다.

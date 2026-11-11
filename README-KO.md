# llama.cpp Vulkan 실습

이 폴더의 소스 기준은 `e6ab7c1a41054a888ada952eab4c886444c2f5ad`입니다.
원본 llama.cpp는 `llama.cpp/`에 있고 실행용 설정은 그 바깥에 있습니다.

## 바로 실행

1. `00-open-visual-studio.cmd`를 실행합니다.
2. Visual Studio 상단에서 **Debug / x64**를 선택합니다.
3. **llama-simple**이 시작 프로젝트인지 확인하고 **F5**를 누릅니다.
4. 콘솔에 모델 로드 정보와 생성된 텍스트가 나타납니다.

모델 경로, `-ngl 99`, 짧은 프롬프트는 이미 설정되어 있습니다.
모델은 Qwen 공식 `qwen2.5-1.5b-instruct-fp16.gguf`입니다.
이 파일의 출처, 고정 revision, SHA-256은 `models/model-source.json`에 있습니다.
공식 배포: https://huggingface.co/Qwen/Qwen2.5-1.5B-Instruct-GGUF

## 이 PC에서 확인한 결과

2026-11-10, Visual Studio 2022 Debug/x64 빌드 및 Vulkan/CPU 실행 모두 정상 종료를 확인했습니다.
Vulkan 실행에서는 NVIDIA GeForce RTX 2070 SUPER를 인식하고 29/29 레이어를 GPU에 offload했습니다.
GPU 모델 버퍼는 2944.68 MiB였고 `The capital of South Korea is Seoul...` 텍스트를 생성했습니다.
실제 로그는 `logs/run-Vulkan-Debug-20261110-234525.log`에 있습니다.
CPU 실행은 `-ngl 0`으로 별도로 확인했습니다. Debug 실행이므로 성능 벤치마크 결과로 사용하지 마세요.

Visual Studio 없이 실행하려면 `02-run-vulkan.cmd`를, CPU로 비교하려면 `02-run-cpu.cmd`를 실행합니다.
빌드가 필요할 때는 `01-build.cmd`를 실행합니다. 실행 로그는 `logs/`에 저장됩니다.

## 디버깅할 위치

Visual Studio에서 파일을 열어 해당 줄의 왼쪽 여백을 누르거나 F9로 중단점을 설정합니다.
F5는 다음 중단점, F10은 다음 줄, F11은 함수 내부로 이동합니다.

| 담당 | 파일과 줄 | 확인할 값 |
|---|---|---|
| SS | `llama.cpp/examples/simple/simple.cpp:88` | model_params.n_gpu_layers |
| SS → HR | `llama.cpp/examples/simple/simple.cpp:173` | ctx, batch |
| HR | `llama.cpp/src/llama-context.cpp:1399` | gparams와 그래프 재사용 조건 |
| HR | `llama.cpp/src/models/qwen2.cpp:119` | 첫 층의 FFN up 입력 |
| HR → WG | `llama.cpp/ggml/src/ggml.c:3341` | a, b, result의 type/ne/nb |
| WG | `llama.cpp/ggml/src/ggml-backend.cpp:951` | 가중치 buffer와 backend 배정 |
| WG | `llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan.cpp:6980` | src0, src1, dst와 행렬곱 분기 |
| WG | `llama.cpp/ggml/src/ggml-vulkan/ggml-vulkan.cpp:5352` | matvec pipeline 후보 |

반복 호출이 많으므로 FFN up은 `il == 0` 조건을 걸면 첫 층에 집중할 수 있습니다.
`ggml_mul_mat`는 GPU 계산이 아니라 연산 노드 생성입니다. 실제 GPU 실행은 backend와 dispatch 이후에 일어납니다.
일반 matvec 조건은 N=1만이 아니라 일부 N≤8도 포함합니다. 실제 분기는 메모리 배치와 dtype을 함께 봅니다.

## Understand-Anything 지도

`03-visual-map.cmd`를 실행하면 실제 Understand-Anything 대시보드가 열립니다.
프로젝트는 이 폴더의 `llama.cpp`이며, 지도의 파일 경로도 해당 소스에 연결됩니다.
SS / HR / WG의 담당 영역과 학습 순서를 확인하세요.
지도는 이번 과업에 필요한 범위만 정리한 정적 분석입니다. GPU의 실시간 호출 추적 화면은 아닙니다.

## 구성 및 주의점

### Graphify에서 실제 코드로 이동

`04-graphify-map.cmd`를 실행하면 **Graphify 노드 + 코드 위치** 지도가 열립니다.
인터넷이나 별도 서버 없이 HTML 파일 하나로 작동합니다.

1. 상단 **핵심 경로**에서 SS → HR → WG의 10개 진입점을 고릅니다.
2. 노드를 누르면 오른쪽에 **정의 파일, 시작/끝 줄, 원본 코드**가 나타납니다.
3. **이 노드로 들어오는 호출·참조 → 이 관계의 코드 보기**를 누르면 호출하는 쪽의 줄을 확인합니다.
4. Visual Studio에서는 **파일 경로 복사 → Ctrl+O → 붙여넣기 → Ctrl+G → 줄 번호**로 같은 곳을 엽니다.
5. 주변 노드에서는 선택 노드의 직접 연결을, 전체 지도에서는 자동 군집 전체를 봅니다. 함수명과 파일명으로 검색할 수 있습니다.

예: `ggml_vk_mul_mat()`의 정의는 `ggml/src/ggml-vulkan/ggml-vulkan.cpp:6980–7052`이고,
`ggml_vk_build_graph()`에서 호출하는 근거는 같은 파일의 **12392행**입니다.
정의 위치와 호출 위치를 구분해서 보세요.

2026-11-11 기준 16개 파일에서 2,503개 노드를 구성했으며 2,177개에 소스 위치가 있습니다.
326개 외부 참조 등은 **정의 위치 미확인**으로 표시합니다. 전체 저장소의 완전한 호출 그래프는 아닙니다.
실제 Graphify 0.9.105의 HTML에 코드 패널을 추가한 화면입니다.
원래 화면은 `graphify-out/graphify-native.html`, 분석 기록은 `graphify-out/GRAPH_REPORT.md`에 있습니다.

코드는 생성 시점의 스냅샷입니다. 소스를 수정했다면 `04-rebuild-graphify.cmd`를 실행하세요.
현재 분석기는 이 실습의 고정 commit을 확인하며, 다른 commit으로 바꾼 경우 분석 범위/줄 근거도 함께 갱신해야 합니다.
Vulkan C++ 매크로 부분에 파서 경고가 있어 일부 관계가 빠질 수 있습니다. GLSL 5개는 파일과 명시적 참조만 연결했습니다.

### 실행 환경

- Visual Studio 2022 C++ 도구, Vulkan SDK `D:\VulkanSDK\1.4.363.0` 사용
- Debug 빌드는 코드 따라가기용입니다. 성능 비교는 별도의 Release 빌드에서 수행합니다.
- simple 예제는 대화형 채팅 프로그램이 아니라 프롬프트의 다음 토큰을 생성하는 예제입니다.
- 이 예제의 옵션은 `-m`, `-ngl`, `-n`이며 `--device`는 제공하지 않습니다.
- CPU 비교도 Vulkan backend 초기화 로그를 출력할 수 있습니다. 실제 offload 레이어와 버퍼 위치를 확인하세요.
- Debug에서는 매우 상세한 로그가 나옵니다. 초기 DLL 검색의 `failed to find ggml_backend_init` 메시지가 있어도, 연결된 backend 등록 뒤 정상 추론하는 것을 확인했습니다. 이 메시지만으로 GPU 실행 실패로 판단하지 마세요.

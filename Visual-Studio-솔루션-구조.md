# Visual Studio 2022에서 llama-vulkan-lab 솔루션 읽기

캡처에서 선택한 **`llama-simple → Source Files → simple.cpp`가 실행의 출발점**이다. 이 프로젝트가 직접 컴파일하는 C++ 소스는 한 개다. 모델을 읽는 구현은 옆의 `llama` 프로젝트에, GPU에서 계산하는 구현은 `ggml-vulkan` 프로젝트에 있다. 세 프로젝트의 파일을 따로 찾아 열어도 F5로 실행하는 프로그램은 같은 `llama-simple.exe`다.

## 1. 지금 보고 있는 화면

```text
솔루션 'llama-vulkan-lab' (15 프로젝트)    ← 함께 열고 빌드하는 프로젝트 목록
├─ llama-simple                         ← 굵게 표시된 시작 프로젝트. F5의 대상
│  ├─ 참조                              ← 이 프로젝트에 연결된 다른 빌드 대상
│  │  ├─ ggml, ggml-base                ← 백엔드 등록, 텐서·그래프·스케줄러
│  │  ├─ ggml-cpu, ggml-vulkan          ← CPU와 Vulkan용 계산 구현
│  │  ├─ llama                          ← 모델 로드와 토큰 추론 API
│  │  └─ ZERO_CHECK                     ← CMake 설정 변경을 확인하는 빌드 단계
│  ├─ 외부 종속성                        ← VS가 찾아낸 포함 헤더를 모아 보여주는 곳
│  ├─ Source Files                      ← 프로젝트 안의 표시용 그룹(필터)
│  │  └─ simple.cpp                     ← 디스크의 llama.cpp/examples/simple/simple.cpp
│  └─ CMakeLists.txt                    ← 이 예제의 빌드 규칙
├─ llama                                ← 펼치면 모델 구현을 탐색할 수 있음
├─ ggml-base                            ← 펼치면 ggml.c와 ggml-backend.cpp가 있음
├─ ggml-vulkan                          ← 펼치면 ggml-vulkan.cpp가 있음
└─ study-map                            ← 여러 프로젝트의 주요 원본을 함께 열어 보는 곳
```

**같은 이름이 두 번 보이는 이유.** 맨 위 수준의 `ggml-vulkan`은 독립된 프로젝트다. `llama-simple → 참조 → ggml-vulkan`은 앞의 프로젝트를 가리키는 항목이다. CMake에서 예제는 `llama`에 링크하고, 생성된 Visual Studio 프로젝트에는 그 아래 필요한 GGML 프로젝트 참조도 나타난다. 참조 목록의 표시 순서는 빌드 관계를 살펴보는 데 쓰며, 프로그램의 실행 순서는 함수 호출을 따라 확인한다.

**선택한 파일이 진짜 어디에 있는지 확인하려면** `simple.cpp`를 클릭하고 **F4 → 속성 창 → 전체 경로(Full Path)** 를 본다. 파일명 위에서 우클릭해 **포함하는 폴더 열기**를 선택해도 된다.

## 2. 디스크에서는 어디에 있나

기준 폴더는 `D:\llama-vulkan-lab`이다. 아래는 캡처와 팀 실습에 연결되는 파일이다. 깊은 폴더 이름은 한 줄로 묶었다.

```text
D:\llama-vulkan-lab\
├─ 00-open-visual-studio.cmd              Visual Studio 솔루션 열기
├─ 01-build.cmd                          CMake 설정 및 Debug 빌드
├─ 02-run-cpu.cmd / 02-run-vulkan.cmd     같은 예제를 CPU 또는 Vulkan 설정으로 실행
├─ CMakeLists.txt                        실습 전체 설정. Vulkan 활성화, 시작 프로젝트, F5 인수
├─ llama.cpp\                            원본 소스 폴더 (.cpp로 끝나는 폴더 이름)
│  ├─ examples\simple\
│  │  ├─ CMakeLists.txt                  simple.cpp로 llama-simple을 만들고 llama에 링크
│  │  └─ simple.cpp                      main, 모델 로드 요청, decode 루프, 콘솔 출력
│  ├─ include\llama.h                    예제가 호출하는 llama 공개 API 선언
│  ├─ src\
│  │  ├─ llama.cpp                       모델 로드 API 구현 (이쪽 llama.cpp는 파일)
│  │  ├─ llama-model-loader.cpp          GGUF 메타데이터와 가중치 읽기
│  │  ├─ llama-context.cpp               decode 실행, 그래프 생성·재사용, 결과 읽기
│  │  ├─ models\qwen2.cpp                Qwen2 계열 모델의 층과 연산 연결
│  │  └─ llama-graph.cpp                 FFN 등 여러 모델이 공유하는 그래프 조립
│  └─ ggml\
│     ├─ include\ggml.h                  텐서와 연산 API 선언
│     └─ src\
│        ├─ ggml.c                      ggml_mul_mat 등 연산 노드 생성
│        ├─ ggml-backend.cpp             스케줄러가 그래프 구간을 백엔드에 배정·전달
│        ├─ ggml-cpu\                   CPU에서 계산하는 구현
│        └─ ggml-vulkan\
│           ├─ ggml-vulkan.cpp           Vulkan 장치와 연산 구현 선택
│           ├─ ggml-vulkan-common.h      파이프라인 바인딩과 dispatch 기록
│           └─ vulkan-shaders\           GPU에서 실행할 셰이더 원본
│              ├─ mul_mm.comp            여러 입력 열을 처리하는 일반 행렬곱 계열
│              └─ mul_mat_vec.comp       행렬–벡터 곱 계열
├─ models\qwen2.5-1.5b-instruct-fp16.gguf  F5가 읽는 실제 모델 데이터
├─ build\                                CMake가 생성한 VS 파일과 빌드 결과
│  ├─ llama-vulkan-lab.sln               지금 열어 둔 15개 프로젝트의 솔루션
│  ├─ study-simple\
│  │  ├─ llama-simple.vcxproj            실제 소스 경로, 프로젝트 참조, 디버거 설정
│  │  └─ llama-simple.vcxproj.filters    simple.cpp를 'Source Files' 아래에 표시하는 규칙
│  ├─ llama.cpp\                        llama·GGML 등의 생성된 프로젝트 파일
│  ├─ bin\Debug\                        llama-simple.exe, llama.dll, ggml 계열 DLL, PDB
│  └─ matmul-demo\matmul_demo.sln        행렬곱 하나만 실험하는 별도 솔루션
├─ matmul-demo\main.cpp                  독립 행렬곱 예제 소스
├─ .vscode\launch.json                   VS Code의 CPU/Vulkan 실행 설정
├─ scripts\                              빌드·실행 명령 파일이 부르는 PowerShell 스크립트
├─ logs\                                 모델 로드·실행·Vulkan dispatch 기록
└─ graphify-out\                         브라우저에서 열어 보는 코드 관계 지도
```

**두 개의 CMakeLists.txt를 구분하는 법.** 캡처의 `llama-simple` 바로 밑에 있는 파일을 열면 `add_executable(${TARGET} simple.cpp)`가 나온다. 반면 실습 폴더 맨 위의 파일에는 `VS_STARTUP_PROJECT llama-simple`과 `VS_DEBUGGER_COMMAND_ARGUMENTS`가 있다. **“어떤 소스를 컴파일하지?”**는 첫 파일, **“왜 F5만 눌러도 Qwen과 Vulkan이 선택되지?”**는 두 번째 파일에서 답을 찾는다. 빌드 구성을 계속 유지하려면 원본 CMake 설정을 편집한다. `build` 아래 프로젝트 파일은 CMake가 다시 생성할 수 있다.

## 3. 솔루션에 보이는 프로젝트 15개

| 솔루션 탐색기 이름 | 맡은 일 | 언제 펼칠까 |
|---|---|---|
| **llama-simple** | 실습 실행 파일. 사용자 입력부터 텍스트 출력까지 연결 | 제일 먼저 `simple.cpp`를 열 때 |
| **llama** | 모델 로더, 토크나이저, Qwen2 그래프와 decode 구현 | Qwen 텐서가 어디에 쓰이는지 볼 때 |
| **ggml-base** | 텐서, 연산 노드, GGUF 처리, 공통 백엔드 인터페이스와 스케줄러 | `ggml_mul_mat` 또는 백엔드 배정 위치를 볼 때 |
| **ggml** | 사용 가능한 백엔드를 등록하고 찾는 진입점 | CPU와 Vulkan이 장치 목록에 들어오는 과정을 볼 때 |
| **ggml-cpu** | GGML 연산의 CPU 구현 | CPU 실행과 비교할 때 |
| **ggml-vulkan** | GGML 연산을 Vulkan 명령으로 기록·제출 | 행렬곱이 어느 GPU 파이프라인을 타는지 볼 때 |
| **vulkan-shaders-gen** | 빌드 중 GLSL 셰이더 변형을 컴파일하고 사용할 데이터를 생성하는 도구 | 셰이더 빌드 과정을 볼 때 |
| **study-map** | 실습용 파일 모음. 여러 프로젝트의 같은 원본 파일을 한곳에 표시 | Qwen2, 스케줄러, Vulkan 소스를 바로 오갈 때 |
| llama-common | 여러 도구가 공유하는 인자 처리 등 공통 기능 | 더 큰 CLI 예제와 비교할 때 |
| llama-common-base | 빌드 버전·커밋 등 공통 빌드 정보 | 실행 도구에 표시되는 버전의 출처를 볼 때 |
| cpp-httplib | 외부 HTTP 라이브러리 | 네트워크 관련 코드를 찾을 때 |
| vendor-hash | xxHash, SHA-1, SHA-256 등을 묶은 라이브러리 | 해시 계산 구현을 볼 때 |
| ALL_BUILD | 기본 빌드 대상들을 묶어 빌드하는 CMake 프로젝트 | 솔루션을 한꺼번에 빌드할 때 |
| INSTALL | 빌드된 파일을 설정된 설치 위치에 배치하는 CMake 프로젝트 | 설치 결과물을 만들 때 |
| ZERO_CHECK | CMake 입력의 변경을 확인하고 필요하면 VS 프로젝트를 다시 생성 | CMakeLists.txt 변경 후 빌드 흐름을 볼 때 |

## 4. 세 사람이 화면에서 따라갈 순서

1. **SS · 시작과 출력.** `llama-simple → Source Files → simple.cpp`를 연다. 14행의 `main`, 89행의 `llama_model_load_from_file`, 173행의 `llama_decode`, 196행의 `printf`에 차례로 가 본다. 함수 이름에 커서를 두고 **F12**를 누르면 정의 위치로, **Ctrl+G**는 원하는 줄로 이동한다.
2. **HR · Qwen의 계산식.** `study-map → Source Files → qwen2.cpp`에서 119행의 FFN을 열고 `llama-graph.cpp`의 `build_lora_mm`을 따라간다. 최종적으로 `ggml-base`의 `ggml.c`에서 가중치와 입력을 참조하는 `GGML_OP_MUL_MAT` 노드를 확인한다.
3. **WG · GPU 실행.** `study-map → Source Files → ggml-backend.cpp`에서 그래프가 백엔드로 전달되는 지점을 보고, 같은 그룹의 `ggml-vulkan.cpp`에서 `ggml_vk_mul_mat`을 찾는다. 한 토큰의 실제 내적은 `study-map` 바로 아래의 `mul_mat_vec.comp`에서 `dot(v, b)`를 검색하면 보인다.

이 창에서 실제 추론을 시작할 때는 상단의 **Debug / x64**와 굵게 표시된 **llama-simple**을 확인하고 **F5**를 누른다. 첫 중단점은 `simple.cpp` 89행에 **F9**로 둔다. 멈춘 화면의 `model_path`와 `model_params.n_gpu_layers`가 실제 F5 설정을 보여준다.

[팀별 실행과 중간보고](팀별-실행과-중간보고.md) · [모델 로드에서 셰이더까지 실행 흐름도](qwen-vulkan-trace.svg)

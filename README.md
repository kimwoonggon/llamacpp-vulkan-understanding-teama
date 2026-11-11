# llama.cpp Vulkan 실습 · Team A

SS는 GGUF 모델 로드와 추론 진입을, HR은 Qwen2 연산 그래프를, WG는 첫 층 FFN 행렬곱의 Vulkan 실행을 추적합니다.

## 강의와 코드 지도

저장소를 복제한 후 다음 파일을 브라우저로 열면 됩니다.

- [토큰 재생 강의](simple-inference-lecture.html) — 실제 토큰 ID, 콘솔 출력, 현재 C++ 코드 줄을 함께 재생합니다.
- [HR · Qwen2.5 GGML 그래프 강의](hr-ggml-graph-lecture.html) — SS의 decode에서 그래프 생성·재사용, 첫 블록의 텐서, FFN 행렬곱 노드까지 따라갑니다.
- [Graphify 코드 지도](graphify-out/graph.html) — 함수 정의와 호출 위치를 탐색합니다.
- [팀별 실행과 중간보고](팀별-실행과-중간보고.md) · [Visual Studio 솔루션 구조](Visual-Studio-솔루션-구조.md) · [주석을 단 simple.cpp](llama.cpp/examples/simple/simple.cpp)

## 모델과 Windows 실행

1. Visual Studio 2022의 C++ 데스크톱 개발 도구, CMake 3.24 이상, Vulkan SDK를 설치합니다.
2. [공식 Qwen FP16 모델](https://huggingface.co/Qwen/Qwen2.5-1.5B-Instruct-GGUF/resolve/91cad51170dc346986eccefdc2dd33a9da36ead9/qwen2.5-1.5b-instruct-fp16.gguf)을 **`models/qwen2.5-1.5b-instruct-fp16.gguf`**에 저장합니다. 크기와 SHA-256은 [model-source.json](models/model-source.json)에 있습니다.
3. 저장소 루트에서 다음 PowerShell 명령을 실행합니다.

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Debug --target llama-simple --parallel 6
Start-Process .\build\llama-vulkan-lab.sln
```

Visual Studio에서 **Debug / x64 → llama-simple → F5**로 실행합니다. 프로젝트의 디버깅 명령 인수에서 `-ngl 0`은 CPU 비교, `-ngl 99`는 GPU 레이어 배치를 요청합니다. 실습 PC의 실행 결과와 로그는 [실습 안내](README-KO.md)에 있습니다. 문서에 등장하는 `D:\llama-vulkan-lab`은 기록을 남긴 PC의 경로입니다.

Understand-Anything 지도는 Node.js 18 이상이 설치된 환경에서 다음 명령으로 열 수 있습니다.

```powershell
node .\map-tools\viewer\bin\viewer.mjs .\llama.cpp
```

Graphify 지도를 다시 생성하려면 `python -m venv graphify-tools/venv`로 가상 환경을 만들고, 해당 환경에 `graphifyy==0.9.105`를 설치한 뒤 `04-rebuild-graphify.cmd`를 실행합니다.

## 소스 기준

- [llama.cpp](https://github.com/ggml-org/llama.cpp/tree/e6ab7c1a41054a888ada952eab4c886444c2f5ad) 소스와 [라이선스](llama.cpp/LICENSE)를 포함합니다. 실습용 `simple.cpp`에는 한국어 주석이 있습니다.
- [Understand-Anything](https://github.com/Egonex-AI/Understand-Anything/tree/182c7fbf1745d9acd55dda6c47cceff77de4c111) 소스, [라이선스](map-tools/understand-anything/LICENSE), 로컬 수정이 반영된 뷰어를 포함합니다. 수정 내용은 [지도 안내](map-tools/README.md)에 있습니다.

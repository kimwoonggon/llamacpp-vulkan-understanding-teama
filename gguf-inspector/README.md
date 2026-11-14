# GGUF Inspector

GGUF 모델 하나를 읽어 파일 구획, 메타데이터와 텐서를 콘솔에 출력합니다. 같은 결과를 검색 가능한 단일 HTML로 저장할 수 있습니다. 가중치에서는 각 텐서의 처음 16바이트만 읽습니다.

팀 Qwen2.5-1.5B FP16 실행 결과 · [SVG 연산 지도](results/qwen2-model-map.svg) · [콘솔 출력](results/qwen-fp16.txt) · [대화형 HTML](results/qwen-fp16.html). HTML은 내려받아 브라우저로 열면 됩니다.

## Visual Studio에서 실행

1. Visual Studio 2022의 **C++를 사용한 데스크톱 개발**과 CMake 3.24 이상을 설치합니다.
2. 저장소 루트에서 **05-open-gguf-inspector.cmd**를 실행합니다. 전용 솔루션이 열립니다. 파일 위치는 `gguf-inspector/build/gguf-inspector.sln`입니다.
3. **Debug / x64 → Ctrl+F5**로 실행하면 콘솔에 분석 결과가 나옵니다. 브라우저에서 `gguf-inspector/build/report.html`을 열고 텐서 이름이나 GGML 타입으로 검색합니다.
4. 기본 입력은 팀 실습용 `models/qwen2.5-1.5b-instruct-fp16.gguf`입니다. 솔루션 생성 시 모델이 없으면 동봉한 `sample.gguf`로 설정합니다. 다른 모델은 프로젝트 속성의 **디버깅 → 명령 인수**에서 바꿉니다.

전용 솔루션은 저장소 안의 ggml-base를 함께 빌드하며 Vulkan SDK나 GPU가 필요하지 않습니다. 기존 실습 솔루션에도 `gguf-inspector` 대상이 들어 있습니다.

## 명령줄에서 실행

저장소 루트에서 실행합니다.

```powershell
cmake -S gguf-inspector -B gguf-inspector/build -G "Visual Studio 17 2022" -A x64
cmake --build gguf-inspector/build --config Debug --target gguf-inspector
$exe = '.\gguf-inspector\build\bin\Debug\gguf-inspector.exe'
& $exe '.\gguf-inspector\sample.gguf'
& $exe '.\models\qwen2.5-1.5b-instruct-fp16.gguf' --html '.\gguf-inspector\build\report.html'
Start-Process '.\gguf-inspector\build\report.html'
```

## Qwen2 연산 지도

Qwen2 가중치 파일의 HTML에는 토큰 임베딩, 반복 블록, 최종 RMSNorm, 출력 투영을 연결한 SVG가 표시됩니다. 블록을 선택한 뒤 연산 상자를 누르면 해당 파일에서 읽은 텐서 이름·shape·타입·절대 위치를 볼 수 있습니다. 텐서 이름을 누르면 원본 표의 행으로 이동합니다. 화살표는 저장소의 Qwen2 그래프 생성 코드를 기준으로 한 데이터 흐름이며, 점선은 잔차 연결입니다.

## 예제로 패딩 따라가기

동봉한 384바이트 파일은 Header 24 B, Metadata KV 131 B, Tensor Info 88 B 순으로 시작합니다. 끝 주소는 해당 구획에 포함되지 않습니다.

| 위치 또는 계산 | sample.gguf에서 확인할 값 |
|---|---|
| 기술자 끝 → 데이터 시작 | 243 → 256. 32바이트 경계까지 13바이트 |
| A.weight | FP16 35개 × 2 B = 70 B. 파일의 [256, 326)에 저장 |
| 다음 텐서까지의 패딩 | [326, 352), 총 26 B |
| B.weight의 절대 위치 | 데이터 시작 256 + 기술자의 상대 위치 96 = 352 |
| B.weight | Q4_0 한 블록(32개 값) = 18 B. 뒤에 패딩 14 B |

## 읽는 범위

Windows x64 리틀 엔디언 GGUF v2/v3 및 팀 저장소의 GGML 타입을 지원합니다. 배열은 전체 개수와 앞 4개 값, 문자열 값은 앞 192바이트까지 표시합니다. 텐서 크기는 양자화 블록 단위를 반영합니다. 패딩 열은 정렬과 파일 범위로 계산한 길이입니다. 패딩 바이트의 내용이나 전체 가중치 무결성을 검사하지 않습니다.

`inspect.cpp`의 `read_metadata`와 `read_tensor`에서 실제 파일 위치가 어떻게 이동하는지 확인할 수 있습니다. 텐서의 파일 위치는 `data_start + relative`입니다. 파일 레이아웃과 메모리 구조를 비교할 때는 저장소의 [GGUF 파일 형식](../llama.cpp/ggml/include/gguf.h)과 [llama.cpp 로더](../llama.cpp/ggml/src/gguf.cpp)를 함께 보세요.

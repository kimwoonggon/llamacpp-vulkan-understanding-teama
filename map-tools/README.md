# Understand-Anything 코드 지도

`D:\llama-vulkan-lab\03-visual-map.cmd`를 실행하면 공식 Understand-Anything 대시보드가 열립니다. 이미 서버가 실행 중이면 같은 서버와 접근 주소를 다시 사용합니다. 창을 닫아도 로컬 서버는 실행 중이며 재부팅 후에는 실행 파일로 다시 시작할 수 있습니다.

대시보드는 `127.0.0.1`에서만 실행됩니다. 현재 접근 주소와 서버 번호는 `dashboard-state.json`에 저장됩니다. 주소의 `?token=...` 부분도 필요합니다.

## 탐색 방법

- Graph 화면의 노드를 선택하면 설명과 연결 관계를 볼 수 있습니다.
- 담당 영역 안에서 `Cluster A/B/C` 상자를 클릭하면 그 안의 노드가 펼쳐집니다.
- 파일 노드나 소스가 있는 노드를 선택하고 Code를 열면 `D:\llama-vulkan-lab\llama.cpp`의 실제 파일을 읽습니다.
- 담당별 layer: SS(실행과 입력), HR(모델 연산 그래프), WG(백엔드와 Vulkan)
- Learn: 담당 사이의 인계를 따르는 6단계 탐색

## 분석 범위

커밋 `e6ab7c1a41054a888ada952eab4c886444c2f5ad`의 선택 파일 12개, 노드 42개, 관계 67개입니다. 전체 llama.cpp의 함수들을 자동 분석한 전체 지도가 아닙니다. 소스 코드에서 확인한 흐름이며 실제 GPU 실행 결과는 별도로 확인해야 합니다.

## 설치 구성

공식 Understand-Anything v2.9.8의 공개 release viewer 다운로드를 시도했으나 해당 URL이 404를 반환했습니다. 공식 소스를 이 폴더의 `understand-anything`에 별도로 내려받아 core와 dashboard를 빌드하고, 공식 standalone viewer를 `viewer`에 배치했습니다. viewer를 시작하는 데에는 Node.js만 필요하고 매번 인터넷 다운로드나 빌드를 하지 않습니다. `runtime\node.exe`는 현재 PC의 Node 실행 파일 복사본입니다.

실행에 C 드라이브의 ChatGPT 작업 폴더는 필요하지 않습니다. graph 데이터는 `..\llama.cpp\.ua`에 있고 원본 파일도 D 드라이브에서 직접 읽습니다. 자동 commit hook이나 외부 서버는 사용하지 않습니다.

도구 원본: https://github.com/Egonex-AI/Understand-Anything

도구 커밋: `182c7fbf1745d9acd55dda6c47cceff77de4c111`

## 로컬 화면 수정 기록

공식 v2.9.8에서 접힌 cluster 안의 파일을 탐색기에서 열면, 화면에 아직 없는 노드로 확대/이동하여 지도가 화면 밖으로 밀리는 문제가 재현되었습니다. `packages/dashboard/src/components/GraphView.tsx`의 `SelectedNodeFitView`만 로컬에서 수정했습니다. 선택 노드가 실제로 배치되어 있으면 그 노드로 이동하고, 아직 접혀 있으면 보이는 cluster 전체를 화면 안에 맞춥니다. 변경한 dashboard를 다시 빌드하여 viewer에 넣었습니다. 따라서 이 설치본은 공식 viewer에 작은 로컬 화면 수정이 적용된 버전입니다. 원격 저장소에 변경을 보내거나 자동 업데이트를 설치하지 않았습니다.

수정 전에는 파일 선택 후 노드가 화면 밖에 있어 회귀 검사에 실패했고, 수정 후에는 같은 파일 열기와 소스 패널 확인 및 지도 가시성 검사를 통과했습니다. `dashboard-validation.json`과 `dashboard-preview.png`에 확인 결과가 있습니다.

담당 영역의 개수는 파일과 개념 노드를 함께 센 값이므로 `LayerClusterNode.tsx`의 카드 표시를 `files`에서 `nodes`로 바꿨습니다. 원본 파일은 12개이고, 전체 노드는 42개입니다. 개념 노드를 함수 정의로 가장하지 않고 그대로 유지했습니다.

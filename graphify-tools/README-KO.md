# Graphify 코드 지도 재현

`../04-graphify-map.cmd`는 만들어진 지도를 열고, `../04-rebuild-graphify.cmd`는 D드라이브 소스에서 다시 분석합니다.
Python 가상 환경과 Graphify 0.9.105는 이 폴더의 `venv/`에 설치되어 있습니다.
지도 열기에는 Python이나 인터넷 연결이 필요 없습니다.

Graphify의 detect → Tree-sitter AST 추출 → 그래프 생성 → 군집화 → 분석/HTML/JSON/Obsidian 출력을 실행했습니다.
대상은 상위 `llama.cpp/`의 선택한 16개 파일입니다. C/C++ 11개 파일을 자동 추출했고 shader 5개는 파일/명시적 참조로 보완했습니다.
추가 코드 패널은 Graphify 노드의 시작 행을 원본 구문 범위와 대조하여 파일·행·정의 코드 및 호출 근거를 표시합니다.

출력은 `../graphify-out/`에 있습니다.

- `graph.html`: 실제 Graphify 네트워크에 코드 위치 패널을 붙인 오프라인 화면
- `graphify-native.html`: 코드 패널을 붙이기 전 Graphify 기본 화면 (외부 JS만 내장)
- `source-map.json`: 노드별 소스 위치, 전체 선택 파일 스냅샷, 방향/근거를 보존한 추출 관계
- `source-manifest.json`: 원본 파일별 SHA-256과 commit
- `mapping-audit.json`, `GRAPH_REPORT.md`: 범위, 결과 수, 미확인 위치, 한계
- `ui-verification.json`: 실제 브라우저의 검색·코드·클립보드·확대 범위·모바일 확인 결과
- `graph.json`, `obsidian/`: Graphify 자체 출력
- `benchmark.json`, `cost.json`: 질의 컨텍스트 크기 추정과 AST 추출 토큰 기록

핵심 10개 경로는 학습용 진입점이며 모든 단계가 직접 호출로 연결된다는 뜻은 아닙니다.
Graphify의 전역 그래프는 무방향 관계입니다. 오른쪽 근거 목록은 원래 추출된 source/target 방향과 confidence를 보존합니다.
함수 포인터와 C++ 매크로는 자동 분석에서 누락될 수 있습니다. 이 지도는 실시간 GPU 실행 추적이 아닙니다.
정의 위치 미확인 노드에는 임의의 정의 위치를 붙이지 않았습니다. 가능한 경우 사용 위치만 제공합니다.

`extraction.log`는 원래 AST 실행 로그이며 `render.log`는 UI를 갱신하면서 저장한 실행 로그입니다.
`--reuse`는 UI 개발용으로만 사용하며, 소스 변경 후에는 사용하면 안 됩니다.
브라우저 확인 스크립트 `verify-map.cjs`는 이 PC의 기존 Playwright 설치를 사용하는 개발용 도구입니다.

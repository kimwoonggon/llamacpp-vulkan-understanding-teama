---
source_file: "src/llama-context.cpp"
type: "code"
community: "ggml-backend · 27"
location: "L2265"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-backend__27
---

# llama_context::extract_layer_inputs()

## Connections
- [[ggml_backend_sched_get_tensor_backend()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get_async()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llm_graph_result]] - `references` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-backend__27
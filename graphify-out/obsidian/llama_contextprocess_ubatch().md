---
source_file: "src/llama-context.cpp"
type: "code"
community: "ggml-backend · 14"
location: "L1391"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__14
---

# llama_context::process_ubatch()

## Connections
- [[ggml_backend_sched_alloc_graph()]] - `calls` [INFERRED]
- [[ggml_backend_sched_reset()]] - `calls` [INFERRED]
- [[ggml_backend_sched_set_eval_callback()]] - `calls` [INFERRED]
- [[ggml_backend_sched_synchronize()]] - `calls` [INFERRED]
- [[ggml_status]] - `references` [EXTRACTED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llama_memory_context_i]] - `references` [EXTRACTED]
- [[llama_ubatch]] - `references` [EXTRACTED]
- [[llm_graph_result]] - `references` [EXTRACTED]
- [[llm_graph_type]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__14
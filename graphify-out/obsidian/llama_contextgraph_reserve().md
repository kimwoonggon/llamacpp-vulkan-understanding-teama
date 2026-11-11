---
source_file: "src/llama-context.cpp"
type: "code"
community: "ggml-backend · 14"
location: "L2487"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__14
---

# llama_context::graph_reserve()

## Connections
- [[ctx_type_to_graph_type()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_reserve()]] - `calls` [INFERRED]
- [[ggml_backend_sched_reserve_size()]] - `calls` [INFERRED]
- [[ggml_backend_sched_reset()]] - `calls` [INFERRED]
- [[ggml_backend_sched_split_graph()]] - `calls` [INFERRED]
- [[ggml_cgraph]] - `references` [EXTRACTED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llama_graph_n_input_tensors()]] - `calls` [EXTRACTED]
- [[llama_memory_context_i]] - `references` [EXTRACTED]
- [[ubatch_prepare_reserve()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__14
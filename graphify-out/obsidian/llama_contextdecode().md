---
source_file: "src/llama-context.cpp"
type: "code"
community: "llama-context · 32"
location: "L1704"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/llama-context__32
---

# llama_context::decode()

## Connections
- [[copy_tensor_async_rows()]] - `calls` [EXTRACTED]
- [[ctx_type_to_graph_type()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_get_tensor_backend()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get_async()]] - `calls` [INFERRED]
- [[ggml_time_us()]] - `calls` [INFERRED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llama_batch]] - `references` [EXTRACTED]
- [[needs_raw_logits()]] - `calls` [EXTRACTED]
- [[size_3]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/llama-context__32
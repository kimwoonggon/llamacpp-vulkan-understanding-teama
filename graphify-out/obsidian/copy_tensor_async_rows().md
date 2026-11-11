---
source_file: "src/llama-context.cpp"
type: "code"
community: "ggml-backend · 27"
location: "L1653"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__27
---

# copy_tensor_async_rows()

## Connections
- [[buffer_view]] - `references` [EXTRACTED]
- [[ggml_backend_sched_get_tensor_backend()]] - `calls` [INFERRED]
- [[ggml_backend_sched_t_1]] - `references` [EXTRACTED]
- [[ggml_backend_tensor_get_async()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_tensor_3]] - `references` [EXTRACTED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llama_contextdecode()]] - `calls` [EXTRACTED]
- [[vector_3]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__27
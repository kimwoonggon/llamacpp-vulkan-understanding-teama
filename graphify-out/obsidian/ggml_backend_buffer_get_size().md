---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 11"
location: "L127"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__11
---

# ggml_backend_buffer_get_size()

## Connections
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_t]] - `references` [EXTRACTED]
- [[ggml_backend_multi_buffer_alloc_buffer()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_alloc()]] - `calls` [EXTRACTED]
- [[llama_contextllama_context()]] - `calls` [INFERRED]
- [[llama_contextoutput_reserve()]] - `calls` [INFERRED]
- [[llama_modelmemory_breakdown()]] - `calls` [INFERRED]
- [[llama_model_baseload_tensors()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__11
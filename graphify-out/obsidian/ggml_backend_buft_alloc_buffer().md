---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 46"
location: "L39"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__46
---

# ggml_backend_buft_alloc_buffer()

## Connections
- [[buft_supported()]] - `calls` [INFERRED]
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_alloc_buffer()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_init()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_t]] - `references` [EXTRACTED]
- [[ggml_backend_buffer_type_t]] - `references` [EXTRACTED]
- [[ggml_backend_vk_host_buffer_type_alloc_buffer()]] - `calls` [INFERRED]
- [[llama_contextoutput_reserve()]] - `calls` [INFERRED]
- [[llama_model_baseload_tensors()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__46
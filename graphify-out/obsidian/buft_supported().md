---
source_file: "src/llama-model.cpp"
type: "code"
community: "llama-model · 61"
location: "L2186"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/llama-model__61
---

# buft_supported()

## Connections
- [[ggml_backend_buffer_type_t_2]] - `references` [EXTRACTED]
- [[ggml_backend_buft_alloc_buffer()]] - `calls` [INFERRED]
- [[ggml_backend_dev_supports_op()]] - `calls` [INFERRED]
- [[ggml_backend_dev_t_2]] - `references` [EXTRACTED]
- [[ggml_init()]] - `calls` [INFERRED]
- [[ggml_tensor_overhead()]] - `calls` [INFERRED]
- [[llama-model.cpp]] - `contains` [EXTRACTED]
- [[select_buft()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/llama-model__61
---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 11"
location: "L132"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__11
---

# ggml_backend_buffer_get_base()

## Connections
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_t]] - `references` [EXTRACTED]
- [[ggml_backend_tensor_alloc()]] - `calls` [EXTRACTED]
- [[llama_contextoutput_reserve()]] - `calls` [INFERRED]
- [[llama_modelmemory_breakdown()]] - `calls` [INFERRED]
- [[llama_model_baseload_tensors()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__11
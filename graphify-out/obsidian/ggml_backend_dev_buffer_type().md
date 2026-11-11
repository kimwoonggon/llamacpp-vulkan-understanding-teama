---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 24"
location: "L615"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__24
---

# ggml_backend_dev_buffer_type()

## Connections
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_type_t]] - `references` [EXTRACTED]
- [[ggml_backend_dev_t]] - `references` [EXTRACTED]
- [[ggml_backend_get_default_buffer_type()]] - `calls` [EXTRACTED]
- [[llama_contextset_sampler()]] - `calls` [INFERRED]
- [[llama_model_baseload_tensors()]] - `calls` [INFERRED]
- [[make_cpu_buft_list()]] - `calls` [INFERRED]
- [[make_gpu_buft_list()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__24
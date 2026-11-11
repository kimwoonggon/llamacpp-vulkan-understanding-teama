---
source_file: "src/llama-model.cpp"
type: "code"
community: "ggml-backend · 24"
location: "L1061"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-backend__24
---

# make_cpu_buft_list()

## Connections
- [[buft_list_t]] - `references` [EXTRACTED]
- [[ggml_backend_cpu_buffer_type()]] - `calls` [INFERRED]
- [[ggml_backend_dev_backend_reg()]] - `calls` [INFERRED]
- [[ggml_backend_dev_buffer_type()]] - `calls` [INFERRED]
- [[ggml_backend_dev_host_buffer_type()]] - `calls` [INFERRED]
- [[ggml_backend_dev_type()]] - `calls` [INFERRED]
- [[ggml_backend_reg_get_proc_address()]] - `calls` [INFERRED]
- [[llama-model.cpp]] - `contains` [EXTRACTED]
- [[llama_device]] - `references` [EXTRACTED]
- [[llama_model_baseload_tensors()]] - `calls` [EXTRACTED]
- [[vector_5]] - `references` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-backend__24
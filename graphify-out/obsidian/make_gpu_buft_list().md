---
source_file: "src/llama-model.cpp"
type: "code"
community: "ggml-backend · 24"
location: "L1123"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-backend__24
---

# make_gpu_buft_list()

## Connections
- [[buft_list_t]] - `references` [EXTRACTED]
- [[ggml_backend_dev_backend_reg()]] - `calls` [INFERRED]
- [[ggml_backend_dev_buffer_type()]] - `calls` [INFERRED]
- [[ggml_backend_dev_name()]] - `calls` [INFERRED]
- [[ggml_backend_dev_t_2]] - `references` [EXTRACTED]
- [[ggml_backend_reg_dev_count()]] - `calls` [INFERRED]
- [[ggml_backend_reg_dev_get()]] - `calls` [INFERRED]
- [[ggml_backend_reg_get_proc_address()]] - `calls` [INFERRED]
- [[llama-model.cpp]] - `contains` [EXTRACTED]
- [[llama_model_baseload_tensors()]] - `calls` [EXTRACTED]
- [[llama_split_mode]] - `references` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-backend__24
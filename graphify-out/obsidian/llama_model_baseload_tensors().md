---
source_file: "src/llama-model.cpp"
type: "code"
community: "ggml-backend · 24"
location: "L1432"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-backend__24
---

# llama_model_base::load_tensors()

## Connections
- [[ggml_backend_buffer_get_base()]] - `calls` [INFERRED]
- [[ggml_backend_buffer_get_size()]] - `calls` [INFERRED]
- [[ggml_backend_buffer_is_host()]] - `calls` [INFERRED]
- [[ggml_backend_buffer_name()]] - `calls` [INFERRED]
- [[ggml_backend_buffer_set_usage()]] - `calls` [INFERRED]
- [[ggml_backend_buft_alloc_buffer()]] - `calls` [INFERRED]
- [[ggml_backend_buft_get_device()]] - `calls` [INFERRED]
- [[ggml_backend_buft_name()]] - `calls` [INFERRED]
- [[ggml_backend_dev_buffer_from_host_ptr()]] - `calls` [INFERRED]
- [[ggml_backend_dev_buffer_type()]] - `calls` [INFERRED]
- [[ggml_backend_dev_get_props()]] - `calls` [INFERRED]
- [[ggml_backend_dev_memory()]] - `calls` [INFERRED]
- [[ggml_backend_dev_name()]] - `calls` [INFERRED]
- [[ggml_get_first_tensor()]] - `calls` [INFERRED]
- [[ggml_get_max_tensor_size()]] - `calls` [INFERRED]
- [[ggml_get_name()]] - `calls` [INFERRED]
- [[ggml_get_next_tensor()]] - `calls` [INFERRED]
- [[llama-model.cpp]] - `contains` [EXTRACTED]
- [[llama_model_loader]] - `references` [EXTRACTED]
- [[make_cpu_buft_list()]] - `calls` [EXTRACTED]
- [[make_gpu_buft_list()]] - `calls` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-backend__24
---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml · 34"
location: "L488"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__34
---

# ggml_backend_tensor_copy()

## Connections
- [[dot-llama_io_read_device()]] - `calls` [INFERRED]
- [[dot-llama_io_write_device()]] - `calls` [INFERRED]
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_copy_tensor()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_is_host()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_name()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_copy_async()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_get()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_set()]] - `calls` [EXTRACTED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[graph_copy_init_tensor()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml__34
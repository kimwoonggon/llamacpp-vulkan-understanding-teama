---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 27"
location: "L279"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__27
---

# ggml_backend_tensor_get_async()

## Connections
- [[copy_tensor_async_rows()]] - `calls` [INFERRED]
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [EXTRACTED]
- [[ggml_backend_synchronize()]] - `calls` [EXTRACTED]
- [[ggml_backend_t]] - `references` [EXTRACTED]
- [[ggml_backend_tensor_get()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_get_2d_async()]] - `calls` [EXTRACTED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[llama_contextdecode()]] - `calls` [INFERRED]
- [[llama_contextencode()]] - `calls` [INFERRED]
- [[llama_contextextract_layer_inputs()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__27
---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 27"
location: "L2097"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__27
---

# ggml_backend_sched_get_tensor_backend()

## Connections
- [[copy_tensor_async_rows()]] - `calls` [INFERRED]
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_print_assignments()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_t]] - `references` [EXTRACTED]
- [[ggml_backend_t]] - `references` [EXTRACTED]
- [[llama_contextdecode()]] - `calls` [INFERRED]
- [[llama_contextencode()]] - `calls` [INFERRED]
- [[llama_contextextract_layer_inputs()]] - `calls` [INFERRED]
- [[llama_contextresolve_fused_ops()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__27
---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 27"
location: "L1646"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__27
---

# ggml_backend_sched_compute_splits()

## Connections
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_get_usage()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_is_host()]] - `calls` [EXTRACTED]
- [[ggml_backend_event_record()]] - `calls` [EXTRACTED]
- [[ggml_backend_event_synchronize()]] - `calls` [EXTRACTED]
- [[ggml_backend_event_wait()]] - `calls` [EXTRACTED]
- [[ggml_backend_graph_compute_async()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_get_tensor_backend()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_graph_compute_async()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_t]] - `references` [EXTRACTED]
- [[ggml_backend_synchronize()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_copy()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_get_async()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_set_async()]] - `calls` [EXTRACTED]
- [[ggml_graph_view()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__27
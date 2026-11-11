---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "ggml-backend · 14"
location: "L1066"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-backend__14
---

# ggml_backend_sched_split_graph()

## Connections
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_graph_optimize()]] - `calls` [EXTRACTED]
- [[ggml_backend_name()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_alloc_graph()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_backend_id_from_cur()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_buffer_supported()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_graph_inputs_grow()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_print_assignments()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_reserve()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_reserve_size()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_set_if_supported()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_split_inputs_grow()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_t]] - `references` [EXTRACTED]
- [[ggml_backend_supports_op()]] - `calls` [EXTRACTED]
- [[ggml_dup_tensor_layout()]] - `calls` [EXTRACTED]
- [[ggml_format_name()]] - `calls` [INFERRED]
- [[ggml_free()]] - `calls` [INFERRED]
- [[ggml_graph_next_uid()]] - `calls` [INFERRED]
- [[ggml_graph_view()]] - `calls` [INFERRED]
- [[ggml_init()]] - `calls` [INFERRED]
- [[ggml_is_view_op()]] - `calls` [EXTRACTED]
- [[ggml_set_input()]] - `calls` [INFERRED]
- [[ggml_set_output()]] - `calls` [INFERRED]
- [[ggml_view_tensor()]] - `calls` [INFERRED]
- [[llama_contextgraph_reserve()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-backend__14
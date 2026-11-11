---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 17"
location: "L1364"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__17
---

# ggml_op_name()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_backend_sched_backend_id_from_cur()]] - `calls` [INFERRED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_graph_print()]] - `calls` [EXTRACTED]
- [[ggml_op_desc()]] - `calls` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [INFERRED]
- [[ggml_vk_compute_forward()]] - `calls` [INFERRED]
- [[ggml_vk_debug_labelggml_vk_debug_label()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[ggml_vk_print_node_list()]] - `calls` [INFERRED]
- [[llama_graph_n_input_tensors()]] - `calls` [INFERRED]
- [[vk_perf_loggerget_node_fusion_name()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__17
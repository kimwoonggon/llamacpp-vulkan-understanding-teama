---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 17"
location: "L1932"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__17
---

# ggml_get_unary_op()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [INFERRED]
- [[ggml_build_backward_expand()]] - `calls` [EXTRACTED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_op_desc()]] - `calls` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_ssm_conv()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_topk_moe()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_unary_mul()]] - `calls` [INFERRED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_unary_mul()]] - `calls` [INFERRED]
- [[vk_perf_loggerget_node_fusion_name()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__17
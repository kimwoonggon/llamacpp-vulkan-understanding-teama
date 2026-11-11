---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 17"
location: "L13452"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__17
---

# ggml_vk_can_fuse_topk_moe()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [EXTRACTED]
- [[ggml_get_unary_op()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nrows()]] - `calls` [INFERRED]
- [[topk_moe_mode]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__17
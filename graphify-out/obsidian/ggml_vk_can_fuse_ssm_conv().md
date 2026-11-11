---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 17"
location: "L13397"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__17
---

# ggml_vk_can_fuse_ssm_conv()

## Connections
- [[get_misalign_bytes()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [EXTRACTED]
- [[ggml_get_unary_op()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__17
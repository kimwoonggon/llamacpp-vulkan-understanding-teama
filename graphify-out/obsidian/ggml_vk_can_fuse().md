---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L13201"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_can_fuse()

## Connections
- [[get_misalign_bytes()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_are_same_shape()]] - `calls` [INFERRED]
- [[ggml_are_same_stride()]] - `calls` [INFERRED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_contiguous_rows()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_nrows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_unary_mul_pair()]] - `calls` [EXTRACTED]
- [[ggml_vk_use_mul_mat_vec_id()]] - `calls` [EXTRACTED]
- [[initializer_list_1]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
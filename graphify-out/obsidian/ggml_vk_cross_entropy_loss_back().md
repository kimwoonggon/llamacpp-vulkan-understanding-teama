---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L11338"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_vk_cross_entropy_loss_back()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_are_same_shape()]] - `calls` [INFERRED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_scalar()]] - `calls` [INFERRED]
- [[ggml_nrows()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_nrows_elements()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
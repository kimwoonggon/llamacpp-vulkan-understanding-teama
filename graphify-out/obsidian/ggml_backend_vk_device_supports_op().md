---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L15014"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_backend_vk_device_supports_op()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_are_same_shape()]] - `calls` [INFERRED]
- [[ggml_backend_dev_t_1]] - `references` [EXTRACTED]
- [[ggml_get_glu_op()]] - `calls` [INFERRED]
- [[ggml_get_unary_op()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_contiguous_rows()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_is_scalar()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_concat_supported()]] - `calls` [EXTRACTED]
- [[ggml_vk_dim01_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_lightning_indexer_k_type_supported()]] - `calls` [EXTRACTED]
- [[vk_tensor_offset()]] - `calls` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
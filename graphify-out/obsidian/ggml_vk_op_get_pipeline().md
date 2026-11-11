---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L8336"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_vk_op_get_pipeline()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_are_same_shape()]] - `calls` [INFERRED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_get_glu_op()]] - `calls` [INFERRED]
- [[ggml_get_unary_op()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_contiguous_channels()]] - `calls` [INFERRED]
- [[ggml_op]] - `references` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_arange()]] - `calls` [EXTRACTED]
- [[ggml_vk_concat_supported()]] - `calls` [EXTRACTED]
- [[ggml_vk_concat_unit_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_select_shape()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [EXTRACTED]
- [[ggml_vk_fill()]] - `calls` [EXTRACTED]
- [[ggml_vk_gated_delta_net()]] - `calls` [EXTRACTED]
- [[ggml_vk_gated_linear_attn()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_lightning_indexer()]] - `calls` [EXTRACTED]
- [[ggml_vk_lightning_indexer_k_type_supported()]] - `calls` [EXTRACTED]
- [[ggml_vk_multi_add()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32_wkv()]] - `calls` [EXTRACTED]
- [[ggml_vk_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk_moe()]] - `calls` [EXTRACTED]
- [[vk_pipeline]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
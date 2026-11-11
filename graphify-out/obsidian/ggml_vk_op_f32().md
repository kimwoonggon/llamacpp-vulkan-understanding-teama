---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 8"
location: "L9082"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__8
---

# ggml_vk_op_f32()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_blck_size()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_nrows()]] - `calls` [INFERRED]
- [[ggml_op]] - `references` [EXTRACTED]
- [[ggml_op_name()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_name()]] - `calls` [INFERRED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_clamp()]] - `calls` [EXTRACTED]
- [[ggml_vk_col2im_1d()]] - `calls` [EXTRACTED]
- [[ggml_vk_concat_unit_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_2d()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_2d_dw()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_3d()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_select_shape()]] - `calls` [EXTRACTED]
- [[ggml_vk_conv_transpose_1d()]] - `calls` [EXTRACTED]
- [[ggml_vk_cos()]] - `calls` [EXTRACTED]
- [[ggml_vk_cpy()]] - `calls` [EXTRACTED]
- [[ggml_vk_cumsum()]] - `calls` [EXTRACTED]
- [[ggml_vk_diag()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_leaky_relu()]] - `calls` [EXTRACTED]
- [[ggml_vk_log()]] - `calls` [EXTRACTED]
- [[ggml_vk_mean()]] - `calls` [EXTRACTED]
- [[ggml_vk_norm()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_pad()]] - `calls` [EXTRACTED]
- [[ggml_vk_pad_reflect_1d()]] - `calls` [EXTRACTED]
- [[ggml_vk_repeat()]] - `calls` [EXTRACTED]
- [[ggml_vk_repeat_back()]] - `calls` [EXTRACTED]
- [[ggml_vk_roll()]] - `calls` [EXTRACTED]
- [[ggml_vk_scale()]] - `calls` [EXTRACTED]
- [[ggml_vk_sin()]] - `calls` [EXTRACTED]
- [[ggml_vk_sqr()]] - `calls` [EXTRACTED]
- [[ggml_vk_sqrt()]] - `calls` [EXTRACTED]
- [[ggml_vk_subbuffer()]] - `calls` [EXTRACTED]
- [[ggml_vk_sum()]] - `calls` [EXTRACTED]
- [[ggml_vk_sum_rows()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[ggml_vk_tri()]] - `calls` [EXTRACTED]
- [[ggml_vk_unary()]] - `calls` [EXTRACTED]
- [[ggml_vk_xielu()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__8
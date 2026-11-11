---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1333"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_type_size()

## Connections
- [[fa_block_bytes()]] - `calls` [INFERRED]
- [[get_misalign_bytes()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_conv_2d_dw_direct()]] - `calls` [EXTRACTED]
- [[ggml_element_size()]] - `calls` [EXTRACTED]
- [[ggml_flash_attn_back()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_channels()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_m_n()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_rows()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguously_allocated()]] - `calls` [EXTRACTED]
- [[ggml_is_padded_1d()]] - `calls` [EXTRACTED]
- [[ggml_nbytes()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[ggml_roll()]] - `calls` [EXTRACTED]
- [[ggml_row_size()]] - `calls` [EXTRACTED]
- [[ggml_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_vk_acc()]] - `calls` [INFERRED]
- [[ggml_vk_add()]] - `calls` [INFERRED]
- [[ggml_vk_add1()]] - `calls` [INFERRED]
- [[ggml_vk_add_id()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rope_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_concat()]] - `calls` [INFERRED]
- [[ggml_vk_concat_supported()]] - `calls` [INFERRED]
- [[ggml_vk_concat_unit_size()]] - `calls` [INFERRED]
- [[ggml_vk_cpy()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [INFERRED]
- [[ggml_vk_dim01_contiguous()]] - `calls` [INFERRED]
- [[ggml_vk_div()]] - `calls` [INFERRED]
- [[ggml_vk_flash_attn()]] - `calls` [INFERRED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_rows()]] - `calls` [INFERRED]
- [[ggml_vk_get_rows_back()]] - `calls` [INFERRED]
- [[ggml_vk_glu()]] - `calls` [INFERRED]
- [[ggml_vk_im2col_3d()]] - `calls` [INFERRED]
- [[ggml_vk_make_rope_constants()]] - `calls` [INFERRED]
- [[ggml_vk_mul()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_nb_elem()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_out_prod()]] - `calls` [INFERRED]
- [[ggml_vk_rms_norm()]] - `calls` [INFERRED]
- [[ggml_vk_rope()]] - `calls` [INFERRED]
- [[ggml_vk_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_solve_tri()]] - `calls` [INFERRED]
- [[ggml_vk_sub()]] - `calls` [INFERRED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [INFERRED]
- [[ggml_vk_timestep_embedding()]] - `calls` [INFERRED]
- [[ggml_vk_topk_moe()]] - `calls` [INFERRED]
- [[ggml_vk_unary_mul()]] - `calls` [INFERRED]
- [[ggml_vk_upscale()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
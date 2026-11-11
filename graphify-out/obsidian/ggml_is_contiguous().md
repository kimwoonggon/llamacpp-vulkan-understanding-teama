---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1494"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_is_contiguous()

## Connections
- [[copy_tensor_async_rows()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_acc_impl()]] - `calls` [EXTRACTED]
- [[ggml_add_rel_pos_impl()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_col2im_1d()]] - `calls` [EXTRACTED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_fill_impl()]] - `calls` [EXTRACTED]
- [[ggml_flash_attn_ext()]] - `calls` [EXTRACTED]
- [[ggml_gated_delta_net()]] - `calls` [EXTRACTED]
- [[ggml_gated_linear_attn()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_0()]] - `calls` [EXTRACTED]
- [[ggml_pad_reflect_1d()]] - `calls` [EXTRACTED]
- [[ggml_reshape()]] - `calls` [EXTRACTED]
- [[ggml_reshape_1d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_2d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_3d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_4d()]] - `calls` [EXTRACTED]
- [[ggml_rwkv_wkv6()]] - `calls` [EXTRACTED]
- [[ggml_rwkv_wkv7()]] - `calls` [EXTRACTED]
- [[ggml_soft_max_impl()]] - `calls` [EXTRACTED]
- [[ggml_solve_tri()]] - `calls` [EXTRACTED]
- [[ggml_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_tri()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rms_norm_mul_rope()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rope_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_snake()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_ssm_conv()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_topk_moe()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_topk_qsa()]] - `calls` [INFERRED]
- [[ggml_vk_can_use_fwht()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [INFERRED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [INFERRED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_inp_embd()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 8"
location: "L1286"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__8
---

# ggml_nelements()

## Connections
- [[copy_tensor_async_rows()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_acc_impl()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [INFERRED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_cont_4d()]] - `calls` [EXTRACTED]
- [[ggml_cpy_impl()]] - `calls` [EXTRACTED]
- [[ggml_flash_attn_back()]] - `calls` [EXTRACTED]
- [[ggml_gated_linear_attn()]] - `calls` [EXTRACTED]
- [[ggml_graph_dump_dot()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguously_allocated()]] - `calls` [EXTRACTED]
- [[ggml_opt_step_adamw()]] - `calls` [EXTRACTED]
- [[ggml_opt_step_sgd()]] - `calls` [EXTRACTED]
- [[ggml_reshape()]] - `calls` [EXTRACTED]
- [[ggml_reshape_1d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_2d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_3d()]] - `calls` [EXTRACTED]
- [[ggml_reshape_4d()]] - `calls` [EXTRACTED]
- [[ggml_rwkv_wkv6()]] - `calls` [EXTRACTED]
- [[ggml_rwkv_wkv7()]] - `calls` [EXTRACTED]
- [[ggml_set_impl()]] - `calls` [EXTRACTED]
- [[ggml_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_vk_acc()]] - `calls` [INFERRED]
- [[ggml_vk_add()]] - `calls` [INFERRED]
- [[ggml_vk_add1()]] - `calls` [INFERRED]
- [[ggml_vk_arange()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_rope_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_ssm_conv()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_topk_qsa()]] - `calls` [INFERRED]
- [[ggml_vk_conv_2d_dw()]] - `calls` [INFERRED]
- [[ggml_vk_count_equal()]] - `calls` [INFERRED]
- [[ggml_vk_cpy()]] - `calls` [INFERRED]
- [[ggml_vk_cpy_to_contiguous()]] - `calls` [INFERRED]
- [[ggml_vk_cpy_to_strided()]] - `calls` [INFERRED]
- [[ggml_vk_diag()]] - `calls` [INFERRED]
- [[ggml_vk_div()]] - `calls` [INFERRED]
- [[ggml_vk_fill()]] - `calls` [INFERRED]
- [[ggml_vk_flash_attn()]] - `calls` [INFERRED]
- [[ggml_vk_get_rows()]] - `calls` [INFERRED]
- [[ggml_vk_get_rows_back()]] - `calls` [INFERRED]
- [[ggml_vk_glu()]] - `calls` [INFERRED]
- [[ggml_vk_mul()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_multi_add()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [INFERRED]
- [[ggml_vk_opt_step_adamw()]] - `calls` [INFERRED]
- [[ggml_vk_opt_step_sgd()]] - `calls` [INFERRED]
- [[ggml_vk_out_prod()]] - `calls` [INFERRED]
- [[ggml_vk_pad_reflect_1d()]] - `calls` [INFERRED]
- [[ggml_vk_repeat()]] - `calls` [INFERRED]
- [[ggml_vk_repeat_back()]] - `calls` [INFERRED]
- [[ggml_vk_set_rows()]] - `calls` [INFERRED]
- [[ggml_vk_silu_back()]] - `calls` [INFERRED]
- [[ggml_vk_solve_tri()]] - `calls` [INFERRED]
- [[ggml_vk_ssm_scan()]] - `calls` [INFERRED]
- [[ggml_vk_sub()]] - `calls` [INFERRED]
- [[ggml_vk_sum()]] - `calls` [INFERRED]
- [[ggml_vk_unary_mul()]] - `calls` [INFERRED]
- [[ggml_vk_upscale()]] - `calls` [INFERRED]
- [[llama_model_get_tok_embd()]] - `calls` [INFERRED]
- [[llm_graph_input_attn_no_cacheset_input()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__8
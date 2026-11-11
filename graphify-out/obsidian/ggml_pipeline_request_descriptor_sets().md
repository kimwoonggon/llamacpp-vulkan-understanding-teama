---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L816"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_pipeline_request_descriptor_sets()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_pipeline_allocate_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_vk_arange()]] - `calls` [EXTRACTED]
- [[ggml_vk_argsort()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [EXTRACTED]
- [[ggml_vk_cumsum()]] - `calls` [EXTRACTED]
- [[ggml_vk_dsv4_hc_comb()]] - `calls` [EXTRACTED]
- [[ggml_vk_dsv4_hc_post()]] - `calls` [EXTRACTED]
- [[ggml_vk_dsv4_hc_pre()]] - `calls` [EXTRACTED]
- [[ggml_vk_fill()]] - `calls` [EXTRACTED]
- [[ggml_vk_flash_attn()]] - `calls` [EXTRACTED]
- [[ggml_vk_fwht()]] - `calls` [EXTRACTED]
- [[ggml_vk_gated_delta_net()]] - `calls` [EXTRACTED]
- [[ggml_vk_gated_linear_attn()]] - `calls` [EXTRACTED]
- [[ggml_vk_lightning_indexer()]] - `calls` [EXTRACTED]
- [[ggml_vk_matmul()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_p021_f16_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_multi_add()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32_wkv()]] - `calls` [EXTRACTED]
- [[ggml_vk_rms_norm()]] - `calls` [EXTRACTED]
- [[ggml_vk_snake_dispatch_fused()]] - `calls` [EXTRACTED]
- [[ggml_vk_soft_max()]] - `calls` [EXTRACTED]
- [[ggml_vk_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk_moe()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk_qsa()]] - `calls` [EXTRACTED]
- [[vk_pipeline]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
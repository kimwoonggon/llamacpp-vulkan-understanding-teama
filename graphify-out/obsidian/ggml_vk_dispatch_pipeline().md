---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan-common.h"
type: "code"
community: "ggml-vulkan · 10"
location: "L249"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__10
---

# ggml_vk_dispatch_pipeline()

## Connections
- [[DescriptorBufferInfo]] - `references` [EXTRACTED]
- [[array]] - `references` [EXTRACTED]
- [[ggml-vulkan-common.h]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_vk_arange()]] - `calls` [INFERRED]
- [[ggml_vk_argsort()]] - `calls` [INFERRED]
- [[ggml_vk_cpy_to_contiguous()]] - `calls` [INFERRED]
- [[ggml_vk_cpy_to_strided()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [INFERRED]
- [[ggml_vk_cumsum()]] - `calls` [INFERRED]
- [[ggml_vk_dsv4_hc_comb()]] - `calls` [INFERRED]
- [[ggml_vk_dsv4_hc_post()]] - `calls` [INFERRED]
- [[ggml_vk_dsv4_hc_pre()]] - `calls` [INFERRED]
- [[ggml_vk_fill()]] - `calls` [INFERRED]
- [[ggml_vk_flash_attn()]] - `calls` [INFERRED]
- [[ggml_vk_fwht()]] - `calls` [INFERRED]
- [[ggml_vk_gated_delta_net()]] - `calls` [INFERRED]
- [[ggml_vk_gated_linear_attn()]] - `calls` [INFERRED]
- [[ggml_vk_lightning_indexer()]] - `calls` [INFERRED]
- [[ggml_vk_matmul()]] - `calls` [INFERRED]
- [[ggml_vk_matmul_id()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_p021_f16_f32()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_multi_add()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_wkv()]] - `calls` [INFERRED]
- [[ggml_vk_quantize_q8_1()]] - `calls` [INFERRED]
- [[ggml_vk_rms_norm()]] - `calls` [INFERRED]
- [[ggml_vk_snake_dispatch_fused()]] - `calls` [INFERRED]
- [[ggml_vk_soft_max()]] - `calls` [INFERRED]
- [[ggml_vk_ssm_scan()]] - `calls` [INFERRED]
- [[ggml_vk_topk()]] - `calls` [INFERRED]
- [[ggml_vk_topk_moe()]] - `calls` [INFERRED]
- [[ggml_vk_topk_qsa()]] - `calls` [INFERRED]
- [[initializer_list]] - `references` [EXTRACTED]
- [[push_constant_size]] - `calls` [INFERRED]
- [[vk_context]] - `references` [EXTRACTED]
- [[vk_pipeline]] - `references` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__10
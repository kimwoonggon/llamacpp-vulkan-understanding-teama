---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1327"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_blck_size()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_conv_2d_dw_direct()]] - `calls` [EXTRACTED]
- [[ggml_flash_attn_back()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_m_n()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous_rows()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguously_allocated()]] - `calls` [EXTRACTED]
- [[ggml_nbytes()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[ggml_row_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_concat()]] - `calls` [INFERRED]
- [[ggml_vk_cpy()]] - `calls` [INFERRED]
- [[ggml_vk_dim01_contiguous()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[llama_init_from_model()]] - `calls` [INFERRED]
- [[llama_meta_device_get_split_state()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
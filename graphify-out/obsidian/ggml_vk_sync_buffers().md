---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L1116"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_vk_sync_buffers()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_backend_vk_get_tensor_2d_async()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_set_tensor_2d_async()]] - `calls` [EXTRACTED]
- [[ggml_vk_argsort()]] - `calls` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_cpy_to_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_cpy_to_strided()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [EXTRACTED]
- [[ggml_vk_cumsum()]] - `calls` [EXTRACTED]
- [[ggml_vk_flash_attn()]] - `calls` [EXTRACTED]
- [[ggml_vk_matmul()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_quantize_q8_1()]] - `calls` [EXTRACTED]
- [[ggml_vk_soft_max()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk()]] - `calls` [EXTRACTED]
- [[ggml_vk_topk_qsa()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
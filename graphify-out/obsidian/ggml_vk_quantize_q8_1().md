---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L6007"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_quantize_q8_1()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_quantize_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]
- [[vk_subbuffer]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
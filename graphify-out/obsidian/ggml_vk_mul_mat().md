---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L6980"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_mul_mat()

## Connections
- [[get_misalign_bytes()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_permuted()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_is_transposed()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_use_fwht()]] - `calls` [EXTRACTED]
- [[ggml_vk_fwht()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_p021_f16_f32()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
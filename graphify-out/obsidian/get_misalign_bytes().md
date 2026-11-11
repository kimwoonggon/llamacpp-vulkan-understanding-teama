---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L271"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# get_misalign_bytes()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_rope_set_rows()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_ssm_conv()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [EXTRACTED]
- [[ggml_vk_descriptor_offset()]] - `calls` [EXTRACTED]
- [[ggml_vk_fuse_multi_add()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [EXTRACTED]
- [[ggml_vk_rms_norm()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_buffer_offset()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
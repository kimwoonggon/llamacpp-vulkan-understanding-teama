---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 3"
location: "L13009"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__3
---

# ggml_backend_vk_cpy_tensor_async()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_is_host()]] - `calls` [INFERRED]
- [[ggml_backend_buffer_is_vk()]] - `calls` [EXTRACTED]
- [[ggml_backend_t_1]] - `references` [EXTRACTED]
- [[ggml_backend_vk_get_default_buffer_type()]] - `calls` [EXTRACTED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_vk_get_compute_ctx()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_transfer_ctx()]] - `calls` [EXTRACTED]
- [[vk_tensor_offset()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__3
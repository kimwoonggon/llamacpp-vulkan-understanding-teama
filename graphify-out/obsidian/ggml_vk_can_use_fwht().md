---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 3"
location: "L6832"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__3
---

# ggml_vk_can_use_fwht()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_vk_fwht_pipeline_idx()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__3
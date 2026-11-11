---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 8"
location: "L10352"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__8
---

# ggml_vk_cpy()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_blck_size()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_op_f32()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__8
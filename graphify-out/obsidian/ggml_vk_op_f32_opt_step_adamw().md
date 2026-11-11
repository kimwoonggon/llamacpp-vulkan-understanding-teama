---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L10086"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_vk_op_f32_opt_step_adamw()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_are_same_shape()]] - `calls` [INFERRED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_opt_step_adamw()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]
- [[vk_op_push_constants]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
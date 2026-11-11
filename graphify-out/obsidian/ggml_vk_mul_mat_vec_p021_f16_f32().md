---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L6636"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_mul_mat_vec_p021_f16_f32()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_is_permuted()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_64b_indexing_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
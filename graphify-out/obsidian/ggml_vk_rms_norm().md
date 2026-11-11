---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan-types · 7"
location: "L10482"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan-types__7
---

# ggml_vk_rms_norm()

## Connections
- [[get_misalign_bytes()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_make_rope_constants()]] - `calls` [EXTRACTED]
- [[ggml_vk_rms_norm_finish()]] - `calls` [EXTRACTED]
- [[ggml_vk_rms_num_partials()]] - `calls` [EXTRACTED]
- [[ggml_vk_subbuffer()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]
- [[vk_tensor_offset()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan-types__7
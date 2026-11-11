---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 10"
location: "L7779"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_vk_flash_attn()

## Connections
- [[get_fa_pipeline_state()]] - `calls` [EXTRACTED]
- [[get_fa_tuning_params()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_row_size()]] - `calls` [INFERRED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_to_fp16()]] - `calls` [EXTRACTED]
- [[ggml_vk_preallocate_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_subbuffer()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
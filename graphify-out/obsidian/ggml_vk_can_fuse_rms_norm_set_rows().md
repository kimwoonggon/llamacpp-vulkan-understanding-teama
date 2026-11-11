---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L13686"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_can_fuse_rms_norm_set_rows()

## Connections
- [[get_misalign_bytes()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_backend_vk_graph_compute()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_type_size()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
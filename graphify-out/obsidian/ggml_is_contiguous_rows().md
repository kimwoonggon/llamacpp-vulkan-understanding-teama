---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1539"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_is_contiguous_rows()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_blck_size()]] - `calls` [EXTRACTED]
- [[ggml_gated_delta_net()]] - `calls` [EXTRACTED]
- [[ggml_set_rows()]] - `calls` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [EXTRACTED]
- [[ggml_unary_impl()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse()]] - `calls` [INFERRED]
- [[ggml_vk_concat_supported()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
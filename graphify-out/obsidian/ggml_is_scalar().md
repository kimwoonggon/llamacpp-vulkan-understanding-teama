---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 10"
location: "L1396"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__10
---

# ggml_is_scalar()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_add1_impl()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_cross_entropy_loss_back()]] - `calls` [EXTRACTED]
- [[ggml_graph_reset()]] - `calls` [EXTRACTED]
- [[ggml_set_loss()]] - `calls` [EXTRACTED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__10
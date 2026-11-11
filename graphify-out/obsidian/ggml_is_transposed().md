---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1470"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_is_transposed()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_mul_mat_id()]] - `calls` [EXTRACTED]
- [[ggml_out_prod()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
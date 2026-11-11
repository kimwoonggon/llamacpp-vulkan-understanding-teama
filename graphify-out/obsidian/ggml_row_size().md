---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 2"
location: "L1339"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__2
---

# ggml_row_size()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_blck_size()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[ggml_quantize_chunk()]] - `calls` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_flash_attn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_qkv()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml__2
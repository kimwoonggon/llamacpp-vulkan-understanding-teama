---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L3742"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__5
---

# ggml_reshape_3d()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_conv_1d()]] - `calls` [EXTRACTED]
- [[ggml_conv_1d_dw()]] - `calls` [EXTRACTED]
- [[ggml_format_name()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_nelements()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_lora_mm_id()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_moe_ffn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_norm()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_pos_bias()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_qkv()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_rwkv_token_shift_load()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml__5
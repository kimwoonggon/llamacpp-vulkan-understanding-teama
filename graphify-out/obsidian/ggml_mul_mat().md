---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L3341"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__5
---

# ggml_mul_mat()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_can_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_conv_1d()]] - `calls` [EXTRACTED]
- [[ggml_conv_1d_dw()]] - `calls` [EXTRACTED]
- [[ggml_conv_2d()]] - `calls` [EXTRACTED]
- [[ggml_conv_2d_dw()]] - `calls` [EXTRACTED]
- [[ggml_conv_3d()]] - `calls` [EXTRACTED]
- [[ggml_is_transposed()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_mha()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_dense_out()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_inp_embd()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_lora_mm()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_pooling()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml__5
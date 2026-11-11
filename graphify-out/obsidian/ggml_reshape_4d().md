---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L3761"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__5
---

# ggml_reshape_4d()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_conv_1d_dw()]] - `calls` [EXTRACTED]
- [[ggml_conv_2d()]] - `calls` [EXTRACTED]
- [[ggml_conv_2d_dw()]] - `calls` [EXTRACTED]
- [[ggml_conv_3d()]] - `calls` [EXTRACTED]
- [[ggml_format_name()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_nelements()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_mha()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_moe_ffn()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml__5
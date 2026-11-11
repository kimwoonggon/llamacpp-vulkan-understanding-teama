---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L4000"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__5
---

# ggml_set_rows()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_is_contiguous_rows()]] - `calls` [EXTRACTED]
- [[ggml_view_tensor()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_moe_ffn()]] - `calls` [INFERRED]

#graphify/code #graphify/EXTRACTED #community/ggml__5
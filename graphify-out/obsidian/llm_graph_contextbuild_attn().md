---
source_file: "src/llama-graph.cpp"
type: "code"
community: "ggml · 5"
location: "L2766"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__5
---

# llm_graph_context::build_attn()

## Connections
- [[ggml_add()]] - `calls` [INFERRED]
- [[ggml_build_forward_expand()]] - `calls` [INFERRED]
- [[ggml_fill()]] - `calls` [INFERRED]
- [[ggml_mul()]] - `calls` [INFERRED]
- [[ggml_new_tensor_4d()]] - `calls` [INFERRED]
- [[ggml_prec_set_acc()]] - `calls` [INFERRED]
- [[ggml_set_rows()]] - `calls` [INFERRED]
- [[ggml_tensor_4]] - `references` [EXTRACTED]
- [[ggml_view_4d()]] - `calls` [INFERRED]
- [[llama-graph.cpp]] - `contains` [EXTRACTED]
- [[llm_graph_input_attn_cross]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_k]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_k_dsa]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_k_iswa]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_kv]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_kv_iswa]] - `references` [EXTRACTED]
- [[llm_graph_input_attn_no_cache]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml__5
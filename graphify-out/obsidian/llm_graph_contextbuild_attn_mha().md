---
source_file: "src/llama-graph.cpp"
type: "code"
community: "ggml · 5"
location: "L2602"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml__5
---

# llm_graph_context::build_attn_mha()

## Connections
- [[ggml_add()]] - `calls` [INFERRED]
- [[ggml_backend_sched_set_tensor_backend()]] - `calls` [INFERRED]
- [[ggml_build_forward_expand()]] - `calls` [INFERRED]
- [[ggml_cast()]] - `calls` [INFERRED]
- [[ggml_cont()]] - `calls` [INFERRED]
- [[ggml_cont_2d()]] - `calls` [INFERRED]
- [[ggml_flash_attn_ext()]] - `calls` [INFERRED]
- [[ggml_flash_attn_ext_add_sinks()]] - `calls` [INFERRED]
- [[ggml_flash_attn_ext_set_n_kv_max()]] - `calls` [INFERRED]
- [[ggml_mul_mat()]] - `calls` [INFERRED]
- [[ggml_permute()]] - `calls` [INFERRED]
- [[ggml_prec_set_acc()]] - `calls` [INFERRED]
- [[ggml_reshape_2d()]] - `calls` [INFERRED]
- [[ggml_reshape_4d()]] - `calls` [INFERRED]
- [[ggml_scale()]] - `calls` [INFERRED]
- [[ggml_soft_max_add_sinks()]] - `calls` [INFERRED]
- [[ggml_soft_max_ext()]] - `calls` [INFERRED]
- [[ggml_tanh()]] - `calls` [INFERRED]
- [[ggml_tensor_4]] - `references` [EXTRACTED]
- [[ggml_transpose()]] - `calls` [INFERRED]
- [[ggml_view_4d()]] - `calls` [INFERRED]
- [[llama-graph.cpp]] - `contains` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml__5
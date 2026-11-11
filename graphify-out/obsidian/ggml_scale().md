---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L3467"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml__5
---

# ggml_scale()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_acc_or_set()]] - `calls` [EXTRACTED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_scale_impl()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_mha()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_inp_embd()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_lora_mm()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_lora_mm_id()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_moe_ffn()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml__5
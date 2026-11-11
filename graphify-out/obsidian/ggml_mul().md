---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 5"
location: "L2275"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml__5
---

# ggml_mul()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_mul_impl()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_ffn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_lora_mm()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_lora_mm_id()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_moe_ffn()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_norm()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml__5
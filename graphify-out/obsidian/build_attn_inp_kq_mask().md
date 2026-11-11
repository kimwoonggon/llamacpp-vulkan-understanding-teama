---
source_file: "src/llama-graph.cpp"
type: "code"
community: "외부 참조 · 33"
location: "L29"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/외부_참조__33
---

# build_attn_inp_kq_mask()

## Connections
- [[build_attn_inp_k_dsa_impl()]] - `calls` [EXTRACTED]
- [[build_attn_inp_k_impl()]] - `calls` [EXTRACTED]
- [[build_attn_inp_kv_impl()]] - `calls` [EXTRACTED]
- [[ggml_context]] - `references` [EXTRACTED]
- [[ggml_new_tensor_4d()]] - `calls` [INFERRED]
- [[ggml_set_input()]] - `calls` [INFERRED]
- [[ggml_set_name()]] - `calls` [INFERRED]
- [[ggml_tensor_4]] - `references` [EXTRACTED]
- [[llama-graph.cpp]] - `contains` [EXTRACTED]
- [[llama_cparams]] - `references` [EXTRACTED]
- [[llama_kv_cache_context]] - `references` [EXTRACTED]
- [[llama_ubatch_1]] - `references` [EXTRACTED]
- [[llm_graph_contextbuild_attn_inp_k_dsa_iswa()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_inp_k_iswa()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_inp_kv_iswa()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_attn_inp_kv_msa()]] - `calls` [EXTRACTED]
- [[llm_graph_contextbuild_inp_mem_hybrid_iswa()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/외부_참조__33
---
source_file: "ggml/src/ggml-backend.cpp"
type: "code"
community: "llama-graph · 18"
location: "L183"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/llama-graph__18
---

# ggml_backend_buffer_is_host()

## Connections
- [[dsv4_set_kq_mask()]] - `calls` [INFERRED]
- [[ggml-backend.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_buffer_get_type()]] - `calls` [EXTRACTED]
- [[ggml_backend_buffer_t]] - `references` [EXTRACTED]
- [[ggml_backend_buft_is_host()]] - `calls` [EXTRACTED]
- [[ggml_backend_cpu_buffer_cpy_tensor()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_backend_id_from_cur()]] - `calls` [EXTRACTED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_copy()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_cpy_tensor_async()]] - `calls` [INFERRED]
- [[llama_model_baseload_tensors()]] - `calls` [INFERRED]
- [[llm_graph_input_attn_crossset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_attn_no_cacheset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_clsset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_meanset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_mem_hybridset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_mem_hybrid_iswaset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_mem_hybrid_kset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_out_idsset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_pos_bucketset_input()]] - `calls` [INFERRED]
- [[llm_graph_input_rsset_input()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/llama-graph__18
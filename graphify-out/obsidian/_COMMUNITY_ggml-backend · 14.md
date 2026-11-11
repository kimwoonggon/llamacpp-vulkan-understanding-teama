---
type: community
cohesion: 0.09
members: 45
---

# ggml-backend · 14

**Cohesion:** 0.09 - loosely connected
**Members:** 45 nodes

## Members
- [[fmt_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_name()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buft_name()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_supports_buft()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_supports_op()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_optimize()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_name()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_alloc_graph()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_alloc_splits()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_backend_from_buffer()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_backend_id()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_backend_id_from_cur()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_buffer_supported()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_buffer_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_buffer_type()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_n_backends()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_n_copies()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_n_splits()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_graph_compute()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_graph_compute_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_graph_inputs_grow()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_new()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_print_assignments()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_reserve()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_reserve_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_reset()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_set_eval_callback()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_set_if_supported()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_set_tensor_backend()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_split_graph()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_split_inputs_grow()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_synchronize()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_t]] - code
- [[ggml_backend_supports_buft()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_supports_op()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_graph_n_nodes()]] - code - ggml/src/ggml.c
- [[ggml_graph_node()]] - code - ggml/src/ggml.c
- [[ggml_is_view_op()]] - code - ggml/src/ggml-backend.cpp
- [[llama_contextgraph_get_cb()]] - code - src/llama-context.cpp
- [[llama_contextgraph_reserve()]] - code - src/llama-context.cpp
- [[llama_contextprocess_ubatch()]] - code - src/llama-context.cpp
- [[llama_contextsched_reserve()]] - code - src/llama-context.cpp
- [[llama_graph_n_input_tensors()]] - code - src/llama-context.cpp
- [[llama_memory_context_i]] - code
- [[llm_graph_cb]] - code

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-backend__14
SORT file.name ASC
```

## Connections to other communities
- 40 edges to [[_COMMUNITY_ggml-backend · 11]]
- 18 edges to [[_COMMUNITY_ggml-backend · 27]]
- 15 edges to [[_COMMUNITY_ggml-backend · 24]]
- 9 edges to [[_COMMUNITY_llama-context · 32]]
- 5 edges to [[_COMMUNITY_ggml-backend · 46]]
- 5 edges to [[_COMMUNITY_ggml · 34]]
- 5 edges to [[_COMMUNITY_llama-context · 4]]
- 4 edges to [[_COMMUNITY_ggml-vulkan · 17]]
- 3 edges to [[_COMMUNITY_ggml · 5]]
- 3 edges to [[_COMMUNITY_ggml · 2]]
- 2 edges to [[_COMMUNITY_ggml · 16]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 2 edges to [[_COMMUNITY_llama-graph · 31]]
- 2 edges to [[_COMMUNITY_ggml · 44]]
- 2 edges to [[_COMMUNITY_llama-context · 28]]
- 1 edge to [[_COMMUNITY_llama-graph · 18]]
- 1 edge to [[_COMMUNITY_llama-model · 61]]
- 1 edge to [[_COMMUNITY_ggml-backend · 19]]
- 1 edge to [[_COMMUNITY_llama-graph · 20]]
- 1 edge to [[_COMMUNITY_ggml · 6]]

## Top bridge nodes
- [[ggml_backend_sched_split_graph()]] - degree 25, connects to 8 communities
- [[ggml_backend_sched_new()]] - degree 13, connects to 6 communities
- [[ggml_backend_sched_print_assignments()]] - degree 9, connects to 4 communities
- [[ggml_backend_buft_name()]] - degree 7, connects to 4 communities
- [[ggml_backend_sched_get_buffer_size()]] - degree 7, connects to 4 communities
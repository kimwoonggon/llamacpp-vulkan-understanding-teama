---
type: community
cohesion: 0.12
members: 26
---

# ggml · 34

**Cohesion:** 0.12 - loosely connected
**Members:** 26 nodes

## Members
- [[dot-llama_io_read_device()]] - code - src/llama-context.cpp
- [[dot-llama_io_write_device()]] - code - src/llama-context.cpp
- [[ggml_aligned_free()]] - code - ggml/src/ggml.c
- [[ggml_aligned_malloc()]] - code - ggml/src/ggml.c
- [[ggml_backend_buffer_copy_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_copy()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_copy()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_memset()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_view_init()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_free()]] - code - ggml/src/ggml.c
- [[ggml_graph_get_grad_acc()]] - code - ggml/src/ggml.c
- [[ggml_graph_overhead()]] - code - ggml/src/ggml.c
- [[ggml_graph_overhead_custom()]] - code - ggml/src/ggml.c
- [[ggml_graph_reset()]] - code - ggml/src/ggml.c
- [[ggml_graph_size()]] - code - ggml/src/ggml.c
- [[ggml_init()]] - code - ggml/src/ggml.c
- [[ggml_set_zero()]] - code - ggml/src/ggml.c
- [[ggml_tensor_overhead()]] - code - ggml/src/ggml.c
- [[ggml_time_init()]] - code - ggml/src/ggml.c
- [[ggml_view_1d()]] - code - ggml/src/ggml.c
- [[graph_copy_init_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[llama_contextopt_epoch_iter()]] - code - src/llama-context.cpp
- [[llama_memory_buffers]] - code
- [[llm_graph_contextbuild_rwkv_token_shift_store()]] - code - src/llama-graph.cpp
- [[llm_graph_contextbuild_sampling()]] - code - src/llama-graph.cpp
- [[llm_graph_resultreset()]] - code - src/llama-graph.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml__34
SORT file.name ASC
```

## Connections to other communities
- 14 edges to [[_COMMUNITY_ggml-backend · 11]]
- 14 edges to [[_COMMUNITY_ggml · 2]]
- 8 edges to [[_COMMUNITY_llama-graph · 18]]
- 5 edges to [[_COMMUNITY_ggml-backend · 14]]
- 5 edges to [[_COMMUNITY_ggml · 44]]
- 5 edges to [[_COMMUNITY_ggml · 5]]
- 4 edges to [[_COMMUNITY_ggml-backend · 27]]
- 4 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 4 edges to [[_COMMUNITY_llama-context · 28]]
- 3 edges to [[_COMMUNITY_llama-context · 13]]
- 3 edges to [[_COMMUNITY_llama-graph · 20]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 10]]
- 2 edges to [[_COMMUNITY_llama-model · 61]]
- 2 edges to [[_COMMUNITY_llama-context · 30]]
- 1 edge to [[_COMMUNITY_ggml-backend · 46]]
- 1 edge to [[_COMMUNITY_ggml-vulkan · 8]]
- 1 edge to [[_COMMUNITY_llama-graph · 31]]
- 1 edge to [[_COMMUNITY_llama-graph · 60]]
- 1 edge to [[_COMMUNITY_ggml · 50]]
- 1 edge to [[_COMMUNITY_llama-context · 4]]
- 1 edge to [[_COMMUNITY_llama-context · 32]]
- 1 edge to [[_COMMUNITY_llama-context · 53]]
- 1 edge to [[_COMMUNITY_llama-model · 25]]

## Top bridge nodes
- [[llama_contextopt_epoch_iter()]] - degree 16, connects to 7 communities
- [[dot-llama_io_write_device()]] - degree 12, connects to 6 communities
- [[ggml_backend_tensor_copy()]] - degree 12, connects to 5 communities
- [[ggml_backend_graph_copy()]] - degree 12, connects to 4 communities
- [[dot-llama_io_read_device()]] - degree 11, connects to 4 communities
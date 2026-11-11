---
type: community
cohesion: 0.08
members: 49
---

# ggml-backend · 11

**Cohesion:** 0.08 - loosely connected
**Members:** 49 nodes

## Members
- [[dot-llama_io_write_host()]] - code - src/llama-context.cpp
- [[buffers]] - code - ggml/src/ggml-backend.cpp
- [[ggml-backend.cpp]] - code - ggml/src/ggml-backend.cpp
- [[ggml_alloc]] - concept
- [[ggml_backend_buffer_clear()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_alignment()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_alloc_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_base()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_max_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_get_type()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_i]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_init_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_is_multi_buffer()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_reset()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_set_usage()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buffer_t]] - code
- [[ggml_backend_buft_get_alignment()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buft_get_alloc_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_buft_get_max_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_clear()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_cpy_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_free_buffer()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_get_base()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_get_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_memset_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_cpu_buffer_set_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_offload_op()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_event_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_get_alignment()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_get_max_size()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_copy_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_multi_buffer_alloc_buffer()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_multi_buffer_clear()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_multi_buffer_context]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_multi_buffer_free_buffer()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_multi_buffer_set_usage()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_offload_op()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_alloc()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_get()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_get_2d()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_dup_tensor_layout()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_op_alloc_size_may_expand()]] - code - ggml/src/ggml-backend.cpp
- [[graph_copy_dup_tensor()]] - code - ggml/src/ggml-backend.cpp
- [[llama_modelmemory_breakdown()]] - code - src/llama-model.cpp
- [[n_buffers]] - code - ggml/src/ggml-backend.cpp
- [[sysctl]] - concept

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-backend__11
SORT file.name ASC
```

## Connections to other communities
- 40 edges to [[_COMMUNITY_ggml-backend · 14]]
- 28 edges to [[_COMMUNITY_ggml-backend · 27]]
- 26 edges to [[_COMMUNITY_ggml-backend · 46]]
- 25 edges to [[_COMMUNITY_ggml-backend · 24]]
- 14 edges to [[_COMMUNITY_ggml · 34]]
- 7 edges to [[_COMMUNITY_ggml · 2]]
- 6 edges to [[_COMMUNITY_llama-graph · 18]]
- 5 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 4 edges to [[_COMMUNITY_외부 참조 · 26]]
- 3 edges to [[_COMMUNITY_vulkan-shaders-gen · 9]]
- 1 edge to [[_COMMUNITY_ggml-backend · 19]]
- 1 edge to [[_COMMUNITY_ggml-backend · 63]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 40]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 23]]
- 1 edge to [[_COMMUNITY_llama-context · 13]]
- 1 edge to [[_COMMUNITY_ggml · 6]]
- 1 edge to [[_COMMUNITY_llama-graph · 31]]
- 1 edge to [[_COMMUNITY_llama-context · 30]]
- 1 edge to [[_COMMUNITY_외부 참조 · 15]]
- 1 edge to [[_COMMUNITY_llama-model · 36]]
- 1 edge to [[_COMMUNITY_llama-model · 61]]

## Top bridge nodes
- [[ggml-backend.cpp]] - degree 154, connects to 13 communities
- [[ggml_backend_buffer_t]] - degree 34, connects to 5 communities
- [[ggml_backend_tensor_get()]] - degree 8, connects to 5 communities
- [[ggml_backend_buffer_get_type()]] - degree 11, connects to 4 communities
- [[llama_modelmemory_breakdown()]] - degree 6, connects to 3 communities
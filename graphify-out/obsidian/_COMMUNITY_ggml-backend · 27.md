---
type: community
cohesion: 0.11
members: 30
---

# ggml-backend · 27

**Cohesion:** 0.11 - loosely connected
**Members:** 30 nodes

## Members
- [[buffer_view]] - code
- [[copy_tensor_async_rows()]] - code - src/llama-context.cpp
- [[ggml_backend_buffer_get_usage()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_compare_graph_backend()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_eval_callback]] - code
- [[ggml_backend_event_record()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_event_synchronize()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_event_t]] - code
- [[ggml_backend_event_wait()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_compute()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_compute_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_plan_compute()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_plan_create()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_plan_free()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_graph_plan_t]] - code
- [[ggml_backend_guid()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_compute_splits()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_backend()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_sched_get_tensor_backend()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_synchronize()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_t]] - code
- [[ggml_backend_tensor_copy_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_get_2d_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_get_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_set_2d_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_tensor_set_async()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_graph_view()]] - code - ggml/src/ggml.c
- [[ggml_guid_t]] - code
- [[llama_contextextract_layer_inputs()]] - code - src/llama-context.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-backend__27
SORT file.name ASC
```

## Connections to other communities
- 28 edges to [[_COMMUNITY_ggml-backend · 11]]
- 18 edges to [[_COMMUNITY_ggml-backend · 14]]
- 8 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 5 edges to [[_COMMUNITY_ggml-backend · 24]]
- 4 edges to [[_COMMUNITY_ggml · 34]]
- 4 edges to [[_COMMUNITY_llama-context · 32]]
- 2 edges to [[_COMMUNITY_llama-graph · 18]]
- 2 edges to [[_COMMUNITY_ggml · 2]]
- 2 edges to [[_COMMUNITY_ggml-backend · 19]]
- 2 edges to [[_COMMUNITY_llama-context · 28]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 8]]
- 2 edges to [[_COMMUNITY_llama-context · 4]]
- 2 edges to [[_COMMUNITY_llama-context · 13]]
- 1 edge to [[_COMMUNITY_ggml-backend · 46]]
- 1 edge to [[_COMMUNITY_외부 참조 · 83]]

## Top bridge nodes
- [[ggml_backend_t]] - degree 36, connects to 6 communities
- [[ggml_backend_sched_compute_splits()]] - degree 17, connects to 6 communities
- [[copy_tensor_async_rows()]] - degree 11, connects to 6 communities
- [[ggml_backend_sched_get_tensor_backend()]] - degree 10, connects to 5 communities
- [[ggml_backend_tensor_get_async()]] - degree 11, connects to 4 communities
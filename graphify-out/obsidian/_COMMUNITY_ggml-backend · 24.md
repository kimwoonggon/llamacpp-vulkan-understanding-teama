---
type: community
cohesion: 0.12
members: 32
---

# ggml-backend · 24

**Cohesion:** 0.12 - loosely connected
**Members:** 32 nodes

## Members
- [[buft_list_t]] - code
- [[ggml_backend_buft_get_device()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_backend_reg()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_buffer_from_host_ptr()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_buffer_type()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_description()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_get_props()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_init()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_memory()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_name()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_dev_t]] - code
- [[ggml_backend_dev_type()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_event_new()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_get_default_buffer_type()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_get_device()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_reg_dev_count()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_reg_dev_get()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_reg_get_proc_address()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_reg_name()]] - code - ggml/src/ggml-backend.cpp
- [[ggml_backend_reg_t]] - code
- [[ggml_get_first_tensor()]] - code - ggml/src/ggml.c
- [[ggml_get_max_tensor_size()]] - code - ggml/src/ggml.c
- [[ggml_get_next_tensor()]] - code - ggml/src/ggml.c
- [[ggml_status]] - code - ggml/src/ggml-vulkan/ggml-vulkan-common.h
- [[llama_contextgraph_compute()]] - code - src/llama-context.cpp
- [[llama_contextllama_context()]] - code - src/llama-context.cpp
- [[llama_contextresolve_fused_ops()]] - code - src/llama-context.cpp
- [[llama_contextset_abort_callback()]] - code - src/llama-context.cpp
- [[llama_device]] - code
- [[llama_model_baseload_tensors()]] - code - src/llama-model.cpp
- [[make_cpu_buft_list()]] - code - src/llama-model.cpp
- [[make_gpu_buft_list()]] - code - src/llama-model.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-backend__24
SORT file.name ASC
```

## Connections to other communities
- 25 edges to [[_COMMUNITY_ggml-backend · 11]]
- 15 edges to [[_COMMUNITY_ggml-backend · 14]]
- 9 edges to [[_COMMUNITY_ggml-backend · 46]]
- 5 edges to [[_COMMUNITY_ggml-backend · 27]]
- 5 edges to [[_COMMUNITY_llama-context · 4]]
- 4 edges to [[_COMMUNITY_외부 참조 · 15]]
- 3 edges to [[_COMMUNITY_ggml-vulkan · 17]]
- 3 edges to [[_COMMUNITY_ggml · 2]]
- 3 edges to [[_COMMUNITY_llama-model · 61]]
- 2 edges to [[_COMMUNITY_llama-context · 32]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 3]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 2 edges to [[_COMMUNITY_llama-context · 28]]
- 2 edges to [[_COMMUNITY_llama-model · 36]]
- 1 edge to [[_COMMUNITY_llama-graph · 18]]
- 1 edge to [[_COMMUNITY_ggml · 55]]
- 1 edge to [[_COMMUNITY_llama-model · 52]]
- 1 edge to [[_COMMUNITY_llama-model · 25]]
- 1 edge to [[_COMMUNITY_llama-model · 70]]

## Top bridge nodes
- [[llama_contextllama_context()]] - degree 21, connects to 9 communities
- [[llama_model_baseload_tensors()]] - degree 21, connects to 7 communities
- [[ggml_backend_get_default_buffer_type()]] - degree 9, connects to 4 communities
- [[ggml_backend_dev_t]] - degree 17, connects to 3 communities
- [[make_cpu_buft_list()]] - degree 11, connects to 3 communities
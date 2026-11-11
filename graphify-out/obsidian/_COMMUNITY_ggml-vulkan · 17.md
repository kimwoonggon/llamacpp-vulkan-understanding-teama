---
type: community
cohesion: 0.09
members: 39
---

# ggml-vulkan · 17

**Cohesion:** 0.09 - loosely connected
**Members:** 39 nodes

## Members
- [[dot-print_timings()]] - code - ggml/src/ggml-vulkan/ggml-vulkan-types.h
- [[ArrayProxy]] - code
- [[Fence_3]] - code
- [[SubmitInfo]] - code
- [[find_first_set()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[get_subgroup_size()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml-vulkan-common.h]] - code - ggml/src/ggml-vulkan/ggml-vulkan-common.h
- [[ggml_backend_graph_optimize_params]] - code - ggml/src/ggml-vulkan/ggml-vulkan-common.h
- [[ggml_backend_vk_event_record()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_backend_vk_free()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_backend_vk_get_device_pci_id()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_backend_vk_graph_compute()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_cgraph]] - code - ggml/src/ggml-vulkan/ggml-vulkan-common.h
- [[ggml_get_unary_op()]] - code - ggml/src/ggml.c
- [[ggml_op]] - code - ggml/src/ggml-vulkan/ggml-vulkan-common.h
- [[ggml_op_name()]] - code - ggml/src/ggml.c
- [[ggml_vk_can_fuse_rms_norm_mul_rope()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse_ssm_conv()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse_topk_moe()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse_topk_qsa()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_cleanup()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_compute_forward()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_ctx_end()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_debug_labelggml_vk_debug_label()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_node_flops()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_match_ops()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_print_device_fault_info()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_print_device_lost_info()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_print_node_list()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_submit()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_submit_transfer_ctx()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_synchronize()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_wait_for_fence()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vulkan_push_constants]] - concept
- [[initializer_list_1]] - code
- [[string_1]] - code
- [[vk_perf_loggerget_node_fusion_name()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[vk_queue_handle_synchronizedsubmit()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[vk_queue_handle_unsynchronizedsubmit()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-vulkan__17
SORT file.name ASC
```

## Connections to other communities
- 45 edges to [[_COMMUNITY_ggml-vulkan · 3]]
- 17 edges to [[_COMMUNITY_ggml-vulkan · 8]]
- 16 edges to [[_COMMUNITY_ggml-vulkan · 10]]
- 11 edges to [[_COMMUNITY_ggml-vulkan · 12]]
- 10 edges to [[_COMMUNITY_ggml-vulkan-types · 7]]
- 5 edges to [[_COMMUNITY_ggml · 16]]
- 4 edges to [[_COMMUNITY_ggml-backend · 14]]
- 3 edges to [[_COMMUNITY_ggml-backend · 24]]
- 2 edges to [[_COMMUNITY_ggml-vulkan · 51]]
- 2 edges to [[_COMMUNITY_ggml-vulkan-types · 23]]
- 2 edges to [[_COMMUNITY_ggml · 2]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 1]]
- 1 edge to [[_COMMUNITY_외부 참조 · 15]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 29]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 45]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 47]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 69]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 67]]
- 1 edge to [[_COMMUNITY_ggml · 55]]
- 1 edge to [[_COMMUNITY_ggml · 22]]

## Top bridge nodes
- [[ggml_cgraph]] - degree 16, connects to 7 communities
- [[ggml_get_unary_op()]] - degree 13, connects to 7 communities
- [[ggml_backend_vk_graph_compute()]] - degree 31, connects to 6 communities
- [[ggml_op_name()]] - degree 12, connects to 5 communities
- [[ggml_vk_can_fuse_topk_moe()]] - degree 7, connects to 5 communities
---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 17"
location: "L13888"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__17
---

# ggml_backend_vk_graph_compute()

## Connections
- [[dot-log_timing()]] - `calls` [INFERRED]
- [[dot-print_timings()]] - `calls` [INFERRED]
- [[find_first_set()]] - `calls` [EXTRACTED]
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_t_1]] - `references` [EXTRACTED]
- [[ggml_cgraph]] - `references` [EXTRACTED]
- [[ggml_get_unary_op()]] - `calls` [INFERRED]
- [[ggml_status]] - `references` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_rms_norm_mul_rope()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_rope_set_rows()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_snake()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_ssm_conv()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_topk_moe()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse_topk_qsa()]] - `calls` [EXTRACTED]
- [[ggml_vk_compute_forward()]] - `calls` [EXTRACTED]
- [[ggml_vk_ctx_end()]] - `calls` [EXTRACTED]
- [[ggml_vk_fuse_multi_add()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_compute_ctx()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_node_flops()]] - `calls` [EXTRACTED]
- [[ggml_vk_is_empty()]] - `calls` [EXTRACTED]
- [[ggml_vk_preallocate_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_print_device_fault_info()]] - `calls` [EXTRACTED]
- [[ggml_vk_print_node_list()]] - `calls` [EXTRACTED]
- [[ggml_vk_submit()]] - `calls` [EXTRACTED]
- [[ggml_vk_submit_transfer_ctx()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_synchronize()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensors_overlap()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__17
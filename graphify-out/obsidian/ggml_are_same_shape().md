---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 10"
location: "L1564"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__10
---

# ggml_are_same_shape()

## Connections
- [[dot-llama_io_write_device()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_add_rel_pos_impl()]] - `calls` [EXTRACTED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_compute_backward()]] - `calls` [EXTRACTED]
- [[ggml_count_equal()]] - `calls` [EXTRACTED]
- [[ggml_cross_entropy_loss()]] - `calls` [EXTRACTED]
- [[ggml_cross_entropy_loss_back()]] - `calls` [EXTRACTED]
- [[ggml_glu_impl()]] - `calls` [EXTRACTED]
- [[ggml_opt_step_adamw()]] - `calls` [EXTRACTED]
- [[ggml_opt_step_sgd()]] - `calls` [EXTRACTED]
- [[ggml_ssm_scan()]] - `calls` [EXTRACTED]
- [[ggml_vk_can_fuse()]] - `calls` [INFERRED]
- [[ggml_vk_can_fuse_snake()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss()]] - `calls` [INFERRED]
- [[ggml_vk_cross_entropy_loss_back()]] - `calls` [INFERRED]
- [[ggml_vk_fuse_multi_add()]] - `calls` [INFERRED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_opt_step_adamw()]] - `calls` [INFERRED]
- [[ggml_vk_op_get_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_snake_dispatch_fused()]] - `calls` [INFERRED]
- [[ggml_vk_unary_mul()]] - `calls` [INFERRED]
- [[llm_graph_contextbuild_inp_embd()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__10
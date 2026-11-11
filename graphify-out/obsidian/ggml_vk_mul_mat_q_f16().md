---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L6040"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_mul_mat_q_f16()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_blck_size()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_tensor_1]] - `references` [EXTRACTED]
- [[ggml_type_name()]] - `calls` [INFERRED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_align_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_cpy_to_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_dim01_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_64b_indexing_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_mul_mat_mat_pipeline_map()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_quantize_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_to_fp16()]] - `calls` [EXTRACTED]
- [[ggml_vk_guess_matmul_pipeline_align_map()]] - `calls` [EXTRACTED]
- [[ggml_vk_guess_matmul_pipeline_map()]] - `calls` [EXTRACTED]
- [[ggml_vk_guess_split_k()]] - `calls` [EXTRACTED]
- [[ggml_vk_matmul()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_vk_preallocate_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_quantize_q8_1()]] - `calls` [EXTRACTED]
- [[ggml_vk_subbuffer()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]
- [[vk_tensor_offset()]] - `calls` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
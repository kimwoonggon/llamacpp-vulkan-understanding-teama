---
source_file: "ggml/src/ggml-vulkan/ggml-vulkan.cpp"
type: "code"
community: "ggml-vulkan · 12"
location: "L6393"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml-vulkan__12
---

# ggml_vk_mul_mat_vec_q_f16()

## Connections
- [[ggml-vulkan.cpp]] - `contains` [EXTRACTED]
- [[ggml_backend_vk_context]] - `references` [EXTRACTED]
- [[ggml_blck_size()]] - `calls` [INFERRED]
- [[ggml_is_contiguous()]] - `calls` [INFERRED]
- [[ggml_nbytes()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_pipeline_request_descriptor_sets()]] - `calls` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [INFERRED]
- [[ggml_vk_align_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_cpy_to_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_dim01_contiguous()]] - `calls` [EXTRACTED]
- [[ggml_vk_dispatch_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_64b_indexing_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_dequantize_mul_mat_vec()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_quantize_pipeline()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_to_fp16()]] - `calls` [EXTRACTED]
- [[ggml_vk_mul_mat()]] - `calls` [EXTRACTED]
- [[ggml_vk_preallocate_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_quantize_q8_1()]] - `calls` [EXTRACTED]
- [[ggml_vk_should_use_mmvq()]] - `calls` [EXTRACTED]
- [[ggml_vk_sync_buffers()]] - `calls` [EXTRACTED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [EXTRACTED]
- [[vk_context]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml-vulkan__12
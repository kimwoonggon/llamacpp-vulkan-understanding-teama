---
type: community
cohesion: 0.13
members: 46
---

# ggml-vulkan · 12

**Cohesion:** 0.13 - loosely connected
**Members:** 46 nodes

## Members
- [[get_misalign_bytes()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_are_same_stride()]] - code - ggml/src/ggml.c
- [[ggml_backend_vk_device_supports_op()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_blck_size()]] - code - ggml/src/ggml.c
- [[ggml_flash_attn_back()]] - code - ggml/src/ggml.c
- [[ggml_gated_delta_net()]] - code - ggml/src/ggml.c
- [[ggml_is_contiguous()]] - code - ggml/src/ggml.c
- [[ggml_is_contiguous_rows()]] - code - ggml/src/ggml.c
- [[ggml_is_contiguously_allocated()]] - code - ggml/src/ggml.c
- [[ggml_is_permuted()]] - code - ggml/src/ggml.c
- [[ggml_is_quantized()]] - code - ggml/src/ggml.c
- [[ggml_is_transposed()]] - code - ggml/src/ggml.c
- [[ggml_nbytes()]] - code - ggml/src/ggml.c
- [[ggml_nbytes_pad()]] - code - ggml/src/ggml.c
- [[ggml_type_name()]] - code - ggml/src/ggml.c
- [[ggml_type_size()]] - code - ggml/src/ggml.c
- [[ggml_vk_align_size()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse_rms_norm_set_rows()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_can_fuse_rope_set_rows()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_concat()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_concat_supported()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_concat_unit_size()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_cpy_to_contiguous()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_dim01_contiguous()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_64b_indexing_pipeline()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_cpy_pipeline()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_dequantize_mul_mat_vec()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_dequantize_mul_mat_vec_id()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_quantize_pipeline()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_get_to_fp16()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_guess_matmul_pipeline_align_map()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_guess_matmul_pipeline_map()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_guess_split_k()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_matmul_id()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_id()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_id_q_f16()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_q_f16()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_vec_p021_f16_f32()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_mul_mat_vec_q_f16()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_quantize_q8_1()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[ggml_vk_use_mul_mat_vec_id()]] - code - ggml/src/ggml-vulkan/ggml-vulkan.cpp
- [[vk_pipeline]] - code - ggml/src/ggml-vulkan/ggml-vulkan-types.h

## Live Query (requires Dataview plugin)

```dataview
TABLE source_file, type FROM #community/ggml-vulkan__12
SORT file.name ASC
```

## Connections to other communities
- 66 edges to [[_COMMUNITY_ggml-vulkan · 10]]
- 59 edges to [[_COMMUNITY_ggml-vulkan · 8]]
- 50 edges to [[_COMMUNITY_ggml-vulkan · 3]]
- 29 edges to [[_COMMUNITY_ggml-vulkan-types · 7]]
- 21 edges to [[_COMMUNITY_ggml · 2]]
- 12 edges to [[_COMMUNITY_ggml-vulkan · 51]]
- 12 edges to [[_COMMUNITY_ggml · 5]]
- 11 edges to [[_COMMUNITY_ggml-vulkan · 17]]
- 11 edges to [[_COMMUNITY_ggml · 22]]
- 8 edges to [[_COMMUNITY_ggml-backend · 27]]
- 6 edges to [[_COMMUNITY_ggml · 6]]
- 5 edges to [[_COMMUNITY_ggml-backend · 11]]
- 5 edges to [[_COMMUNITY_ggml-vulkan-types · 66]]
- 4 edges to [[_COMMUNITY_llama-graph · 18]]
- 4 edges to [[_COMMUNITY_ggml · 34]]
- 4 edges to [[_COMMUNITY_ggml · 16]]
- 4 edges to [[_COMMUNITY_llama-context · 28]]
- 3 edges to [[_COMMUNITY_ggml · 39]]
- 2 edges to [[_COMMUNITY_ggml-backend · 14]]
- 2 edges to [[_COMMUNITY_ggml-backend · 24]]
- 2 edges to [[_COMMUNITY_ggml · 50]]
- 1 edge to [[_COMMUNITY_외부 참조 · 26]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 42]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 48]]
- 1 edge to [[_COMMUNITY_ggml-vulkan-types · 1]]
- 1 edge to [[_COMMUNITY_외부 참조 · 15]]
- 1 edge to [[_COMMUNITY_ggml · 64]]
- 1 edge to [[_COMMUNITY_ggml · 55]]
- 1 edge to [[_COMMUNITY_llama-graph · 31]]

## Top bridge nodes
- [[ggml_nbytes()]] - degree 41, connects to 12 communities
- [[ggml_type_size()]] - degree 56, connects to 11 communities
- [[ggml_is_contiguous()]] - degree 44, connects to 11 communities
- [[ggml_is_quantized()]] - degree 19, connects to 8 communities
- [[vk_pipeline]] - degree 22, connects to 7 communities
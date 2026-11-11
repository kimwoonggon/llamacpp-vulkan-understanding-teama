---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1298"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_nbytes()

## Connections
- [[dot-llama_io_read_device()]] - `calls` [INFERRED]
- [[copy_tensor_async_rows()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_backend_buft_get_alloc_size()]] - `calls` [INFERRED]
- [[ggml_backend_cpu_buffer_cpy_tensor()]] - `calls` [INFERRED]
- [[ggml_backend_sched_compute_splits()]] - `calls` [INFERRED]
- [[ggml_backend_sched_print_assignments()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_copy()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get_2d()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get_2d_async()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_get_async()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_memset()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_set()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_set_2d()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_set_2d_async()]] - `calls` [INFERRED]
- [[ggml_backend_tensor_set_async()]] - `calls` [INFERRED]
- [[ggml_backend_vk_buffer_cpy_tensor()]] - `calls` [INFERRED]
- [[ggml_backend_vk_buffer_type_get_alloc_size()]] - `calls` [INFERRED]
- [[ggml_backend_vk_cpy_tensor_async()]] - `calls` [INFERRED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_blck_size()]] - `calls` [EXTRACTED]
- [[ggml_get_max_tensor_size()]] - `calls` [EXTRACTED]
- [[ggml_is_contiguously_allocated()]] - `calls` [EXTRACTED]
- [[ggml_nbytes_pad()]] - `calls` [EXTRACTED]
- [[ggml_new_tensor_impl()]] - `calls` [EXTRACTED]
- [[ggml_set_zero()]] - `calls` [EXTRACTED]
- [[ggml_type_size()]] - `calls` [EXTRACTED]
- [[ggml_vk_build_graph()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_nc_f16_f32()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_p021_f16_f32()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_vec_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_tensor_subbuffer()]] - `calls` [INFERRED]
- [[ggml_vk_tensors_overlap()]] - `calls` [INFERRED]
- [[llama_contextencode()]] - `calls` [INFERRED]
- [[llama_contextextract_layer_inputs()]] - `calls` [INFERRED]
- [[llm_graph_input_cross_embdset_input()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
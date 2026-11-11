---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1358"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_is_quantized()

## Connections
- [[get_fa_tuning_params_coopmat2()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_add_cast_impl()]] - `calls` [EXTRACTED]
- [[ggml_backend_buft_get_alloc_size()]] - `calls` [INFERRED]
- [[ggml_backend_vk_device_supports_op()]] - `calls` [INFERRED]
- [[ggml_vk_concat()]] - `calls` [INFERRED]
- [[ggml_vk_concat_supported()]] - `calls` [INFERRED]
- [[ggml_vk_concat_unit_size()]] - `calls` [INFERRED]
- [[ggml_vk_cpy()]] - `calls` [INFERRED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_id_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32_wkv()]] - `calls` [INFERRED]
- [[ggml_vk_use_mul_mat_vec_id()]] - `calls` [INFERRED]
- [[llama_contextllama_context()]] - `calls` [INFERRED]
- [[llama_init_from_model()]] - `calls` [INFERRED]
- [[llama_model_get_tok_embd()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
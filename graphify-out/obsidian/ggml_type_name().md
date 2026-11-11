---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml-vulkan · 12"
location: "L1352"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml-vulkan__12
---

# ggml_type_name()

## Connections
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_graph_dump_dot()]] - `calls` [EXTRACTED]
- [[ggml_vk_get_cpy_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_get_quantize_pipeline()]] - `calls` [INFERRED]
- [[ggml_vk_matmul_int_shmem_support()]] - `calls` [INFERRED]
- [[ggml_vk_matmul_shmem_support()]] - `calls` [INFERRED]
- [[ggml_vk_mul_mat_q_f16()]] - `calls` [INFERRED]
- [[ggml_vk_op_f32()]] - `calls` [INFERRED]
- [[llama_graph_n_input_tensors()]] - `calls` [INFERRED]
- [[llama_init_from_model()]] - `calls` [INFERRED]
- [[llama_model_get_tok_embd()]] - `calls` [INFERRED]
- [[vk_perf_loggerget_node_fusion_name()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml-vulkan__12
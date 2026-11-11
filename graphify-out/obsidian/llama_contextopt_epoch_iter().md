---
source_file: "src/llama-context.cpp"
type: "code"
community: "ggml · 34"
location: "L3532"
tags:
  - graphify/code
  - graphify/EXTRACTED
  - community/ggml__34
---

# llama_context::opt_epoch_iter()

## Connections
- [[ctx_type_to_graph_type()]] - `calls` [EXTRACTED]
- [[ggml_backend_tensor_set()]] - `calls` [INFERRED]
- [[ggml_free()]] - `calls` [INFERRED]
- [[ggml_graph_overhead_custom()]] - `calls` [INFERRED]
- [[ggml_graph_size()]] - `calls` [INFERRED]
- [[ggml_init()]] - `calls` [INFERRED]
- [[ggml_opt_dataset_t]] - `references` [EXTRACTED]
- [[ggml_opt_epoch_callback]] - `references` [EXTRACTED]
- [[ggml_opt_result_t]] - `references` [EXTRACTED]
- [[ggml_set_zero()]] - `calls` [INFERRED]
- [[ggml_tensor_overhead()]] - `calls` [INFERRED]
- [[llama-context.cpp]] - `contains` [EXTRACTED]
- [[llama_batch]] - `references` [EXTRACTED]
- [[llama_model_n_ctx_train()]] - `calls` [INFERRED]
- [[llama_token]] - `references` [EXTRACTED]
- [[vector_3]] - `references` [EXTRACTED]

#graphify/code #graphify/EXTRACTED #community/ggml__34
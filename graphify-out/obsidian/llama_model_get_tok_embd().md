---
source_file: "src/llama-model.cpp"
type: "code"
community: "ggml · 2"
location: "L3326"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml__2
---

# llama_model_get_tok_embd()

## Connections
- [[ggml_backend_tensor_get()]] - `calls` [INFERRED]
- [[ggml_bf16_to_fp32_row()]] - `calls` [INFERRED]
- [[ggml_fp16_to_fp32_row()]] - `calls` [INFERRED]
- [[ggml_get_type_traits()]] - `calls` [INFERRED]
- [[ggml_is_quantized()]] - `calls` [INFERRED]
- [[ggml_nelements()]] - `calls` [INFERRED]
- [[ggml_type_name()]] - `calls` [INFERRED]
- [[llama-model.cpp]] - `contains` [EXTRACTED]

#graphify/code #graphify/INFERRED #community/ggml__2
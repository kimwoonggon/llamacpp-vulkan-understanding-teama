---
source_file: "ggml/src/ggml.c"
type: "code"
community: "ggml · 34"
location: "L1611"
tags:
  - graphify/code
  - graphify/INFERRED
  - community/ggml__34
---

# ggml_init()

## Connections
- [[dot-llama_io_read_device()]] - `calls` [INFERRED]
- [[dot-llama_io_write_device()]] - `calls` [INFERRED]
- [[buft_supported()]] - `calls` [INFERRED]
- [[ggml.c]] - `contains` [EXTRACTED]
- [[ggml_aligned_malloc()]] - `calls` [EXTRACTED]
- [[ggml_backend_graph_copy()]] - `calls` [INFERRED]
- [[ggml_backend_sched_split_graph()]] - `calls` [INFERRED]
- [[ggml_time_init()]] - `calls` [EXTRACTED]
- [[llama_contextopt_epoch_iter()]] - `calls` [INFERRED]
- [[llm_graph_resultreset()]] - `calls` [INFERRED]

#graphify/code #graphify/INFERRED #community/ggml__34
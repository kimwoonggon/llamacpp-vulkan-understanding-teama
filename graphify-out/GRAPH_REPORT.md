# Graphify 코드 위치 연결

2026-11-11, Graphify 0.9.105를 실제 D드라이브 소스에 실행했습니다.
기준: e6ab7c1a41054a888ada952eab4c886444c2f5ad
범위: 16개 선택 파일. 다른 모델/백엔드와 생성된 빌드 파일은 제외했습니다.
자동 AST: 2409 노드, 6385 관계. Shader 파일 5개와 명시적 참조 5개는 수동 소스 확인으로 보완했습니다.

## 화면 보완

Graphify 기본 HTML은 파일 경로만 보여 줍니다. 동일한 native 네트워크에 코드 위치 패널을 추가했습니다.
Graphify의 시작 행을 추가 Tree-sitter 구문 범위와 대조하고 실제 소스의 줄 번호를 표시합니다.
함수/타입 정의, 파일 노드, 소스 지점, 정의 미확인을 구분합니다. 파일 노드를 함수 정의로 표시하지 않습니다.
코드는 추출 시점의 스냅샷입니다. 로컬 소스를 수정하면 04-rebuild-graphify.cmd를 실행하세요.

- 코드 연결: 2177개 노드
- 정의 위치 미확인: 326개 노드 (외부 타입/참조 포함). 가능한 호출/참조 위치만 표시합니다.
- 전역 선은 무방향 정적 관계입니다. 자동 추출 관계는 실제 GPU 런타임 경로를 증명하지 않습니다.
- C++ 매크로/함수 포인터/가상 호출은 누락될 수 있습니다. ggml-vulkan.cpp 파서 경고는 extraction.log에 보존합니다.
- GLSL/.comp 내부 함수는 자동 분석하지 않았습니다.
- 이전에 이 PC에서 실행한 Vulkan/CPU 로그는 ../logs/에 있지만 이 그래프의 추출 입력은 소스뿐입니다.
- 자동 AST/군집화의 LLM 토큰 0. 이 패널 작성에 사용한 대화 토큰은 측정되지 않았습니다.

# Graph Report - corpus  (2026-11-11)

## Corpus Check
- 11 files · ~161,954 words
- Verdict: corpus is large enough that graph structure adds value.
- Unclassified: 5 file(s) not represented in the graph (top: .comp 3, .glsl 2)

## Summary
- 2503 nodes · 5987 edges · 83 communities (79 shown, 4 thin omitted)
- Extraction: 88% EXTRACTED · 12% INFERRED · 0% AMBIGUOUS · INFERRED: 727 edges (avg confidence: 0.85)
- Token cost: 0 input · 0 output

## Graph Freshness
- Built from commit: `e6ab7c1a`
- Run `git rev-parse HEAD` and compare to check if the graph is stale.
- Run `graphify update .` after code changes (no API cost).

## Community Hubs (Navigation)
- ggml-vulkan-types · 1
- ggml · 2
- ggml-vulkan · 3
- llama-context · 4
- ggml · 5
- ggml · 6
- ggml-vulkan-types · 7
- ggml-vulkan · 8
- vulkan-shaders-gen · 9
- ggml-vulkan · 10
- ggml-backend · 11
- ggml-vulkan · 12
- llama-context · 13
- ggml-backend · 14
- 외부 참조 · 15
- ggml · 16
- ggml-vulkan · 17
- llama-graph · 18
- ggml-backend · 19
- llama-graph · 20
- ggml-vulkan-types · 21
- ggml · 22
- ggml-vulkan-types · 23
- ggml-backend · 24
- llama-model · 25
- 외부 참조 · 26
- ggml-backend · 27
- llama-context · 28
- ggml-vulkan-types · 29
- llama-context · 30
- llama-graph · 31
- llama-context · 32
- 외부 참조 · 33
- ggml · 34
- llama-context · 35
- llama-model · 36
- ggml-vulkan-types · 37
- ggml-vulkan-types · 38
- ggml · 39
- ggml-vulkan-types · 40
- ggml-vulkan-types · 41
- ggml-vulkan-types · 42
- ggml-vulkan-types · 43
- ggml · 44
- ggml-vulkan-types · 45
- ggml-backend · 46
- ggml-vulkan-types · 47
- ggml-vulkan-types · 48
- ggml-vulkan-types · 49
- ggml · 50
- ggml-vulkan · 51
- llama-model · 52
- llama-context · 53
- llama-model · 54
- ggml · 55
- ggml-vulkan-types · 56
- ggml-vulkan-types · 57
- llama-graph · 58
- ggml · 59
- llama-graph · 60
- llama-model · 61
- 외부 참조 · 62
- ggml-backend · 63
- ggml · 64
- ggml-vulkan-types · 65
- ggml-vulkan-types · 66
- ggml-vulkan-types · 67
- ggml-vulkan-types · 68
- ggml-vulkan-types · 69
- llama-model · 70
- ggml-vulkan-types · 71
- llama-model · 72
- ggml-vulkan-types · 73
- ggml-vulkan-types · 74
- llama-context · 75
- 외부 참조 · 76
- llama-context · 77
- ggml-vulkan-types · 78
- ggml-vulkan-types · 79
- ggml-vulkan-types · 80
- 외부 참조 · 81
- 외부 참조 · 82
- 외부 참조 · 83

## God Nodes (most connected - your core abstractions)
1. `vk_device_struct` - 364 edges
2. `ggml_backend_vk_context` - 224 edges
3. `vk_context` - 117 edges
4. `ggml_vk_build_graph()` - 104 edges
5. `ggml_nelements()` - 67 edges
6. `ggml_type_size()` - 56 edges
7. `ggml_vk_op_f32()` - 48 edges
8. `ggml_compute_backward()` - 48 edges
9. `ggml_vk_dispatch_pipeline()` - 44 edges
10. `ggml_is_contiguous()` - 44 edges

## Surprising Connections (you probably didn't know these)
- `main()` --calls--> `llama_model_decoder_start_token()`  [INFERRED]
  examples/simple/simple.cpp → src/llama-model.cpp
- `main()` --calls--> `llama_model_default_params()`  [INFERRED]
  examples/simple/simple.cpp → src/llama-model.cpp
- `main()` --calls--> `llama_model_free()`  [INFERRED]
  examples/simple/simple.cpp → src/llama-model.cpp
- `main()` --calls--> `llama_model_get_vocab()`  [INFERRED]
  examples/simple/simple.cpp → src/llama-model.cpp
- `main()` --calls--> `llama_model_has_encoder()`  [INFERRED]
  examples/simple/simple.cpp → src/llama-model.cpp

## Import Cycles
- None detected.

## Communities (83 total, 4 thin omitted)

### Community 0 - "ggml-vulkan-types · 1"
Cohesion: 0.01
Nodes (332): vk_device_struct, add_rms_fusion, all_pipelines, allow_sysmem_fallback, architecture, async_use_transfer_queue, bf16, buffer_device_address (+324 more)

### Community 1 - "ggml · 2"
Cohesion: 0.02
Nodes (88): ggml_abort(), ggml_abs_inplace(), ggml_bf16_to_fp32(), ggml_bf16_to_fp32_row(), ggml_can_fuse_subgraph_ext(), ggml_ceil_inplace(), ggml_dsv4_hc_pre(), ggml_dsv4_hc_pre_gated() (+80 more)

### Community 2 - "ggml-vulkan · 3"
Cohesion: 0.04
Nodes (101): deferred_memcpy(), fa_block_bytes(), get_fa_spec_constants(), ggml_backend_buffer_is_vk(), ggml_backend_device_i, ggml_backend_is_vk(), ggml_backend_reg_i, ggml_backend_vk_buffer_clear() (+93 more)

### Community 3 - "llama-context · 4"
Cohesion: 0.04
Nodes (42): llama_attach_threadpool(), llama_context::attach_threadpool(), llama_copy_state_data(), llama_detach_threadpool(), llama_get_ctx_other(), llama_get_embeddings(), llama_get_embeddings_ith(), llama_get_embeddings_layer_inp() (+34 more)

### Community 4 - "ggml · 5"
Cohesion: 0.06
Nodes (68): ggml_add(), ggml_build_forward_expand(), ggml_cast(), ggml_clamp(), ggml_cont(), ggml_cont_impl(), ggml_conv_1d(), ggml_conv_1d_dw() (+60 more)

### Community 5 - "ggml · 6"
Cohesion: 0.04
Nodes (73): ggml_add_id(), ggml_add_rel_pos(), ggml_add_rel_pos_impl(), ggml_add_rel_pos_inplace(), ggml_clamp_impl(), ggml_clamp_inplace(), ggml_cos(), ggml_cos_impl() (+65 more)

### Community 6 - "ggml-vulkan-types · 7"
Cohesion: 0.03
Nodes (65): ggml_pipeline_allocate_descriptor_sets(), ggml_vk_conv_select_shape(), ggml_vk_get_max_buffer_range(), ggml_vk_make_rope_constants(), ggml_vk_rms_norm(), ggml_vk_rms_norm_finish(), ggml_vk_rms_num_partials(), ggml_vk_rms_partials_size() (+57 more)

### Community 7 - "ggml-vulkan · 8"
Cohesion: 0.11
Nodes (65): ggml_is_empty(), ggml_nelements(), ggml_vk_acc(), ggml_vk_add(), ggml_vk_add1(), ggml_vk_add_id(), ggml_vk_argmax(), ggml_vk_build_graph() (+57 more)

### Community 8 - "vulkan-shaders-gen · 9"
Cohesion: 0.07
Nodes (31): acquire_compile_slot(), basename(), compile_count_guard, create_directory(), directory_exists(), execute_command(), is_iq_quant(), is_k_quant() (+23 more)

### Community 9 - "ggml-vulkan · 10"
Cohesion: 0.11
Nodes (47): ggml_are_same_shape(), ggml_cross_entropy_loss_back(), ggml_is_scalar(), ggml_nrows(), ggml_opt_step_adamw(), ggml_opt_step_sgd(), ggml_set_loss(), ggml_vk_dispatch_pipeline() (+39 more)

### Community 10 - "ggml-backend · 11"
Cohesion: 0.08
Nodes (44): ggml_backend_buffer_clear(), ggml_backend_buffer_free(), ggml_backend_buffer_get_alignment(), ggml_backend_buffer_get_alloc_size(), ggml_backend_buffer_get_base(), ggml_backend_buffer_get_max_size(), ggml_backend_buffer_get_size(), ggml_backend_buffer_get_type() (+36 more)

### Community 11 - "ggml-vulkan · 12"
Cohesion: 0.13
Nodes (46): ggml_are_same_stride(), ggml_blck_size(), ggml_flash_attn_back(), ggml_gated_delta_net(), ggml_is_contiguous(), ggml_is_contiguous_rows(), ggml_is_contiguously_allocated(), ggml_is_permuted() (+38 more)

### Community 12 - "llama-context · 13"
Cohesion: 0.06
Nodes (25): llama_context::state_read_data(), llama_context::state_seq_read_data(), llama_context::state_seq_save_file(), llama_io_read_device, buf_size, ptr, rinfos, size_read (+17 more)

### Community 13 - "ggml-backend · 14"
Cohesion: 0.09
Nodes (42): fmt_size(), ggml_backend_buffer_name(), ggml_backend_buft_name(), ggml_backend_dev_supports_buft(), ggml_backend_dev_supports_op(), ggml_backend_graph_optimize(), ggml_backend_name(), ggml_backend_sched_alloc_graph() (+34 more)

### Community 14 - "외부 참조 · 15"
Cohesion: 0.05
Nodes (6): llama_meta_device_get_split_state(), llama_model_base::create_tensor_gate_up_exps(), llama_model_base::create_tensor_qkv(), llama_model::build_graph(), llama_model_meta_key_str(), llama_model::split_mode()

### Community 15 - "ggml · 16"
Cohesion: 0.06
Nodes (42): ggml_abs(), ggml_acc(), ggml_acc_impl(), ggml_acc_inplace(), ggml_acc_or_set(), ggml_add1_or_set(), ggml_add_cast(), ggml_add_cast_impl() (+34 more)

### Community 16 - "ggml-vulkan · 17"
Cohesion: 0.09
Nodes (31): ggml_get_unary_op(), ggml_op_name(), ggml_backend_graph_optimize_params, ggml_cgraph, ggml_op, find_first_set(), get_subgroup_size(), ggml_backend_vk_event_record() (+23 more)

### Community 17 - "llama-graph · 18"
Cohesion: 0.08
Nodes (34): ggml_backend_buffer_is_host(), ggml_backend_tensor_set(), ggml_backend_tensor_set_2d(), ggml_element_size(), dsv4_set_i32(), dsv4_set_i64(), llama_relative_position_bucket(), llm_graph_input_attn_cross::set_input() (+26 more)

### Community 18 - "ggml-backend · 19"
Cohesion: 0.05
Nodes (35): ggml_backend_sched, backends, bufts, callback_eval, callback_eval_user_data, context_buffer, context_buffer_size, ctx (+27 more)

### Community 19 - "llama-graph · 20"
Cohesion: 0.11
Nodes (29): ggml_set_output(), can_reuse_kq_mask(), dsv4_can_reuse_raw_kq_mask(), llm_graph_context::build_cvec(), llm_graph_context::cb(), llm_graph_context::llm_graph_context(), llm_graph_input_attn_k::can_reuse(), llm_graph_input_attn_k::can_reuse_impl() (+21 more)

### Community 20 - "ggml-vulkan-types · 21"
Cohesion: 0.07
Nodes (33): VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV, cooperativeMatrixDecodeVector, pNext, sType, VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR, internallySynchronizedQueues, pNext, sType (+25 more)

### Community 21 - "ggml · 22"
Cohesion: 0.07
Nodes (33): ggml_argsort(), ggml_argsort_top_k(), ggml_build_backward_expand(), ggml_calc_conv_output_size(), ggml_calc_conv_transpose_output_size(), ggml_calc_pool_output_size(), ggml_can_mul_mat(), ggml_can_out_prod() (+25 more)

### Community 22 - "ggml-vulkan-types · 23"
Cohesion: 0.07
Nodes (26): ggml_vk_create_binary_semaphore(), ggml_vk_create_timeline_semaphore(), ggml_vk_garbage_collector, contexts, events, semaphores, tl_semaphores, vk_event (+18 more)

### Community 23 - "ggml-backend · 24"
Cohesion: 0.12
Nodes (28): ggml_backend_buft_get_device(), ggml_backend_dev_backend_reg(), ggml_backend_dev_buffer_from_host_ptr(), ggml_backend_dev_buffer_type(), ggml_backend_dev_description(), ggml_backend_dev_get_props(), ggml_backend_dev_init(), ggml_backend_dev_memory() (+20 more)

### Community 24 - "llama-model · 25"
Cohesion: 0.07
Nodes (29): llama_free_model(), llama_model_chat_template(), llama_model_decoder_start_token(), llama_model_dflash_selector_top_k(), llama_model_free(), llama_model_get_vocab(), llama_model_has_decoder(), llama_model_has_encoder() (+21 more)

### Community 25 - "외부 참조 · 26"
Cohesion: 0.07
Nodes (10): DispatchLoaderDynamic, ggml_vk_func_t, GpuPipelineConfig, arch, default_subgroup_size, pipelines, matmul_tile_selector_t, vk_buffer_ref (+2 more)

### Community 26 - "ggml-backend · 27"
Cohesion: 0.11
Nodes (24): ggml_backend_buffer_get_usage(), ggml_backend_compare_graph_backend(), ggml_backend_event_record(), ggml_backend_event_synchronize(), ggml_backend_event_wait(), ggml_backend_free(), ggml_backend_graph_compute(), ggml_backend_graph_compute_async() (+16 more)

### Community 27 - "llama-context · 28"
Cohesion: 0.09
Nodes (18): main(), print_usage(), ggml_time_us(), llama_context_default_params(), llama_context::encode(), llama_context::opt_epoch(), llama_context::perf_get_data(), llama_context::perf_reset() (+10 more)

### Community 28 - "ggml-vulkan-types · 29"
Cohesion: 0.08
Nodes (19): ggml_vk_create_aliased_queue(), ggml_vk_create_cmd_buffer(), ggml_vk_create_queue(), ggml_vk_get_or_create_cmd_buffer(), vk_command_buffer, buf, in_use, use_counter (+11 more)

### Community 29 - "llama-context · 30"
Cohesion: 0.07
Nodes (20): llama_context::state_seq_write_data(), llama_context::state_write_data(), llama_io_write_device, buf_size, ptr, size_written, winfos, llama_io_write_dummy (+12 more)

### Community 30 - "llama-graph · 31"
Cohesion: 0.12
Nodes (22): ggml_arange(), ggml_count_equal(), ggml_cross_entropy_loss(), ggml_new_tensor_1d(), ggml_new_tensor_2d(), ggml_set_input(), ggml_set_name(), ggml_sum() (+14 more)

### Community 31 - "llama-context · 32"
Cohesion: 0.08
Nodes (18): ctx_type_to_graph_type(), llama_context::adapters_lora_are_same(), llama_context::decode(), llama_context::get_embeddings_layer_inp(), llama_context::get_gf_res_prev(), llama_context::get_gf_res_reserve(), llama_context::graph_params(), llama_context::memory_breakdown() (+10 more)

### Community 32 - "외부 참조 · 33"
Cohesion: 0.13
Nodes (12): build_attn_inp_k_dsa_impl(), build_attn_inp_k_impl(), build_attn_inp_kq_mask(), build_attn_inp_kv_impl(), llm_graph_context::build_attn_inp_k(), llm_graph_context::build_attn_inp_k_dsa(), llm_graph_context::build_attn_inp_k_dsa_iswa(), llm_graph_context::build_attn_inp_k_iswa() (+4 more)

### Community 33 - "ggml · 34"
Cohesion: 0.12
Nodes (23): ggml_backend_buffer_copy_tensor(), ggml_backend_graph_copy(), ggml_backend_tensor_copy(), ggml_backend_tensor_memset(), ggml_backend_view_init(), graph_copy_init_tensor(), ggml_aligned_free(), ggml_aligned_malloc() (+15 more)

### Community 34 - "llama-context · 35"
Cohesion: 0.14
Nodes (21): llama_context::get_embeddings_seq(), llama_context::get_memory(), llama_context::state_seq_get_data(), llama_context::state_seq_get_size(), llama_context::state_seq_set_data(), llama_get_embeddings_seq(), llama_memory_can_shift(), llama_memory_clear() (+13 more)

### Community 35 - "llama-model · 36"
Cohesion: 0.08
Nodes (17): llama_model::ftype(), llama_model::impl, cpu_buft_list, ctxs_bufs, desc_str, dev_input, dev_layer, dev_output (+9 more)

### Community 36 - "ggml-vulkan-types · 37"
Cohesion: 0.10
Nodes (13): vk_buffer_struct, bda_addr, buffer, device, device_memory, memory_property_flags, ptr, size (+5 more)

### Community 37 - "ggml-vulkan-types · 38"
Cohesion: 0.10
Nodes (19): deferred_memset(), vk_context_struct, debug_labels, exit_tensor_idx, in_memcpys, memsets, out_memcpys, p (+11 more)

### Community 38 - "ggml · 39"
Cohesion: 0.13
Nodes (18): ggml_argmax(), ggml_calc_conv_transpose_1d_output_size(), ggml_col2im_1d(), ggml_cont_1d(), ggml_cont_2d(), ggml_cont_3d(), ggml_cont_4d(), ggml_conv_transpose_1d() (+10 more)

### Community 39 - "ggml-vulkan-types · 40"
Cohesion: 0.12
Nodes (17): format_size(), ggml_backend_vk_buffer_context, dev_buffer, device, name, ggml_backend_vk_buffer_type_context, device, name (+9 more)

### Community 40 - "ggml-vulkan-types · 41"
Cohesion: 0.11
Nodes (12): vk_instance_t, debug_utils_support, device_indices, device_supports_membudget, devices, instance, pfn_vkCmdBeginDebugUtilsLabelEXT, pfn_vkCmdEndDebugUtilsLabelEXT (+4 more)

### Community 41 - "ggml-vulkan-types · 42"
Cohesion: 0.11
Nodes (14): vk_pipeline_struct, align, compile_pending, compiled, initialized, layout, name, next (+6 more)

### Community 42 - "ggml-vulkan-types · 43"
Cohesion: 0.11
Nodes (17): vk_fa_pipeline_state, aligned, Bc, Br, D_split, f32acc, flags, HSK (+9 more)

### Community 43 - "ggml · 44"
Cohesion: 0.13
Nodes (17): ggml_build_forward_impl(), ggml_build_forward_order(), ggml_build_forward_select(), ggml_graph_clear(), ggml_graph_cpy(), ggml_graph_dup(), ggml_graph_nbytes(), ggml_hash_set_new() (+9 more)

### Community 44 - "ggml-vulkan-types · 45"
Cohesion: 0.12
Nodes (7): vk_queue_handle, device, device_submit_mutex, queue, vk_queue_handle_synchronized, mutex, vk_queue_handle_unsynchronized

### Community 45 - "ggml-backend · 46"
Cohesion: 0.18
Nodes (15): ggml_backend_alloc_buffer(), ggml_backend_buffer_init(), ggml_backend_buft_alloc_buffer(), ggml_backend_buft_is_host(), ggml_backend_cpu_buffer_from_ptr(), ggml_backend_cpu_buffer_from_ptr_type(), ggml_backend_cpu_buffer_from_ptr_type_get_name(), ggml_backend_cpu_buffer_type() (+7 more)

### Community 46 - "ggml-vulkan-types · 47"
Cohesion: 0.12
Nodes (13): get_device_architecture(), ggml_vk_intel_shader_core_count(), ggml_vk_khr_cooperative_matrix_support(), vk_device_architecture, AMD_GCN, AMD_RDNA1, AMD_RDNA2, AMD_RDNA3 (+5 more)

### Community 47 - "ggml-vulkan-types · 48"
Cohesion: 0.12
Nodes (15): CompileTask, disable_robustness, entrypoint, parameter_count, pipeline, require_full_subgroups, required_subgroup_size, specialization_constants (+7 more)

### Community 48 - "ggml-vulkan-types · 49"
Cohesion: 0.12
Nodes (14): vk_conv3d_pipeline_state, aligned, d0, d1, d2, KD, KH, KW (+6 more)

### Community 49 - "ggml · 50"
Cohesion: 0.13
Nodes (14): ggml_custom_4d(), ggml_custom_inplace(), ggml_interpolate(), ggml_interpolate_impl(), ggml_new_tensor_4d(), ggml_pad(), ggml_pad_circular(), ggml_pad_ext() (+6 more)

### Community 50 - "ggml-vulkan · 51"
Cohesion: 0.30
Nodes (14): get_fa_pipeline_state(), get_fa_tuning_params(), get_fa_tuning_params_coopmat1(), get_fa_tuning_params_coopmat2(), get_fa_tuning_params_scalar(), ggml_vk_fa_scalar_uses_mmq(), ggml_vk_fa_type_needs_shmem(), ggml_vk_flash_attn_coopmat_shmem_support() (+6 more)

### Community 51 - "llama-model · 52"
Cohesion: 0.13
Nodes (9): llama_get_memory(), llama_model_base::create_tensor(), llama_model::create_memory(), llama_model::get_rope_factors(), llama_model::get_rope_freq_base(), llama_model::get_rope_freq_scale(), llama_model::get_tensor(), llama_model_n_layer() (+1 more)

### Community 52 - "llama-context · 53"
Cohesion: 0.15
Nodes (14): llama_context::get_sampled_candidates_ith(), llama_context::get_sampled_token_ith(), llama_context::get_sampled_tokens(), llama_context::state_load_file(), llama_context::state_save_file(), llama_context::state_seq_load_file(), llama_get_sampled_candidates_ith(), llama_get_sampled_token_ith() (+6 more)

### Community 53 - "llama-model · 54"
Cohesion: 0.15
Nodes (9): llama_expert_gating_func_name(), llama_model::arch_name(), llama_model::desc(), llama_model::print_info(), llama_model::type_name(), llama_rope_scaling_type_from_string(), llama_rope_scaling_type_name(), llm_ffn_op_type_from_string() (+1 more)

### Community 54 - "ggml · 55"
Cohesion: 0.21
Nodes (11): ggml_fopen(), ggml_get_name(), ggml_graph_dump_dot(), ggml_graph_dump_dot_leaf_edge(), ggml_graph_dump_dot_node_edge(), ggml_graph_find(), ggml_graph_get_grad(), ggml_graph_get_parent() (+3 more)

### Community 55 - "ggml-vulkan-types · 56"
Cohesion: 0.17
Nodes (10): vk_conv2d_pipeline_state, aligned, d0, d1, KH, KW, p0, p1 (+2 more)

### Community 56 - "ggml-vulkan-types · 57"
Cohesion: 0.17
Nodes (11): vk_fa_tuning_params, block_cols, block_rows, d_split, disable_subgroups, limit_occupancy_shmem, path, row_split (+3 more)

### Community 57 - "llama-graph · 58"
Cohesion: 0.24
Nodes (8): dsv4_can_reuse_comp_input(), dsv4_can_reuse_kq_mask(), dsv4_can_reuse_tensor_1d(), dsv4_compress_debug(), dsv4_plan_positions(), dsv4_set_comp_inputs(), dsv4_set_kq_mask(), llm_graph_input_dsv4::set_input()

### Community 58 - "ggml · 59"
Cohesion: 0.18
Nodes (11): ggml_rope(), ggml_rope_custom(), ggml_rope_custom_inplace(), ggml_rope_ext(), ggml_rope_ext_back(), ggml_rope_ext_inplace(), ggml_rope_impl(), ggml_rope_inplace() (+3 more)

### Community 59 - "llama-graph · 60"
Cohesion: 0.20
Nodes (6): build_rs_inp_impl(), llm_graph_context::build_inp_mem_hybrid(), llm_graph_context::build_inp_mem_hybrid_iswa(), llm_graph_context::build_inp_mem_hybrid_k(), llm_graph_context::build_rs_inp(), llm_graph_context::build_rwkv_token_shift_load()

### Community 60 - "llama-model · 61"
Cohesion: 0.22
Nodes (9): buft_supported(), layer_dev, buft_list, dev, llama_model::dev_layer(), llama_model::dev_output(), llama_model_get_device(), llama_model::select_buft() (+1 more)

### Community 61 - "외부 참조 · 62"
Cohesion: 0.25
Nodes (3): llama_model_qwen2::build_arch_graph(), llama_model_qwen2::load_arch_hparams(), llama_model_qwen2::load_arch_tensors()

### Community 62 - "ggml-backend · 63"
Cohesion: 0.25
Nodes (8): ggml_backend_sched_split, backend_id, graph, i_end, i_start, inputs, inputs_capacity, n_inputs

### Community 63 - "ggml · 64"
Cohesion: 0.25
Nodes (8): ggml_add1(), ggml_add1_impl(), ggml_add1_inplace(), ggml_is_padded_1d(), ggml_scale_bias(), ggml_scale_bias_inplace(), ggml_scale_impl(), ggml_scale_inplace()

### Community 64 - "ggml-vulkan-types · 65"
Cohesion: 0.25
Nodes (8): rms_norm_mode, RMS_NORM_COUNT, RMS_NORM_MUL, RMS_NORM_MUL_ADD, RMS_NORM_MUL_ADD_MUL, RMS_NORM_MUL_ROPE, RMS_NORM_MUL_ROPE_VIEW_SET_ROWS, RMS_NORM_VIEW_SET_ROWS

### Community 65 - "ggml-vulkan-types · 66"
Cohesion: 0.33
Nodes (6): ggml_vk_get_mul_mat_mat_f16acc(), ggml_vk_get_mul_mat_mat_pipeline_map(), vk_matmul_pipeline_pair, align, aligned, unaligned

### Community 66 - "ggml-vulkan-types · 67"
Cohesion: 0.33
Nodes (3): ggml_vk_debug_label, qhandle, subctx

### Community 67 - "ggml-vulkan-types · 68"
Cohesion: 0.29
Nodes (5): vk_matmul_pipeline_key, f16acc, mul_mat_id, type_a, type_b

### Community 68 - "ggml-vulkan-types · 69"
Cohesion: 0.29
Nodes (7): topk_moe_mode, TOPK_MOE_COUNT, TOPK_MOE_EARLY_SOFTMAX, TOPK_MOE_EARLY_SOFTMAX_NORM, TOPK_MOE_LATE_SOFTMAX, TOPK_MOE_SIGMOID_NORM_BIAS, TOPK_MOE_SQRT_SOFTPLUS_NORM_BIAS

### Community 69 - "llama-model · 70"
Cohesion: 0.29
Nodes (5): llama_model_base::load_hparams(), llama_model_base::load_stats(), llama_model_base::load_swa_pattern(), llama_model_base::load_vocab(), llama_model_rope_type()

### Community 70 - "ggml-vulkan-types · 71"
Cohesion: 0.33
Nodes (6): vk_conv_shapes, CONV_SHAPE_128x128, CONV_SHAPE_32x256, CONV_SHAPE_64x128, CONV_SHAPE_64x32, CONV_SHAPE_COUNT

### Community 71 - "llama-model · 72"
Cohesion: 0.47
Nodes (4): llama_model_create(), llama_model_default_params(), llama_model::llama_model(), llama_model_mapping()

### Community 72 - "ggml-vulkan-types · 73"
Cohesion: 0.40
Nodes (5): shader_reduction_mode, SHADER_REDUCTION_MODE_COUNT, SHADER_REDUCTION_MODE_HYBRID, SHADER_REDUCTION_MODE_SHMEM, SHADER_REDUCTION_MODE_SUBGROUP

### Community 73 - "ggml-vulkan-types · 74"
Cohesion: 0.40
Nodes (3): vk_solve_tri_pipeline_state, K, N

### Community 74 - "llama-context · 75"
Cohesion: 0.40
Nodes (4): llm_fused_op_probe, n_tokens_per_seq, name, op

### Community 76 - "llama-context · 77"
Cohesion: 0.50
Nodes (3): ggml_set_param(), llama_context::opt_init(), llama_set_param()

### Community 77 - "ggml-vulkan-types · 78"
Cohesion: 0.50
Nodes (4): dmmv_wg_sizes, DMMV_WG_SIZE_COUNT, DMMV_WG_SIZE_LARGE, DMMV_WG_SIZE_SUBGROUP

### Community 78 - "ggml-vulkan-types · 79"
Cohesion: 0.50
Nodes (4): FaCodePath, FA_COOPMAT1, FA_COOPMAT2, FA_SCALAR

### Community 79 - "ggml-vulkan-types · 80"
Cohesion: 0.50
Nodes (4): vk_conv_block_size, CRS, K, NPQ

## Knowledge Gaps
- **720 isolated node(s):** `buffers`, `n_buffers`, `backend_id`, `i_start`, `i_end` (+715 more)
  These have ≤1 connection - possible missing edges. (Counts symbols only; 1009 node(s) total have ≤1 connection when file, concept and rationale nodes are included.)
- **4 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `vk_device_struct` connect `ggml-vulkan-types · 1` to `ggml-vulkan-types · 66`, `ggml-vulkan-types · 68`, `ggml-vulkan-types · 37`, `ggml-vulkan-types · 7`, `ggml-vulkan-types · 40`, `vulkan-shaders-gen · 9`, `ggml-vulkan-types · 74`, `ggml-vulkan-types · 43`, `ggml-vulkan · 12`, `ggml-vulkan-types · 45`, `ggml-vulkan-types · 47`, `ggml-vulkan · 17`, `ggml-vulkan-types · 49`, `ggml-vulkan-types · 23`, `ggml-vulkan-types · 56`, `외부 참조 · 26`, `ggml-vulkan-types · 29`?**
  _High betweenness centrality (0.227) - this node is a cross-community bridge._
- **Are the 8 inferred relationships involving `ggml_vk_build_graph()` (e.g. with `ggml_get_glu_op()` and `ggml_get_unary_op()`) actually correct?**
  _`ggml_vk_build_graph()` has 8 INFERRED edges - model-reasoned connections that need verification._
- **What connects `buffers`, `n_buffers`, `backend_id` to the rest of the system?**
  _720 weakly-connected nodes found - possible missing edges._
- **Should `ggml-vulkan-types · 1` be split into smaller, more focused modules?**
  _Cohesion score 0.0058823529411764705 - nodes in this community are weakly interconnected._
- **Why does `ggml_backend_vk_context` connect `ggml-vulkan-types · 7` to `ggml-vulkan-types · 65`, `ggml-vulkan-types · 66`, `ggml-vulkan · 3`, `ggml-vulkan-types · 69`, `ggml-vulkan · 8`, `ggml-vulkan-types · 40`, `ggml-vulkan · 10`, `ggml-vulkan-types · 42`, `ggml-vulkan · 12`, `ggml-vulkan · 17`, `ggml-vulkan · 51`, `ggml-vulkan-types · 23`, `외부 참조 · 26`, `ggml-vulkan-types · 29`?**
  _High betweenness centrality (0.155) - this node is a cross-community bridge._
- **Should `ggml · 2` be split into smaller, more focused modules?**
  _Cohesion score 0.01943185779017079 - nodes in this community are weakly interconnected._
- **Why does `ggml_backend_sched` connect `ggml-backend · 19` to `ggml-backend · 11`, `ggml-backend · 27`, `ggml-backend · 46`?**
  _High betweenness centrality (0.054) - this node is a cross-community bridge._
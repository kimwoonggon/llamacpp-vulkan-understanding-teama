#include "llama.h"
#include <clocale>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

static void print_usage(int, char ** argv) {
    printf("\nexample usage:\n");
    printf("\n    %s -m model.gguf [-n n_predict] [-ngl n_gpu_layers] [prompt]\n", argv[0]);
    printf("\n");
}

int main(int argc, char ** argv) {
    std::setlocale(LC_NUMERIC, "C");

    // -m: 로드할 GGUF 파일 경로
    std::string model_path;
    // 옵션 뒤에 붙인 문자열: 생성의 시작점이 되는 프롬프트
    std::string prompt = "Hello my name is";
    // -ngl: GPU에 배치할 모델 레이어 수
    int ngl = 99;
    // -n: 생성할 최대 토큰 수
    int n_predict = 32;

    // argv[1]부터 옵션을 읽는다. -m은 경로, -n과 -ngl은 정수로 저장한다.

    {
        int i = 1;
        for (; i < argc; i++) {
            if (strcmp(argv[i], "-m") == 0) {
                if (i + 1 < argc) {
                    model_path = argv[++i];
                } else {
                    print_usage(argc, argv);
                    return 1;
                }
            } else if (strcmp(argv[i], "-n") == 0) {
                if (i + 1 < argc) {
                    try {
                        n_predict = std::stoi(argv[++i]);
                    } catch (...) {
                        print_usage(argc, argv);
                        return 1;
                    }
                } else {
                    print_usage(argc, argv);
                    return 1;
                }
            } else if (strcmp(argv[i], "-ngl") == 0) {
                if (i + 1 < argc) {
                    try {
                        ngl = std::stoi(argv[++i]);
                    } catch (...) {
                        print_usage(argc, argv);
                        return 1;
                    }
                } else {
                    print_usage(argc, argv);
                    return 1;
                }
            } else {
                // 첫 일반 인자부터 남은 인자를 공백으로 이어 프롬프트를 만든다.
                break;
            }
        }
        if (model_path.empty()) {
            print_usage(argc, argv);
            return 1;
        }
        if (i < argc) {
            prompt = argv[i++];
            for (; i < argc; i++) {
                prompt += " ";
                prompt += argv[i];
            }
        }
    }


    // 사용 가능한 백엔드를 찾아 등록한다. 인자와 반환값은 없다.
    ggml_backend_load_all();


    // 기본 로드 설정을 받아 GPU에 배치할 레이어 수만 ngl로 지정한다.
    llama_model_params model_params = llama_model_default_params();
    model_params.n_gpu_layers = ngl;
    // GGUF 로드 | 파일 경로(model_path), 로드 설정(model_params) -> 모델 포인터. 실패하면 NULL.
    llama_model * model = llama_model_load_from_file(model_path.c_str(), model_params);

    if (model == NULL) {
        fprintf(stderr , "%s: error: unable to load model\n" , __func__);  // stderr에 현재 함수명(__func__)과 오류를 쓴다. 성공 시 쓴 문자 수를 반환한다.
        return 1;
    }
    // 어휘 조회 | model -> 모델이 소유한 vocab. 토큰화와 텍스트 복원에 함께 쓴다.
    const llama_vocab * vocab = llama_model_get_vocab(model);

    // 토큰 수 조회 | vocab, 입력 텍스트, 바이트 수, NULL, 용량 0 -> 필요한 개수의 음수. 앞의 -로 양수화한다.
    // 두 true는 순서대로 모델 설정에 따른 시작/끝 토큰 추가와 입력 문자열 속 특수 토큰 인식을 허용한다.
    const int n_prompt = -llama_tokenize(vocab, prompt.c_str(), prompt.size(), NULL, 0, true, true);

    // 토큰화 | n_prompt칸을 만든다. data()는 쓸 주소, size()는 칸 수. ID는 벡터에 쓰고 개수를 반환한다.
    std::vector<llama_token> prompt_tokens(n_prompt);
    if (llama_tokenize(vocab, prompt.c_str(), prompt.size(), prompt_tokens.data(), prompt_tokens.size(), true, true) < 0) {
        fprintf(stderr, "%s: error: failed to tokenize the prompt\n", __func__);
        return 1;
    }


    // 문맥 기본값 조회 | 인자 없음 -> ctx_params. 아래에서 이번 실행의 용량과 측정 옵션을 정한다.
    llama_context_params ctx_params = llama_context_default_params();
    // 마지막에 생성한 토큰은 다시 입력하지 않으므로 요청 길이에서 1을 뺀다.
    ctx_params.n_ctx = n_prompt + n_predict - 1;
    // 한 번의 decode에 프롬프트 전체를 넣을 수 있는 배치 크기.
    ctx_params.n_batch = n_prompt;

    ctx_params.no_perf = false;
    // 실행 문맥 생성 | model(가중치), ctx_params(설정) -> KV 캐시와 출력 점수를 관리하는 ctx. 실패하면 NULL.
    llama_context * ctx = llama_init_from_model(model, ctx_params);

    if (ctx == NULL) {
        fprintf(stderr , "%s: error: failed to create the llama_context\n" , __func__);
        return 1;
    }


    // 샘플러 준비 | 기본 설정 sparams를 얻고, 그 설정으로 선택 규칙을 담을 빈 체인 smpl을 만든다.
    auto sparams = llama_sampler_chain_default_params();
    sparams.no_perf = false;
    llama_sampler * smpl = llama_sampler_chain_init(sparams);
    // 최고 점수 토큰을 고를 규칙을 만들고 smpl에 등록한다. 등록 함수의 반환형은 void다.
    llama_sampler_chain_add(smpl, llama_sampler_init_greedy());

    // 입력 프롬프트 복원 | vocab, id, buf, 용량(128바이트) -> 텍스트는 buf에 쓰고 바이트 수는 n으로 반환한다.
    // 끝의 0은 앞 공백을 유지하고 true는 특수 토큰도 표시한다. 공간이 부족하면 필요한 크기의 음수를 반환한다.
    for (auto id : prompt_tokens) {
        char buf[128];
        int n = llama_token_to_piece(vocab, id, buf, sizeof(buf), 0, true);
        if (n < 0) {
            fprintf(stderr, "%s: error: failed to convert token to piece\n", __func__);
            return 1;
        }
        std::string s(buf, n);  // buf의 앞 n바이트로 문자열을 만든다. 널 종료 문자가 없어도 된다.
        printf("%s", s.c_str());  // s.c_str()의 문자열을 콘솔에 출력한다. 성공 시 쓴 문자 수를 반환한다.
    }


    // 첫 배치 | 토큰 배열 주소와 개수 -> 원래 배열을 참조하는 batch. 첫 decode는 프롬프트 전체를 받는다.
    llama_batch batch = llama_batch_get_one(prompt_tokens.data(), prompt_tokens.size());
    // 인코더 필요 여부 | model -> bool. 디코더 전용 Qwen2.5에서는 false다.
    if (llama_model_has_encoder(model)) {
        if (llama_encode(ctx, batch)) {  // ctx와 입력 배치로 인코더 실행. 결과는 ctx에 남고 성공 시 0을 반환한다.
            fprintf(stderr, "%s : failed to eval\n", __func__);
            return 1;
        }
        // 시작 토큰 조회 | model -> 디코더의 첫 토큰 ID. 지정값이 없으면 vocab에서 BOS(문장 시작) ID를 얻는다.
        llama_token decoder_start_token_id = llama_model_decoder_start_token(model);
        if (decoder_start_token_id == LLAMA_TOKEN_NULL) {
            decoder_start_token_id = llama_vocab_bos(vocab);
        }
        // 시작 토큰의 주소와 개수 1 -> 디코더에 넘길 첫 배치.
        batch = llama_batch_get_one(&decoder_start_token_id, 1);
    }


    // 시작 시각 측정 | 인자 없음 -> 마이크로초 단위 정수. 루프 종료 시각과의 차이로 소요 시간을 구한다.
    const auto t_main_start = ggml_time_us();
    int n_decode = 0;
    llama_token new_token_id;

    for (int n_pos = 0; n_pos + batch.n_tokens < n_prompt + n_predict; ) {
        // 배치 평가 | ctx(실행 상태), batch(토큰 묶음) -> ctx의 KV 캐시와 다음 토큰 점수(logits)를 갱신. 반환값 0은 성공.
        if (llama_decode(ctx, batch)) {
            fprintf(stderr, "%s : failed to eval, return code %d\n", __func__, 1);
            return 1;
        }

        n_pos += batch.n_tokens;

        // 다음 토큰 선택 | smpl(선택 규칙), ctx(후보 점수), -1(마지막 출력 위치) -> 토큰 ID 하나.
        {
            new_token_id = llama_sampler_sample(smpl, ctx, -1);

            // 생성 종료 검사 | vocab, new_token_id -> 종료 토큰이면 true. 출력 전에 루프를 끝낸다.
            if (llama_vocab_is_eog(vocab, new_token_id)) {
                break;
            }
            // 생성 결과 복원 | 방금 선택한 ID -> 텍스트는 buf, 쓴 바이트 수는 n.
            char buf[128];
            int n = llama_token_to_piece(vocab, new_token_id, buf, sizeof(buf), 0, true);
            if (n < 0) {
                fprintf(stderr, "%s: error: failed to convert token to piece\n", __func__);
                return 1;
            }
            std::string s(buf, n);
            printf("%s", s.c_str());
            fflush(stdout);  // stdout의 대기 중인 출력을 즉시 내보낸다. 성공 0, 실패 EOF.

            // 다음 배치 | new_token_id의 주소와 개수 1 -> 다음 decode에 넣을 토큰 한 개짜리 batch.
            batch = llama_batch_get_one(&new_token_id, 1);

            n_decode += 1;
        }
    }

    printf("\n");

    const auto t_main_end = ggml_time_us();

    fprintf(stderr, "%s: decoded %d tokens in %.2f s, speed: %.2f t/s\n",
            __func__, n_decode, (t_main_end - t_main_start) / 1000000.0f, n_decode / ((t_main_end - t_main_start) / 1000000.0f));

    fprintf(stderr, "\n");
    llama_perf_sampler_print(smpl);
    llama_perf_context_print(ctx);
    fprintf(stderr, "\n");

    llama_sampler_free(smpl);
    llama_free(ctx);
    llama_model_free(model);

    return 0;
}

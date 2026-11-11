#include "ggml.h"
#include "ggml-alloc.h"
#include "ggml-backend.h"
#include <cstdio>

int main(int argc, char ** argv) {
    if (argc != 2) {
        std::fprintf(stderr, "Usage: matmul-demo CPU|Vulkan0\n");
        return 2;
    }
    ggml_backend_load_all();
    auto backend = ggml_backend_init_by_name(argv[1], nullptr);
    if (!backend) {
        std::fprintf(stderr, "Device unavailable: %s\n", argv[1]);
        return 1;
    }

    auto ctx = ggml_init({ggml_graph_overhead() + 3 * ggml_tensor_overhead(), nullptr, true});
    auto w = ggml_new_tensor_2d(ctx, GGML_TYPE_F32, 3, 2);
    auto x = ggml_new_tensor_2d(ctx, GGML_TYPE_F32, 3, 2);
    auto y = ggml_mul_mat(ctx, w, x);
    auto graph = ggml_new_graph(ctx);
    ggml_build_forward_expand(graph, y);

    auto buffer = ggml_backend_alloc_ctx_tensors(ctx, backend);
    bool ok = false;
    if (buffer) {
        const float weights[] = {1, 2, 3, 4, 5, 6};
        const float tokens[] = {1, 0, 1, 0, 1, 0};
        ggml_backend_tensor_set(w, weights, 0, sizeof(weights));
        ggml_backend_tensor_set(x, tokens, 0, sizeof(tokens));
        if (ggml_backend_graph_compute(backend, graph) == GGML_STATUS_SUCCESS) {
            float out[4];
            ggml_backend_tensor_get(y, out, 0, sizeof(out));
            std::printf("%s: token 0 [%g, %g], token 1 [%g, %g]\n",
                        ggml_backend_name(backend), out[0], out[1], out[2], out[3]);
            ok = out[0] == 4 && out[1] == 10 && out[2] == 2 && out[3] == 5;
        }
        ggml_backend_buffer_free(buffer);
    }
    ggml_free(ctx);
    ggml_backend_free(backend);
    return ok ? 0 : 1;
}

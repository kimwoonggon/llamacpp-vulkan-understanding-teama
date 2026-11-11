#include "inspect.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif

namespace fs = std::filesystem;

#ifdef _WIN32
int wmain(int argc, wchar_t **argv) {
    SetConsoleOutputCP(CP_UTF8);
#else
int main(int argc, char **argv) {
#endif
    if (argc == 2 && fs::path(argv[1]) == "--help") {
        std::cout << "gguf-inspector MODEL.gguf [--html REPORT.html]\n";
        return 0;
    }
    if (argc != 2 && !(argc == 4 && fs::path(argv[2]) == "--html")) {
        std::cerr << "Usage: gguf-inspector MODEL.gguf [--html REPORT.html]\n";
        return 2;
    }
    try {
        const fs::path input(argv[1]);
        const auto model = inspect(input);
        if (argc == 4) {
            const fs::path output(argv[3]);
            if (output.extension() != ".html" || (fs::exists(output) && fs::equivalent(input, output)))
                throw std::runtime_error("choose a separate .html output file");
            std::ofstream file(output, std::ios::binary);
            if (!file) throw std::runtime_error("cannot open HTML output");
            report(file, model, true);
            file.close();
            if (!file) throw std::runtime_error("cannot finish HTML output");
            std::cerr << "HTML: " << fs::absolute(output).u8string() << "\n";
        }
        report(std::cout, model, false);
        return std::cout ? 0 : 1;
    } catch (const std::exception &error) {
        std::cerr << "GGUF inspection failed: " << error.what() << "\n";
        return 1;
    }
}

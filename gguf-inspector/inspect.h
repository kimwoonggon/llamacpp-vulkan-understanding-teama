#pragma once
#include <cstdint>
#include <filesystem>
#include <iosfwd>
#include <string>
#include <vector>

struct Metadata {
    uint64_t begin, end;
    std::string key, type, value;
};

struct Tensor {
    uint64_t descriptor, relative, absolute, bytes, padding;
    std::string name, shape, type, hex;
};

struct Inspection {
    std::string filename, header_hex;
    uint32_t version = 0, alignment = 32;
    uint64_t file_size = 0, metadata_end = 0, info_end = 0, data_start = 0, trailing = 0;
    std::vector<Metadata> metadata;
    std::vector<Tensor> tensors;
};

Inspection inspect(const std::filesystem::path &path);
void qwen2_map(std::ostream &out, const Inspection &model);
void report(std::ostream &out, const Inspection &model, bool html);

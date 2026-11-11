#include "inspect.h"
#include "gguf.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <stdexcept>

namespace {
using u64 = uint64_t;

u64 product(u64 a, u64 b) {
    if (a && b > UINT64_MAX / a) throw std::runtime_error("byte count overflow");
    return a * b;
}

class Reader {
    std::ifstream in;
public:
    u64 size, pos = 0;
    explicit Reader(const std::filesystem::path &path)
        : in(path, std::ios::binary | std::ios::ate) {
        if (!in || in.tellg() < 0) throw std::runtime_error("cannot open GGUF");
        size = static_cast<u64>(in.tellg());
        seek(0);
    }
    void require(u64 bytes) const {
        if (bytes > size - pos) throw std::runtime_error("unexpected EOF at " + std::to_string(pos));
    }
    void seek(u64 at) {
        if (at > size || !in.seekg(static_cast<std::streamoff>(at)))
            throw std::runtime_error("invalid file offset");
        pos = at;
    }
    void skip(u64 n) {
        require(n);
        if (n) seek(pos + n);
    }
    void read(void *to, size_t n) {
        require(n);
        if (!in.read(static_cast<char *>(to), n)) throw std::runtime_error("file read failed");
        pos += n;
    }
    template<class T> T number() {
        T val{};
        read(&val, sizeof val);
        return val;
    }
    std::string string(size_t limit, bool preview = false) {
        const auto length = number<u64>();
        require(length);
        if (!preview && length > limit) throw std::runtime_error("name exceeds supported length");
        std::string value(static_cast<size_t>(std::min<u64>(limit, length)), '\0');
        read(value.data(), value.size());
        if (length > value.size()) {
            skip(length - value.size());
            // Omit the last UTF-8 code point if the preview boundary splits it.
            size_t start = value.size() - 1;
            while (start && (static_cast<unsigned char>(value[start]) & 0xc0) == 0x80) --start;
            unsigned char lead = value[start];
            size_t width = lead < 128 ? 1 : lead < 224 ? 2 : lead < 240 ? 3 : 4;
            if (start + width > value.size()) value.resize(start);
            value += "…";
        }
        return value;
    }
    std::string hex(size_t count) {
        std::ostringstream s;
        s << std::hex << std::uppercase << std::setfill('0');
        for (size_t i = 0; i < count; ++i) {
            if (i) s << ' ';
            s << std::setw(2) << +number<uint8_t>();
        }
        return s.str();
    }
};

constexpr std::array<unsigned, GGUF_TYPE_COUNT> widths{1,1,2,2,4,4,4,1,0,0,8,8,8};

gguf_type value_type(Reader &r) {
    auto t = r.number<uint32_t>();
    if (t >= GGUF_TYPE_COUNT) throw std::runtime_error("unknown metadata type");
    return static_cast<gguf_type>(t);
}

template<class T> std::string decimal(T value) {
    std::ostringstream out;
    out << std::setprecision(std::numeric_limits<T>::max_digits10) << value;
    return out.str();
}

std::string scalar(Reader &r, gguf_type t) {
    switch (t) {
    case GGUF_TYPE_UINT8:   return std::to_string(r.number<uint8_t>());
    case GGUF_TYPE_INT8:    return std::to_string(r.number<int8_t>());
    case GGUF_TYPE_UINT16:  return std::to_string(r.number<uint16_t>());
    case GGUF_TYPE_INT16:   return std::to_string(r.number<int16_t>());
    case GGUF_TYPE_UINT32:  return std::to_string(r.number<uint32_t>());
    case GGUF_TYPE_INT32:   return std::to_string(r.number<int32_t>());
    case GGUF_TYPE_UINT64:  return std::to_string(r.number<uint64_t>());
    case GGUF_TYPE_INT64:   return std::to_string(r.number<int64_t>());
    case GGUF_TYPE_FLOAT32: return decimal(r.number<float>());
    case GGUF_TYPE_FLOAT64: return decimal(r.number<double>());
    case GGUF_TYPE_BOOL:    return r.number<uint8_t>() ? "true" : "false";
    case GGUF_TYPE_STRING:  return r.string(192, true);
    default: throw std::runtime_error("unsupported metadata element type");
    }
}

Metadata read_metadata(Reader &r, uint32_t &alignment) {
    Metadata kv{};
    kv.begin = r.pos;
    kv.key = r.string(65535);
    auto t = value_type(r);
    kv.type = gguf_type_name(t);
    if (kv.key == GGUF_KEY_GENERAL_ALIGNMENT) {
        if (t != GGUF_TYPE_UINT32) throw std::runtime_error("general.alignment requires uint32");
        alignment = r.number<uint32_t>();
        if (!alignment || (alignment & (alignment - 1))) throw std::runtime_error("invalid alignment");
        kv.value = std::to_string(alignment);
    } else if (t == GGUF_TYPE_ARRAY) {
        const auto element = value_type(r);
        if (element == GGUF_TYPE_ARRAY) throw std::runtime_error("nested arrays are unsupported");
        const auto count = r.number<u64>();
        const auto shown = std::min<u64>(count, 4);
        kv.type = std::string(gguf_type_name(element)) + "[" + std::to_string(count) + "]";
        kv.value = "[";
        for (u64 i = 0; i < shown; ++i) {
            if (i) kv.value += ", ";
            kv.value += scalar(r, element);
        }
        if (shown < count) kv.value += ", …";
        kv.value += "]";
        if (element == GGUF_TYPE_STRING) {
            for (u64 i = shown; i < count; ++i) r.skip(r.number<u64>());
        } else {
            r.skip(product(count - shown, widths[element]));
        }
    } else {
        kv.value = scalar(r, t);
    }
    kv.end = r.pos;
    return kv;
}

Tensor read_tensor(Reader &r) {
    Tensor t{};
    t.descriptor = r.pos;
    t.name = r.string(GGML_MAX_NAME - 1);
    const auto rank = r.number<uint32_t>();
    if (!rank || rank > GGML_MAX_DIMS) throw std::runtime_error("unsupported tensor rank");
    std::vector<u64> dims(rank);
    for (auto &dim : dims) {
        dim = r.number<u64>();
        if (dim > INT64_MAX) throw std::runtime_error("invalid tensor dimension");
        if (!t.shape.empty()) t.shape += " × ";
        t.shape += std::to_string(dim);
    }
    const auto id = r.number<uint32_t>();
    if (id >= GGML_TYPE_COUNT) throw std::runtime_error("unknown GGML tensor type");
    const auto type = static_cast<ggml_type>(id);
    const auto block = ggml_blck_size(type);
    if (block <= 0 || dims.front() % block) throw std::runtime_error("invalid tensor block size");
    t.type = ggml_type_name(type);
    t.bytes = product(dims.front() / block, ggml_type_size(type));
    for (size_t i = 1; i < dims.size(); ++i) t.bytes = product(t.bytes, dims[i]);
    t.relative = r.number<u64>();
    return t;
}
} // namespace

Inspection inspect(const std::filesystem::path &path) {
    Reader r(path);
    Inspection m;
    m.filename = path.filename().u8string();
    m.file_size = r.size;
    m.header_hex = r.hex(24);
    r.seek(0);
    char magic[4];
    r.read(magic, 4);
    if (std::string(magic, 4) != "GGUF") throw std::runtime_error("expected GGUF magic");
    m.version = r.number<uint32_t>();
    if (m.version != 2 && m.version != 3) throw std::runtime_error("expected little-endian GGUF v2/v3");
    const auto tensors = r.number<u64>();
    const auto keys = r.number<u64>();
    for (u64 i = 0; i < keys; ++i) m.metadata.push_back(read_metadata(r, m.alignment));
    m.metadata_end = r.pos;
    for (u64 i = 0; i < tensors; ++i) m.tensors.push_back(read_tensor(r));
    m.info_end = r.pos;
    if (tensors) r.skip((m.alignment - r.pos % m.alignment) % m.alignment);
    m.data_start = r.pos;

    // The bundled llama.cpp reader expects descriptors in consecutive, aligned data order.
    u64 next = 0;
    for (auto &t : m.tensors) {
        if (t.relative != next || t.relative % m.alignment) throw std::runtime_error("unexpected tensor offset: " + t.name);
        t.absolute = m.data_start + t.relative;
        r.seek(t.absolute);
        r.require(t.bytes);
        t.hex = r.hex(static_cast<size_t>(std::min<u64>(16, t.bytes)));
        const auto end = t.absolute + t.bytes;
        t.padding = std::min<u64>((m.alignment - end % m.alignment) % m.alignment, r.size - end);
        next = end - m.data_start + t.padding;
    }
    m.trailing = r.size - m.data_start - next;
    return m;
}

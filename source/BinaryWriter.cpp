#include <stdexcept>
#include "BinaryWriter.h"

namespace demo {
    BinaryWriter::BinaryWriter(const std::string& path):
            stream(path, std::ofstream::binary | std::ofstream::trunc) {
        if (!stream.is_open()) throw std::runtime_error(std::string("Cannot open file: ") + path);
    }

    void BinaryWriter::handle(const Slice& slice) {
        stream.write(reinterpret_cast<const char*>(slice.data), slice.size);
    }
}

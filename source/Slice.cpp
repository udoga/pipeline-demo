#include <cstring>
#include "Slice.h"

namespace demo {
    Slice::Slice(const u8* data, u32 size): data(data), size(size) {
    }

    Slice::Slice(const char* data, u32 size): Slice((const u8*) data, size) {
    }

    Slice::Slice(const std::vector<u8>& v, u32 offset): Slice(&v[offset], u32(v.size() - offset)) {
    }

    u32 Slice::getSize() const {
        return size;
    }

    void Slice::serialize(u8* buffer) const {
        memcpy(buffer, data, size);
    }

    const u8& Slice::operator[](u32 i) const {
        return data[i];
    }

    const bool Slice::operator==(const Slice& other) const {
        if (size != other.size) return false;
        for (u32 i = 0; i < size; i++) if (data[i] != other[i]) return false;
        return true;
    }

    std::ostream& operator<<(std::ostream& os, const Slice& slice) {
        os << "Slice[size=" << slice.size << " data=[";
        for (u32 i = 0; i < slice.size; i++) os << unsigned(slice[i]) << " ";
        return os << "]]";
    }
}

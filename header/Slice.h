#pragma once

#include <ostream>
#include <vector>
#include "Serializable.h"

namespace demo {
    class Slice: public Serializable {
    public:
        const u8* data;
        const u32 size;
        Slice(const u8* data, u32 size);
        Slice(const char* data, u32 size);
        Slice(const std::vector<u8>& v, u32 offset = 0);
        u32 getSize() const override;
        void serialize(u8* buffer) const override;
        const u8& operator[](u32 i) const;
        const bool operator==(const Slice& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Slice& slice);
    };
}

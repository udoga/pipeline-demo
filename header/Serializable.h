#pragma once

#include "Types.h"

namespace demo {
    class Serializable {
    public:
        virtual u32 getSize() const = 0;
        virtual void serialize(u8* buffer) const = 0;
        virtual ~Serializable() = default;
    };
}

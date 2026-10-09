#pragma once

#include "Types.h"

namespace demo {
    template <typename T>
    class Handler {
    public:
        virtual void handle(const T& t) = 0;
        virtual ~Handler() = default;
    };
}

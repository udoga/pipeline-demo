#pragma once

#include "Types.h"

namespace demo {
    class Listener {
    public:
        virtual void listen() = 0;
        virtual ~Listener() = default;
    };
}

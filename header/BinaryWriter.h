#pragma once

#include <fstream>
#include <string>
#include "Slice.h"
#include "Handler.h"

namespace demo {
    class BinaryWriter: public Handler<Slice> {
    public:
        explicit BinaryWriter(const std::string& path);
        void handle(const Slice& slice) override;
    private:
        std::ofstream stream;
    };
}

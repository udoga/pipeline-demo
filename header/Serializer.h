#pragma once

#include <vector>
#include "Emitter.h"
#include "Slice.h"

namespace demo {
    template <typename T>
    class Serializer: public Handler<T>, public Emitter<Slice> {
    public:
        explicit Serializer(u32 size): buffer(size) {
        }

        void handle(const T& s) override {
            s.serialize(buffer.data());
            emit(Slice(buffer.data(), s.getSize()));
        }
    private:
        std::vector<u8> buffer;
    };
}

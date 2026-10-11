#pragma once

#include "Emitter.h"

namespace demo {
    template <typename T>
    class Parser: public Handler<std::string>, public Emitter<T> {
    public:
        void handle(const std::string& s) override {
            Emitter<T>::emit(T(s));
        }
    };
}

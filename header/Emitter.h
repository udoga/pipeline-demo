#pragma once

#include "Enroller.h"
#include "Handler.h"

namespace demo {
    template <typename T>
    class Emitter: public Enroller<Handler<T>> {
    public:
        void emit(const T& t) {
            for (Handler<T>* s: this->subscribers)
                s->handle(t);
        }
    };
}

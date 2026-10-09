#pragma once

#include "Enroller.h"
#include "Listener.h"

namespace demo {
    class Notifier: public Enroller<Listener> {
    protected:
        void notify() {
            for (Listener* s: this->subscribers)
                s->listen();
        }
    };
}

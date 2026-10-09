#pragma once

#include <list>
#include "Types.h"

namespace demo {
    template <typename T>
    class Enroller {
    public:
        void enrol(T& subscriber) {
            subscribers.push_back(&subscriber);
        }

        const std::list<T*>& getSubscribers() const {
            return subscribers;
        }
    protected:
        std::list<T*> subscribers;
    };
}

#pragma once

#include <vector>
#include "Handler.h"

namespace demo {
    template <typename T>
    class Collector: public Handler<T> {
    public:
        std::vector<T> items;

        void handle(const T& item) override {
            items.push_back(item);
        }
    };
}

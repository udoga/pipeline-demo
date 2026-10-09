#include <iostream>
#include "Collector.h"
#include "Emitter.h"

using namespace demo;

i32 main(i32 argc, char *argv[]) {
    Emitter<u32> emitter;
    Collector<u32> collector;
    emitter.enrol(collector);
    emitter.emit(1);
    std::cout << collector.items.at(0) << std::endl;
}

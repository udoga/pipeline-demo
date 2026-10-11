#include <iostream>
#include "Collector.h"
#include "TextReader.h"

using namespace demo;

i32 main(i32 argc, char *argv[]) {
    TextReader textReader("resource/test.csv", true);
    Collector<std::string> collector;
    textReader.Emitter<std::string>::enrol(collector);
    textReader.listen();
    std::cout << collector.items.at(0) << std::endl;
}

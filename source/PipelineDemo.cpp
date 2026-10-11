#include <iostream>
#include "BinaryWriter.h"
#include "PacketCapture.h"
#include "Parser.h"
#include "Serializer.h"
#include "TextReader.h"

using namespace demo;

i32 main() {
    TextReader textReader("resource/sample.pcap.csv", true);
    Parser<PacketCapture> captureParser;
    Serializer<PacketCapture> captureSerializer(4096);
    BinaryWriter binaryWriter("output.dat");

    textReader.Emitter<std::string>::enrol(captureParser);
    captureParser.Emitter<PacketCapture>::enrol(captureSerializer);
    captureSerializer.Emitter<Slice>::enrol(binaryWriter);

    while (textReader.left()) textReader.listen();
    std::cout << "Wrote output.dat" << std::endl;
}

# Pipeline Demo

A minimal event-driven C++ pipeline demonstrating a structure I have used in production systems.

The pipeline reads packet capture CSV data, parses each row, serializes the payload bytes, and writes them to a binary output file.

```text
TextReader -> Parser<PacketCapture> -> Serializer<PacketCapture> -> BinaryWriter
```

```sh
./build.sh # builds and runs tests
./build/PipelineDemo
```

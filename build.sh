#!/bin/bash
set -e

mkdir -p build
cd build
cmake ..
make -j 4
./PipelineDemoTest

cmake_minimum_required(VERSION 3.5)
project(pipeline-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
include_directories(header)

file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB SOURCES "source/*.cpp")
file(GLOB TESTS "test/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/PipelineDemo.cpp")

add_executable(PipelineDemo source/PipelineDemo.cpp ${SOURCES})
add_executable(PipelineDemoTest ${TESTS} ${SOURCES})
target_link_libraries(PipelineDemoTest gtest)

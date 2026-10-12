cmake_minimum_required(VERSION 3.14)
project(pipeline-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
include_directories(header)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB SOURCES "source/*.cpp")
file(GLOB TESTS "test/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/PipelineDemo.cpp")

add_executable(PipelineDemo source/PipelineDemo.cpp ${SOURCES})
add_executable(PipelineDemoTest ${TESTS} ${SOURCES})
target_link_libraries(PipelineDemoTest GTest::gtest)

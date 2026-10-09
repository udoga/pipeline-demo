cmake_minimum_required(VERSION 3.5)
project("event-flow")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3 -march=native")
set(DIR_LIB "/usr/local/lib")
set(DIR_INCLUDE "/usr/local/include")
set(DIR_BUILD ".")

file(GLOB SOURCES "source/*.cpp")
file(GLOB HEADERS "header/*.h")
file(GLOB TESTS "test/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/source/Main.cpp")

include_directories(${DIR_INCLUDE} header)
link_directories(${DIR_LIB})

add_library(${PROJECT_NAME} INTERFACE)
add_executable(Main source/Main.cpp)
add_executable(MainTest ${TESTS})

target_include_directories(${PROJECT_NAME} INTERFACE header)
target_link_libraries(${PROJECT_NAME} INTERFACE ${EXT_LIBS})
target_link_libraries(Main ${PROJECT_NAME})
target_link_libraries(MainTest gtest ${PROJECT_NAME})

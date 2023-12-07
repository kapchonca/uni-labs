cmake_minimum_required(VERSION 3.5)

project(lab3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(lab3 src/main.cpp)

include_directories(/usr/include/gtest)

target_link_libraries(lab3 ${GTEST_LIBRARIES} pthread)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -g")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
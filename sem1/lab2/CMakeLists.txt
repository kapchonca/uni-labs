cmake_minimum_required(VERSION 3.5)

project(lab2)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
file(GLOB SOURCES
    h/*.h
    cpp/*.cpp)
 
add_executable(lab2 ${SOURCES})

target_link_libraries(lab2 ${CURSES_LIBRARIES} tinfo)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -g")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
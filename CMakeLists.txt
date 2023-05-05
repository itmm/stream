cmake_minimum_required(VERSION 3.18)
project(stream)

set(CMAKE_CXX_STANDARD 17)

add_executable(run_tests.cpp stream.cpp stream.h)

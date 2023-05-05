cmake_minimum_required(VERSION 3.18)
project(stream)

set(CMAKE_CXX_STANDARD 17)

add_custom_command(
	COMMAND $ENV{HOME}/bin/mdp README.md
	DEPENDS README.md
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	OUTPUT ${PROJECT_SOURCE_DIR}/run_test.cpp ${PROJECT_SOURCE_DIR}/stream.cpp ${PROJECT_SOURCE_DIR}/stream.h
)
add_executable(run_tests run_tests.cpp stream.cpp stream.h)

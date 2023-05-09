.PHONY: all clean

all: run_tests
	./run_tests

t_src/run_tests.cpp: src/stream.h
	touch $@

run_tests: t_src/run_tests.cpp
	$(CXX) $^ -It_src -Isrc -g -Wall -o$@

clean:
	rm run_tests

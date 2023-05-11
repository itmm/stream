.PHONY: all clean

CXXFLAGS += -std=c++17 -g -Wall -Isrc -It_src

all: run_tests
	./run_tests

t_src/run_tests.cpp: src/stream.h
	touch $@

src/stream.cpp: src/stream.h
	touch $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o$@

run_tests: t_src/run_tests.o src/stream.o
	$(CXX) $(CXXFLAGS) $^ -o$@

clean:
	rm -f run_tests src/*.o t_src/*.o

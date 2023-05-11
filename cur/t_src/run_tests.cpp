#include "stream.h"

// _unit-testet_: [[Δ1]](../../delta/1.patch)

#include <cassert>
#include <filesystem>
#include <fstream>

void run_ut1_add_lines() {
	std::string file_name { "test.txt" };
	std::string line_1 { "abc" };
	std::string line_2 { "def" };
	std::filesystem::remove(file_name);
	{
		Stream str { file_name };
		str.add(line_1);
		str.add(line_2);
	}
	{
		std::ifstream in { file_name };
		std::string line;
		assert(std::getline(in, line));
		assert(line == line_1);
		assert(std::getline(in, line));
		assert(line == line_2);
		assert(!std::getline(in, line));
	}
	std::filesystem::remove(file_name);
}

int main() {
	run_ut1_add_lines();
}

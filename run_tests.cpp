#line 50 "README.md"
#include "stream.h"

#include <cassert>
#line 66
#include <filesystem>
#line 53

void run_ut1_add_lines() {
#line 69
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
	return;
#line 55
	assert(false);
}

int main() {
	run_ut1_add_lines();
}

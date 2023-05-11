#include "stream.h"

// _unit-testet_: [[Δ1]](../../delta/1.patch)

#include <cassert>
#include <filesystem>
#include <fstream>

static const std::string file_name { "test.txt" };
static const std::string line_1 { "abc" };
static const std::string line_2 { "def" };

void check_expected() {
	std::ifstream in { file_name };
	std::string line;
	assert(std::getline(in, line));
	assert(line == line_1);
	assert(std::getline(in, line));
	assert(line == line_2);
	assert(!std::getline(in, line));
}

void run_ut1_add_lines() {
	std::filesystem::remove(file_name);
	{
		Stream str { file_name };
		str.add(line_1);
		str.add(line_2);
	}
	check_expected();
	std::filesystem::remove(file_name);
}

void run_ut2_add_line() {
	{
		std::ofstream out { file_name };
		out << line_1 << '\n';
	}
	{
		Stream str { file_name };
		str.add(line_2);
	}
	check_expected();
	std::filesystem::remove(file_name);
}

int main() {
	run_ut1_add_lines();
}

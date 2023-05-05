#line 34 "README.md"
#pragma once

#include <string>
#line 102
#include <fstream>
#line 37

class Stream {
#line 105
		std::ofstream out_;
#line 39
	public:
		explicit Stream(const std::string &file_path);
		void add(const std::string &data);
};

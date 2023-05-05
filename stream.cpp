#line 113 "README.md"
#include "stream.h"

#include <fstream>

Stream::Stream(const std::string &file_path):
	out_ { file_path.c_str() }
{ }

void Stream::add(const std::string &data) {
	out_ << data << "\n";
}

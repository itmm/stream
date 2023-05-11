#pragma once

// _Design von_: [[Δ1]](../../delta/1.patch)

#include "stream.h"

#include <fstream>
#include <string>

class Stream {
		std::ofstream out_;
	public:
		explicit Stream(const std::string &file_path);
		void add(const std::string &data);
};

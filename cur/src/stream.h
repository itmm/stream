#pragma once

// _Design von_: [[Δ1]](../../delta/1.patch)

#include <string>

class Stream {
	public:
		explicit Stream(const std::string &file_path);
		void add(const std::string &data);
};

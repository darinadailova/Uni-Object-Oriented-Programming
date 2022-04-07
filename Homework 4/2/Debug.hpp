#pragma once
#include <string>

class Debug {
public:
	Debug() = default;
	virtual std::string debug_print() const = 0;
	virtual ~Debug();
};
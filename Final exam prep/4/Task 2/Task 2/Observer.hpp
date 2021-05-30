#pragma once
#include <string>

class Observer {
public:
	Observer() = default;
	virtual void update(const std::string& currency, double rate) = 0;
	virtual Observer* clone() const = 0;
};
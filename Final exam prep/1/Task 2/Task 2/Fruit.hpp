#pragma once
#include "StoreItem.hpp"
#include <string>

class Fruit : public StoreItem {
	std::string name;
	std::string color;
public:
	Fruit(const std::string& newName = "", const std::string& newColor = "");
	std::string getName() const;
	void setName(const std::string& newName);
	void setColor(const std::string& newColor);
	bool operator>(const Fruit& rhs) const;
	void print() const;
};
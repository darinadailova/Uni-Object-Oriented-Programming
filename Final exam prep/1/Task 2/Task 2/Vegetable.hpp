#pragma once
#include "StoreItem.hpp"
#include <string>

class Vegetable : public StoreItem {
	std::string name;
	std::string sort;
public:
	Vegetable(const std::string& newNmae = "", const std::string& newSort = "");
	std::string getName() const;
	void setName(const std::string& newName);
	void setSort(const std::string& newSort);
	bool operator==(const Vegetable& rhs);
	void print() const;
};
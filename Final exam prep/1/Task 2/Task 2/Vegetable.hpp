#pragma once
#include "StoreItem.hpp"

class Vegetable : public StoreItem {
	std::string name;
	std::string sort;
public:
	Vegetable(unsigned int calories = 0, double price = 0,
		const std::string& name = "", const std::string sort = "");
	Vegetable(const Vegetable& rhs);
	std::string getName() const;
	void setName(const std::string& name);
	void setSort(const std::string& sort);

	bool operator==(const Vegetable& rhs) const;
	void print() const;
	virtual StoreItem* clone() const override;
};


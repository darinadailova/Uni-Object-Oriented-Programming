#pragma once
#include "StoreItem.hpp"
#include <string>

class Fruit : public StoreItem {
	std::string name;
	std::string color;
public:
	Fruit(unsigned int calories = 0, double price = 0,
		const std::string& name = "", const std::string& color = "");
	Fruit(const Fruit& rhs);

	std::string getName() const;
	
	void setName(const std::string& name);
	void setColor(const std::string& color);

	bool operator>(const Fruit& rhs) const;
	void print() const;
	virtual StoreItem* clone() const override;
};


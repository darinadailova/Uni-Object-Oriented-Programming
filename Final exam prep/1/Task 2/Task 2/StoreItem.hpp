#pragma once
#include <iostream>

enum class Type {
	FRUIT,
	VEGETABLE,
	DEFAULT
};

class StoreItem {
	Type type;
	unsigned int calories;
	double price;
public:
	StoreItem(const Type& type = Type::DEFAULT, unsigned int calories = 0, double price = 0);

	Type getType() const;
	unsigned int getCalories() const;
	double getPrice() const;

	void setType(const Type& type);
	void setCalories(unsigned int  calories);
	void setPrice(double price);

	void print() const;
	virtual StoreItem* clone() const = 0;
	virtual ~StoreItem();
};


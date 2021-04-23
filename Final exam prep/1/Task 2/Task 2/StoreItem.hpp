#pragma once
#include <iostream>

enum class ProductType {
	fruit,
	vegetable, 
	defaultValue
};

class StoreItem {
	ProductType type;
	unsigned int calories;
	double price;
public:
	StoreItem(const ProductType& newType = ProductType::defaultValue, const unsigned int& newCalories = 0, const double& newPrice = 0);
	
	ProductType getType() const;
	unsigned int getCalories() const;
	double getPrice() const;

	void setType(const ProductType& newType);
	void setCalories(const unsigned int& newCalories);
	void setPrice(const double& newPrice);
};
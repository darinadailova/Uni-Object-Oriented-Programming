#include "StoreItem.hpp"

StoreItem::StoreItem(const ProductType& newType, const unsigned int& newCalories, const double& newPrice) {
	type = newType;
	calories = newCalories;
	price = newPrice;
}

ProductType StoreItem::getType() const { return type; }

unsigned int StoreItem::getCalories() const { return calories; }

double StoreItem::getPrice() const { return price; }

void StoreItem::setType(const ProductType& newType) {
	type = newType;
}

void StoreItem::setCalories(const unsigned int& newCalories) {
	calories = newCalories;
}

void StoreItem::setPrice(const double& newPrice) {
	price = newPrice;
}

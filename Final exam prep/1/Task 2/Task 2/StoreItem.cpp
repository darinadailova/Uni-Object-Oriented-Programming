#include "StoreItem.hpp"

StoreItem::StoreItem(const Type& type, unsigned int calories, double price) 
	: type(type), calories(calories), price(price) {
}

Type StoreItem::getType() const {
	return type;
}

unsigned int StoreItem::getCalories() const {
	return calories;
}

double StoreItem::getPrice() const {
	return price;
}

void StoreItem::setType(const Type& type) {
	this->type = type;
}

void StoreItem::setCalories(unsigned int calories) {
	this->calories = calories;
}

void StoreItem::setPrice(double price) {
	this->price = price;
}

void StoreItem::print() const {
	std::cout << "Product Type: ";
	if(type == Type::FRUIT) std::cout << "Fruit\n";
	else if(type == Type::VEGETABLE) std::cout << "Vegetable\n";
	std::cout << "Calories: " << calories << '\n';
	std::cout << "Price: " << price << '\n';
}

StoreItem::~StoreItem() {
}
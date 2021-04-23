#include "Fruit.hpp"

Fruit::Fruit(const std::string& newName, const std::string& newColor) {
	setType(ProductType::fruit);
	name = newName;
	color = newColor;
}

std::string Fruit::getName() const { return name; }

void Fruit::setName(const std::string& newName) { name = newName; }

void Fruit::setColor(const std::string& newColor) { color = newColor; }

bool Fruit::operator>(const Fruit& rhs) const {
	if (getCalories() > rhs.getCalories()) {
		return true;
	}
	return false;
}

void Fruit::print() const {
	std::cout << "Product type: ";
	if (getType() == ProductType::defaultValue) std::cout << "Default value";
	else if (getType() == ProductType::fruit) std::cout << "Fruit";
	else std::cout << "Vegetable";
	std::cout << '\n';
	std::cout << "Calories: " << getCalories() << '\n';
	std::cout << "Price: " << getPrice() << '\n';
	std::cout << "Name: " << name << '\n';
	std::cout << "Color: " << color << '\n';
}

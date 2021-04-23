#include "Vegetable.hpp"

Vegetable::Vegetable(const std::string& newName, const std::string& newSort) {
	setType(ProductType::vegetable);
	name = newName;
	sort = newSort;
}

std::string Vegetable::getName() const { return name; }

void Vegetable::setName(const std::string& newName) { name = newName; }

void Vegetable::setSort(const std::string& newSort) { sort = newSort; }

bool Vegetable::operator==(const Vegetable& rhs) {
	if (sort == rhs.sort) return true;
	return false;
}

void Vegetable::print() const {
	std::cout << "Product type: ";
	if (getType() == ProductType::defaultValue) std::cout << "Default value";
	else if (getType() == ProductType::fruit) std::cout << "Fruit";
	else std::cout << "Vegetable";
	std::cout << '\n';
	std::cout << "Calories: " << getCalories() << '\n';
	std::cout << "Price: " << getPrice() << '\n';
	std::cout << "Name: " << name << '\n';
	std::cout << "Sort: " << sort << '\n';
}
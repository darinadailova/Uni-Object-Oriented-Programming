#include "Food.hpp"

Food::Food(unsigned int newAvailability, double newPrice, const std::string& newName, double newWeight) 
    : RestaurantItem(ProductType::FOOD, newAvailability, newPrice), name(newName), weight(newWeight) {
}

std::string Food::getName() const {
    return name;
}

void Food::setName(const std::string& newName) {
    name = newName;
}

void Food::setWeight(double newWeight) {
    if(newWeight > 0) {
        weight = newWeight;
    }
}

bool Food::operator>(const Food& rhs) const {
    return this->weight > rhs.weight;
}

void Food::print() const {
    std::cout << "Food\n";
    std::cout << "Availability: " << RestaurantItem::getAvailability() << '\n';
    std::cout << "Price: " << RestaurantItem::getPrice() << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Weight: " << weight << '\n';
}

RestaurantItem* Food::clone() const {
    return new Food(*this);
}
#include "Drink.hpp"

Drink::Drink(unsigned int newAvailability, double newPrice, const std::string& newName, double newAlcohol) 
    : RestaurantItem(ProductType::DRINK, newAvailability, newPrice), name(newName), alcohol(newAlcohol) {
}

std::string Drink::getName() const {
    return name;
}

void Drink::setName(const std::string& newName) {
    name = newName;
}

void Drink::newAlcohol(double newAlcohol) {
    if(newAlcohol > 0) {
        alcohol = newAlcohol;
    }
}

bool Drink::operator>(const Drink& rhs) const {
    return alcohol > rhs.alcohol;
}

void Drink::print() const {
    std::cout << "Drink\n";
    std::cout << "Availability: " << RestaurantItem::getAvailability() << '\n';
    std::cout << "Price: " << RestaurantItem::getPrice() << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Alcohol: " << alcohol << '\n';
}

RestaurantItem* Drink::clone() const {
    return new Drink(*this);
}
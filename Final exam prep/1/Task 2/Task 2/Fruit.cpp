#include "Fruit.hpp"

Fruit::Fruit(unsigned int calories, double price, const std::string& name, const std::string& color) 
    : StoreItem(Type::FRUIT, calories, price), name(name), color(color) {
}

Fruit::Fruit(const Fruit& rhs) {
    this->setCalories(rhs.getCalories());
    this->setPrice(rhs.getPrice());
    this->name = rhs.name;
    this->color = rhs.color;
}

std::string Fruit::getName() const {
    return name;
}

void Fruit::setName(const std::string& name) {
    this->name = name;
}

void Fruit::setColor(const std::string& color) {
    this->color = color;
}

void Fruit::print() const {
    StoreItem::print();
    std::cout << "Name: " << name << '\n';
    std::cout << "Color " << color << '\n';
}

StoreItem* Fruit::clone() const {
    return new Fruit(*this);
}

bool Fruit::operator>(const Fruit& rhs) const { 
    return this->getCalories() > rhs.getCalories();
}
#include "Vegetable.hpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif

Vegetable::Vegetable(unsigned int calories, double price, const std::string& name, const std::string sort) 
    : StoreItem(Type::VEGETABLE, calories, price), name(name), sort(sort) {
}

Vegetable::Vegetable(const Vegetable& rhs) {
    this->setCalories(rhs.getCalories());
    this->setPrice(rhs.getPrice());
    this->name = rhs.name;
    this->sort = rhs.sort;
}

std::string Vegetable::getName() const {
    return name;
}

void Vegetable::setName(const std::string& name) {
    this->name = name;
}

void Vegetable::setSort(const std::string& sort) {
    this->sort = sort;
}

bool Vegetable::operator==(const Vegetable& rhs) const {
    return this->sort == rhs.sort;
}

void Vegetable::print() const {
    StoreItem::print();
    std::cout << "Name: " << name << '\n';
    std::cout << "Sort: " << sort << '\n';
}

StoreItem* Vegetable::clone() const {
    return new Vegetable(*this);
}

#include "Restaurant.hpp"

Restaurant::Restaurant(const Restaurant& rhs) {
    for(auto item : rhs.items) {
        this->items.push_back(item->clone());
    }
}

Restaurant& Restaurant::operator=(const Restaurant& rhs) {
    for(auto item : this->items) {
        delete item;
    }
    this->items.clear();

    for(auto x : rhs.items) {
        this->items.push_back(x->clone());
    }

    return *this;
}

Restaurant::~Restaurant() {
    for(auto item : this->items) {
        delete item;
    }
}

void Restaurant::addProduct(RestaurantItem* newItem) {
    items.push_back(newItem);
}

void Restaurant::removeItem(size_t index) {
    delete items[index];
    items.erase(items.begin() + index);
}

void Restaurant::changePrice(size_t index, unsigned int newPrice) {
    if(index > 0 && newPrice > 0) {
        items[index]->setPrice(newPrice);
    }
}

void Restaurant::changeName(size_t index, const std::string& newName) {
    Food* food = dynamic_cast<Food*>(items[index]);
    if(food) {
        food->setName(newName);
    }

    Drink* drink = dynamic_cast<Drink*>(items[index]);
    if(drink) {
        drink->setName(newName);
    }
}

void Restaurant::print() const {
    for (auto item : items) {
        item->print();
    }
}

void Restaurant::printNonAlcoholicDrinks() const {
    for(auto item : items) {
        Drink* drink = dynamic_cast<Drink*>(item);
        if(drink) {
            Drink zero = Drink(0, 0, "", 0.001);
            if(zero > *drink) {
                drink->print();
            }
        }
    }
}
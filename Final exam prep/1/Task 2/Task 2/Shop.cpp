#include "Shop.hpp"

void Shop::copy(const Shop& rhs) {
    for(auto x : rhs.items) {
        this->items.push_back(x->clone());
    }
}

void Shop::deleteIteams() {
    for(auto x : this->items) {
        delete x;
    }
    items.clear();
}

Shop::Shop(const Shop& rhs) {
    copy(rhs);
}

Shop& Shop::operator=(const Shop& rhs) {
    if(this != &rhs) {
        deleteIteams();
        copy(rhs);
    }

    return *this;
}

Shop::~Shop() {
    deleteIteams();
}

void Shop::addItem(StoreItem* newItem) {
    items.push_back(newItem->clone());
}

void Shop::removeItem(size_t index) {
    if(index < items.size()) {
        delete items[index];
        items.erase(items.begin() + index);
    }
}

void Shop::changePrice(size_t index, double newPrice) {
    if(index < items.size()) {
        items[index]->setPrice(newPrice);
    }
}

void Shop::changeName(size_t index, const std::string& newName) {
    if(index < items.size()) {
        if(items[index]->getType() == Type::FRUIT) {
            Fruit* obj1 = dynamic_cast<Fruit*>(items[index]);
            if(obj1) {
                obj1->setName(newName);
            }
        }

        if(items[index]->getType() == Type::VEGETABLE) {
            Vegetable* obj2 = dynamic_cast<Vegetable*>(items[index]);
            if(obj2) {
                obj2->setName(newName);
            }
        }
    }
}

void Shop::info() const {
    for(auto& item : items) {
        item->print();
    }
}

Fruit* Shop::fruitWithMostCalories() const {
    int temp = -1;
    size_t tempIndex = -1;
    for(size_t i = 0; i < items.size(); i++) {
        if(items[i]->getType() == Type::FRUIT) {
            Fruit* obj = dynamic_cast<Fruit*>(items[i]);
            if(obj) {
                if(obj->getCalories() > temp) {
                    temp = obj->getCalories();
                    tempIndex = i;
                }
            }
        }
    }

    return dynamic_cast<Fruit*>(items[tempIndex]);
}
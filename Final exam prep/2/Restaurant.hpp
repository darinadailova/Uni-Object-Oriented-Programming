#pragma once
#include "RestaurantItem.hpp"
#include <vector>
#include "Food.hpp"
#include "Drink.hpp"

class Restaurant {
    std::vector<RestaurantItem*> items;
public:
    Restaurant() = default;
    Restaurant(const Restaurant& rhs);
    Restaurant& operator=(const Restaurant& rhs);
    ~Restaurant();
    
    void addProduct(RestaurantItem* newItem);
    void removeItem(size_t index);
    void changePrice(size_t index, unsigned int newPrice);
    void changeName(size_t index, const std::string& newName);
    void print() const;
    void printNonAlcoholicDrinks() const;
};
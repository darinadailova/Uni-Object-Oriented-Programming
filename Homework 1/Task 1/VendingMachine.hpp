#pragma once
#include "drink.hpp"
#include <iostream>

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);
    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);
    void removeDrink(int index);

    // getters
    double get_income() const;
    int get_drinksCount() const;

    void print() const;

private:
    Drink* availableDrinks;
    double income;
    int drinksCount;
};
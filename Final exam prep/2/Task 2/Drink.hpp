#pragma once
#include "RestaurantItem.hpp"
#include <string>

class Drink : public RestaurantItem {
    std::string name;
    double alcohol;

public:
    Drink(unsigned int newAvailability = 0, double newPrice = 0, const std::string& newName = "", double newAlcohol = 0);

    std::string getName() const;
    void setName(const std::string& newName);
    void newAlcohol(double newAlcohol);

    bool operator>(const Drink& rhs) const;
    virtual void print() const override;
    virtual RestaurantItem* clone() const override;

};
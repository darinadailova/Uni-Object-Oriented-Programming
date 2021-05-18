#pragma once
#include "RestaurantItem.hpp"
#include <string>

class Food : public RestaurantItem {
    std::string name;
    double weight;

public:
    Food(unsigned int newAvailability = 0, double newPrice = 0, const std::string& newName = "", double newWeight = 0);

    std::string getName() const;
    void setName(const std::string& newName);
    void setWeight(double newWeight);

    bool operator>(const Food& rhs) const;
    virtual void print() const override;
    virtual RestaurantItem* clone() const override;
};
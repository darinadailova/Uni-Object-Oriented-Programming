#pragma once
#include <iostream>

enum class ProductType {
    FOOD,
    DRINK,
    DEFAULT
};

class RestaurantItem {
    ProductType type;
    unsigned int availability;
    double price;

public:
    RestaurantItem(ProductType newType = ProductType::DEFAULT, unsigned int newAvailability = 0, double newPrice = 0);

    ProductType getType() const;
    unsigned int getAvailability() const;
    double getPrice() const;

    void setType(ProductType newType);
    void setAvailability(unsigned int newAvailability);
    void setPrice(double newPrice);

    virtual void print() const = 0;
    virtual RestaurantItem* clone() const = 0;
    virtual ~RestaurantItem() = 0;
};
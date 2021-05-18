#include "RestaurantItem.hpp"

RestaurantItem::RestaurantItem(ProductType newType, unsigned int newAvailability, double newPrice)
    : type(newType), availability(newAvailability), price(newPrice) {
}

ProductType RestaurantItem::getType() const {
    return type;
}

unsigned int RestaurantItem::getAvailability() const {
    return availability;
}

double RestaurantItem::getPrice() const {
    return price;
}

void RestaurantItem::setType(ProductType newType) {
    type = newType;
}

void RestaurantItem::setAvailability(unsigned int newAvailability) {
    if(newAvailability > 0) {
        availability = newAvailability;
    }
}

void RestaurantItem::setPrice(double newPrice) {
    if(newPrice > 0) {
        price = newPrice;
    }
}

RestaurantItem::~RestaurantItem() {
}
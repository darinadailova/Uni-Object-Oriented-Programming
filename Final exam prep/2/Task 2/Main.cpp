#include "Restaurant.hpp"

int main() {
    Restaurant restaurant;
    restaurant.addProduct(new Food(30, 5.50, "Pizza", 0.400));
    restaurant.addProduct(new Drink(100, 2.80, "Water", 0));
    restaurant.changePrice(1, 1.80);
    restaurant.print();

    return 0;
}
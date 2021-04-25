#pragma once
#include <iostream>

class Drink {
public:
    Drink();
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);
    ~Drink();

    // getters
    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    // setters
    void set_name(const char* new_name);
    void set_calories(const int new_calories);
    void set_quantity(const double new_quantity);
    void set_price(const double new_price);

    void print() const;
private:
    char* name;
    double quantity;
    int calories;
    double price;
};
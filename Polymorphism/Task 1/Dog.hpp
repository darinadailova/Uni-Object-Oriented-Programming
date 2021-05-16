#pragma once
#include "Pet.hpp"

class Dog : public Pet {
public:
    Dog(std::string name = "");
    virtual void pet() const override;
    virtual void feed() override;
    void walk();
    virtual Pet* copy() const override;
};
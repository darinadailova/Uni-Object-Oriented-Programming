#pragma once
#include "Pet.hpp"

class Cat : public Pet {
public:
    Cat(const std::string& name = "");
    virtual void pet() const override;
    virtual void feed() override;
    virtual Pet* copy() const override;
};
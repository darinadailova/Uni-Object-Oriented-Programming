#pragma once
#include "Pet.hpp"

class Snake : public Pet {
public:
    Snake(const std::string& name = "");
    virtual void pet() const override;
    virtual void feed() override;
    virtual Pet* copy() const override;
};
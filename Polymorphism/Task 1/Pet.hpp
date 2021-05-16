#pragma once
#include <string>
#include <iostream>

class Pet {
protected:
    int health;
public:
    std::string name;

    Pet(const std::string& name = "");
    int getHealth() const;
    virtual void pet() const = 0;
    virtual void feed() = 0;
    virtual Pet* copy() const = 0;
    ~Pet() = default;
};
#include "Snake.hpp"

Snake::Snake(const std::string& name) : Pet(name) {
}

void Snake::pet() const {
    Pet::pet();
    std::cout << ": sss\n";
}

void Snake::feed() {
    health += 5;
}

Pet* Snake::copy() const {
    return new Snake(*this);
}
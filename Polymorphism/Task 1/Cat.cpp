#include "Cat.hpp"

Cat::Cat(const std::string& name) : Pet(name) {
}

void Cat::pet() const {
    Pet::pet();
    std::cout << ": purrr\n";
}

void Cat::feed() {
    health += 2;
}

Pet* Cat::copy() const {
    return new Cat(*this);
}

#include "Pet.hpp"

int Pet::getHealth() const {
    return health;
}

Pet::Pet(const std::string& name) : name(name), health(100) {
}

void Pet::pet() const {
    std::cout << "Petting " << name;
}
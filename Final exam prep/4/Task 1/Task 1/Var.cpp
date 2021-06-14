#include "Var.hpp"

Var::Var(char* newName, double newValue) : Expression(newValue) {
    copy(newName);
}

Var::Var(const Var& rhs) {
    this->expressionValue = rhs.expressionValue;
    copy(rhs.name);
}

Var& Var::operator=(const Var& rhs) {
    if (this != &rhs) {
        delete[] name;
        this->expressionValue = rhs.expressionValue;
        copy(rhs.name);
    }

    return *this;
}

Var::~Var() {
    delete[] name;
}

void Var::copy(char* str) {
    int size = std::strlen(str);
    name = new char[size + 1];
    for (int i = 0; i < size; i++) {
        name[i] = str[i];
    }

    name[size] = '\0';
}

double Var::value() const {
    return expressionValue;
}

void Var::print() const {
    std::cout << expressionValue;
}

void Var::setValue(double newValue) {
    expressionValue = newValue;
}

Expression* Var::clone() const { 
    return new Var(*this);
}

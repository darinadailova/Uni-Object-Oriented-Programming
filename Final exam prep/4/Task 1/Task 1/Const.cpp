#include "Const.hpp"

Const::Const(double expressionValue) : Expression(expressionValue) {
}

Const::	Const(const Const& rhs) {
    this->expressionValue = rhs.expressionValue;
}

double Const::value() const {
    return expressionValue;
}

void Const::print() const {
    std::cout << expressionValue;
}

Expression* Const::clone() const { 
    return new Const(*this);
}
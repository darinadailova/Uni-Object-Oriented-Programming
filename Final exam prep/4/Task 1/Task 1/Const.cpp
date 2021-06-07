#include "Const.hpp"

Const::Const(double expressionValue) : Expression(expressionValue) {
}

double Const::value() const {
    return expressionValue;
}

void Const::print() const {
    std::cout << expressionValue << '\n';
}

#include "Product.hpp"

Product::Product(Expression* expression1, Expression* expression2) 
    : ArithmeticalOperation(expression1, expression2) {
}

double Product::value() const { 
    return expressions[0]->value() * expressions[1]->value();
}

void Product::print() const { 
    expressions[0]->print();
    std::cout << " * ";
    expressions[1]->print();
    std::cout << "\nProduct: " << expressions[0]->value() * expressions[1]->value() << '\n';
}
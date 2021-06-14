#include "Summ.hpp"

Summ::Summ(Expression* expression1, Expression* expression2) 
    : ArithmeticalOperation(expression1, expression2) {
}

double Summ::value() const { 
    return expressions[0]->value() + expressions[1]->value();
}

void Summ::print() const { 
    expressions[0]->print();
    std::cout << " + ";
    expressions[1]->print();
    std::cout << "\nSum: " << expressions[0]->value() + expressions[1]->value() << '\n';
}
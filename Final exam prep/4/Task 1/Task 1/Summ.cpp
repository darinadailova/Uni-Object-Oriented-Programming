#include "Summ.hpp"

Summ::Summ(Expression* newExpression1, Expression* newExpression2) {
    expression1Value = newExpression1->value();
    expression2Value = newExpression2->value();
}

double Summ::value() const {
    return expression1Value + expression2Value;
}

void Summ::print() const {
    std::cout << expression1Value + expression2Value << '\n';
}

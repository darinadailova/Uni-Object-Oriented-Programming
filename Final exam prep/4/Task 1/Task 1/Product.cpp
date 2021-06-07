#include "Product.hpp"

Product::Product(Expression* newExpression1, Expression* newExpression2) {
    expression1Value = newExpression1->value();
    expression2Value = newExpression2->value();
}

double Product::value() const {
    return expression1Value + expression2Value;
}

void Product::print() const {
    std::cout << expression1Value + expression2Value << '\n';
}

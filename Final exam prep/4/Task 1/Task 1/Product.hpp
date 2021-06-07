#pragma once
#include "Var.hpp"
#include "Const.hpp"

class Product {
	double expression1Value;
	double expression2Value;
public:
	Product(Expression* newExpression1, Expression* newExpression2);

	double value() const;
	void print() const;
};


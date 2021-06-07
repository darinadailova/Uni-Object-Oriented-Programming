#pragma once
#include "Var.hpp"
#include "Const.hpp"

class Summ {
	double expression1Value;
	double expression2Value;
public:
	Summ(Expression* newExpression1, Expression* newExpression2);

	double value() const;
	void print() const;
};


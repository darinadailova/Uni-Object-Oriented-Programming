#pragma once
#include "Expression.hpp"

class Const : public Expression {
public:
	Const(double expressionValue = 0);
	virtual double value() const override;
	virtual void print() const override;
};


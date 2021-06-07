#pragma once
#include <iostream>

class Expression {
protected:
	double expressionValue;
public:
	Expression(double expressionValue = 0);
	virtual double value() const = 0;
	virtual void print() const = 0;
	virtual ~Expression();
};
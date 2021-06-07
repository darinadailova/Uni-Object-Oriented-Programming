#pragma once
#include "Expression.hpp"
#include <cstring>

class Var : public Expression {
	char* name;
public:
	Var(double newValue = 0, char* newName = nullptr);
	Var(const Var& rhs);
	Var& operator=(const Var& rhs);
	~Var();
	void copy(char* str);

	virtual double value() const override;
	virtual void print() const override;
	void setValue(double newValue);
};


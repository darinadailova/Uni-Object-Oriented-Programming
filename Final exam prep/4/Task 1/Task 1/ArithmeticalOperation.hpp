#pragma once
#include "Expression.hpp"
#include "Const.hpp"
#include "Var.hpp"

class ArithmeticalOperation {
protected:
    Expression* expressions[2];
public:
    ArithmeticalOperation(Expression* expression1 = nullptr, Expression* expression2 = nullptr);
    ArithmeticalOperation(const ArithmeticalOperation& rhs);
    ArithmeticalOperation& operator=(const ArithmeticalOperation& rhs);
    virtual ~ArithmeticalOperation();

    virtual double value() const = 0;
    virtual void print() const = 0;
};
#pragma once
#include "Var.hpp"
#include "Const.hpp"
#include "ArithmeticalOperation.hpp"

class Summ : public ArithmeticalOperation {
public:
    Summ(Expression* expression1 = nullptr, Expression* expression2 = nullptr);
    
    virtual double value() const override;
    virtual void print() const override;
};


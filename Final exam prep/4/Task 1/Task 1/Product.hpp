#pragma once
#include "Var.hpp"
#include "Const.hpp"
#include "ArithmeticalOperation.hpp"

class Product : public ArithmeticalOperation {
public:
    Product(Expression* expression1 = nullptr, Expression* expression2 = nullptr);
    
    virtual double value() const override;
    virtual void print() const override;
};


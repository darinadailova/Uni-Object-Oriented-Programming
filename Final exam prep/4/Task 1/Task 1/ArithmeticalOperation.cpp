#include "ArithmeticalOperation.hpp"

ArithmeticalOperation::ArithmeticalOperation(Expression* expression1, Expression* expression2) {
    if(expression1 != nullptr) {
        expressions[0] = expression1->clone();
    }
    else {
        expressions[0] = new Const();
    }
    if(expression2 != nullptr) {
        expressions[1] = expression2->clone();
    }
    else {
        expressions[1] = new Const();
    }
}

ArithmeticalOperation::ArithmeticalOperation(const ArithmeticalOperation& rhs) {
    this->expressions[0] = rhs.expressions[0]->clone();
    this->expressions[1] = rhs.expressions[1]->clone();
}

ArithmeticalOperation& ArithmeticalOperation::operator=(const ArithmeticalOperation& rhs) {
    if(this != &rhs) {
        delete expressions[0];
        delete expressions[1];
        this->expressions[0] = rhs.expressions[0]->clone();
        this->expressions[1] = rhs.expressions[1]->clone();
    }

    return *this;
}

ArithmeticalOperation::~ArithmeticalOperation() {
    delete expressions[0];
    delete expressions[1];
}
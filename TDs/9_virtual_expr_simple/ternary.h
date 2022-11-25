//
// Created by Florian on 25/11/2022.
//

#ifndef INC_9_VIRTUAL_EXPR_SIMPLE_TERNARY_H
#define INC_9_VIRTUAL_EXPR_SIMPLE_TERNARY_H


#include "expr-abstract.h"

class Ternary_Conditional : public Expr {
    Expr *cond;
    Expr *left;
    Expr *right;

public:
    Ternary_Conditional(Expr *cond, Expr *left, Expr *right) : cond(cond), left(left), right(right) {}

    int eval() const override {
        return cond->eval() ? left->eval() : right->eval();
    }
};

#endif //INC_9_VIRTUAL_EXPR_SIMPLE_TERNARY_H

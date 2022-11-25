//
// Created by Florian on 25/11/2022.
//
#ifndef INC_9_VIRTUAL_EXPR_SIMPLE_EXPR_CONCRETE_H
#define INC_9_VIRTUAL_EXPR_SIMPLE_EXPR_CONCRETE_H


#include "expr-abstract.h"

class Unary_Minus : public Unary_Expr {
public:
    Unary_Minus(Expr *e) : Unary_Expr(e) {}

    int eval() const override {
        return -op->eval();
    }
};

class Constant : public Expr {
    int value;
public :
    Constant(int value) : value(value) {}

    int eval() const override {
        return value;
    }
};

class Factoriel : public Unary_Expr {
public :
    Factoriel(Expr *expr) : Unary_Expr(expr) {}

    int eval() const override {
        int result = 1;
        for (int i = 1; i <= op->eval(); i++) {
            result *= i;
        }
        return result;
    }
};

class Binary_Mult : public Binary_Expr {
public:
    Binary_Mult(Expr *left, Expr *right) : Binary_Expr(left, right) {}

    int eval() const override {
        return opl->eval() * opr->eval();
    }
};

class Binary_Minus : public Binary_Expr {
public:
    Binary_Minus(Expr *left, Expr *right) : Binary_Expr(left, right) {}

    int eval() const override {
        return opl->eval() - opr->eval();
    }
};

class Binary_Plus : public Binary_Expr {
public:
    Binary_Plus(Expr *left, Expr *right) : Binary_Expr(left, right) {}

    int eval() const override {
        return opl->eval() + opr->eval();
    }
};

class Binary_Div : public Binary_Expr {
public:
    Binary_Div(Expr *left, Expr *right) : Binary_Expr(left, right) {}

    int eval() const override {
        if (opr->eval() == 0) {
            throw Expr::ZeroDivide();
        }
        return opl->eval() / opr->eval();
    }
};

class Binary_Mod : public Binary_Expr {
public:
    Binary_Mod(Expr *left, Expr *right) : Binary_Expr(left, right) {}

    int eval() const override {
        if (opr->eval() == 0) {
            throw Expr::ZeroDivide();
        }
        return opl->eval() % opr->eval();
    }
};


#endif //INC_9_VIRTUAL_EXPR_SIMPLE_EXPR_CONCRETE_H

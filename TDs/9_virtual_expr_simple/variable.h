//
// Created by Florian on 25/11/2022.
//
#ifndef INC_9_VIRTUAL_EXPR_SIMPLE_VARIABLE_H
#define INC_9_VIRTUAL_EXPR_SIMPLE_VARIABLE_H


#include <map>
#include "expr-abstract.h"

std::map<string, int> variables = {};

class Variable_Ref : public Expr {
    string name;
    int value;
public:
    Variable_Ref(string name) : name(name), value(0) {}

    int eval() const override {
        return variables[name];
    }

    string getName() const {
        return name;
    }
};


class Assignment : public Expr {
    Variable_Ref *variable;
    Expr *expr;
public:
    Assignment(Variable_Ref *var, Expr *ex) : variable(var), expr(ex) {}

    virtual int eval() const override {
        variables[variable->getName()] = expr->eval();
        return variables[variable->getName()];
    }
};



#endif //INC_9_VIRTUAL_EXPR_SIMPLE_VARIABLE_H

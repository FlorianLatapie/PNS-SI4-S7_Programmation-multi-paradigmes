//=======================================================================
// Basic C++: class Expression
//      Specification and implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: Expr-abstract.h,v 1.1 2005/02/08 10:58:27 jpr Exp $
//=======================================================================

#ifndef _EXPR_ABSTRACT_H_
#define _EXPR_ABSTRACT_H_

#include <stdexcept>
using namespace std;

// The abstract classes

class Expr
{
public:

    class ZeroDivide { };

    virtual ~Expr() {}
    virtual int eval() const = 0;
};

class Unary_Expr : public Expr
{
protected:
    Expr *op;
public:
    Unary_Expr(Expr *pe) : op(pe) {}
};

class Binary_Expr : public Expr
{
protected:
    Expr *opl, *opr;
public:
    Binary_Expr(Expr *pe1, Expr *pe2) : opl(pe1), opr(pe2) {}
};

#endif

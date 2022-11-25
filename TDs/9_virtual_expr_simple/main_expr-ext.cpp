//=======================================================================
// Basic C++: class Expression
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_Expr-ext.cpp,v 1.4 2005/02/08 15:57:10 jpr Exp $
//=======================================================================

#include <iostream>
using namespace std;

#include "expr-abstract.h"
#include "expr-concrete.h"
#include "ternary.h"
#include "variable.h"


// e0 = 3
Expr *pe0 = new Constant(3);


// fe0 = 3!
Expr *pfe0 = new Factoriel(pe0);

// e00 = -e0
Expr *pe00 = new Unary_Minus(pe0);

// e1 = e0*e00
Expr *pe1 = new Binary_Mult(pe0, pe00);

// e2 = -(2 + 3)*4 - 5/2 == -22
Expr *pe2 = new Binary_Minus(
               new Binary_Mult(
                   new Unary_Minus(
                       new Binary_Plus(
                           new Constant(2),
                           new Constant(3)
                        )
                   ),
                   new Constant(4)
               ),
               new Binary_Div(
                   new Constant(5),
                   new Constant(2)
               )
            );


int main()
{
    cout << "e0 = "  << pe0->eval()  << endl;
    cout <<" e0! = " << pfe0->eval() << endl;
    cout << "e00 = " << pe00->eval() << endl;
    cout << "e1 = "  << pe1->eval()  << endl;
    cout << "e2 = "  << pe2->eval()  << endl;

    Expr *pe3 = new Ternary_Conditional(pe1,
                     new Binary_Mod(new Constant(23), new Constant(4)),
                     new Constant(1));
    cout << "e3 = "  << pe3->eval()  << endl;
   

    Variable_Ref *pv = new Variable_Ref("foo");
    cout << "pv = " << pv->eval() << endl;// on suppose que les variables valent zero par défaut
    Expr *pev = new Binary_Plus(pv, new Constant(1));
    Expr *pv1 = new Assignment(pv, pev);
    cout << "pv1 = " << pv1->eval() << endl;
    
}

//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Test of square matrices and their varaitions.
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: main_SquareMatrix.cpp,v 1.1 2004/12/04 18:39:42 jpr Exp $
//=======================================================================

#include <iostream>
using namespace std;

#include "common_defs.h"
#include "SquareMatrix.h"
#include "DiagonalMatrix.h"
#include "ScalarMatrix.h"

int main()
{
    cout << boolalpha;

    MSG(Square Matrices);

    SquareMatrix sqmat0;
    SquareMatrix sqmat1(5);
    SquareMatrix sqmat2(5, 2);
  
    OUT(sqmat0);
    OUT(sqmat1);
    OUT(sqmat2);
    OUT(sqmat1 == sqmat2);
    OUT(sqmat1 == sqmat1);

    OUT(sqmat0 = sqmat1 + sqmat2);

    MSG(Mixing Matrix and SquareMatrix);

    Matrix mat1(5, 5, 2);
    Matrix mat2;
    EXEC(mat2 = mat1 + sqmat2);
    OUT(mat2);
    SquareMatrix sqmat3;
    EXEC(sqmat3 = SquareMatrix(mat1));
    OUT(sqmat3);

    Matrix mat3(5, 10, 2);
    Matrix mat4;
    EXEC(mat4 = sqmat2 * mat3);
    OUT(mat4);
    
    MSG(Diagonal Matrices);

    DiagonalMatrix dmat0;
    DiagonalMatrix dmat1(5);
    MVector mv(5, 2);
    DiagonalMatrix dmat2(mv);
    
    OUT(dmat0);
    OUT(dmat1);
    OUT(dmat2);

    EXEC(sqmat2 += dmat2);
    OUT(sqmat2);

    OUT(sqmat2[1][1]);
    OUT(sqmat2(1, 1));
    OUT(sqmat2[1][2]);

    EXEC(mat4 = sqmat2 * dmat2);
    OUT(mat4);

    MSG(Scalar matrices);

    ScalarMatrix scmat0;
    ScalarMatrix scmat1(5);
    ScalarMatrix scmat2(5, 3);
    
    OUT(scmat0);
    OUT(scmat1);
    OUT(scmat2);
    
    EXEC(scmat0 = scmat2 + scmat2);
    OUT(scmat0);
    EXEC(scmat0 = scmat2 * scmat2);
    OUT(scmat0);
    EXEC(sqmat0 = scmat0);
    OUT(sqmat0);

    EXEC(dmat0 = scmat0);
    OUT(dmat0);

    MSG(Determinant for square matrix);
    OUT( sqmat2.det() );

    MSG(Determinant for diagonal matrix);
    OUT( dmat2.det() );

    MSG(Determinant for scalar matrix);
    OUT( scmat2.det() );

}

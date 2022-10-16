//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Implementation of diagonal matrices
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: DiagonalMatrix.cpp,v 1.1 2004/12/04 18:39:42 jpr Exp $
//=======================================================================

#include "DiagonalMatrix.h"

DiagonalMatrix operator+(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    MVector mv(n);
    for (int i = 0; i < n; ++i)
        mv[i] = mat1[i][i] + mat2[i][i];
    return DiagonalMatrix(mv);
}

DiagonalMatrix operator-(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    MVector mv(n);
    for (int i = 0; i < n; ++i)
        mv[i] = mat1[i][i] - mat2[i][i];
    return DiagonalMatrix(mv);
}
DiagonalMatrix operator*(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    MVector mv(n);
    for (int i = 0; i < n; ++i)
        mv[i] = mat1[i][i] * mat2[i][i];
    return DiagonalMatrix(mv);
}

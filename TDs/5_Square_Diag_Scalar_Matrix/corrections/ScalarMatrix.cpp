//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Implementation of scalar matrices
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: ScalarMatrix.cpp,v 1.2 2004/12/05 12:00:08 jpr Exp $
//=======================================================================

#include "ScalarMatrix.h"

ScalarMatrix operator+(const ScalarMatrix& mat1,const ScalarMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    return n == 0 ? mat1 : ScalarMatrix(n, mat1[0][0] + mat2[0][0]);
}

ScalarMatrix operator-(const ScalarMatrix& mat1,const ScalarMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    return n == 0 ? mat1 : ScalarMatrix(n, mat1[0][0] - mat2[0][0]);
}

ScalarMatrix operator*(const ScalarMatrix& mat1,const ScalarMatrix& mat2)
{
    int n = mat1.size();
    if (n != mat2.size()) throw Matrix::Bad_Dimensions();
    return n == 0 ? mat1 : ScalarMatrix(n, mat1[0][0] * mat2[0][0]);
}

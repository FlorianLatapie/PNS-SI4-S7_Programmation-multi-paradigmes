//
// Created by Florian on 13/10/2022.
//

#ifndef INC_5_SQUARE_DIAG_SCALAR_MATRIX_DIAGONALMATRIX_H
#define INC_5_SQUARE_DIAG_SCALAR_MATRIX_DIAGONALMATRIX_H


#include "SquareMatrix.h"

class DiagonalMatrix : public SquareMatrix {
public:
    DiagonalMatrix(int size = 0, double x = 0.0);
    DiagonalMatrix(const MVector& mVector);
};


#endif //INC_5_SQUARE_DIAG_SCALAR_MATRIX_DIAGONALMATRIX_H

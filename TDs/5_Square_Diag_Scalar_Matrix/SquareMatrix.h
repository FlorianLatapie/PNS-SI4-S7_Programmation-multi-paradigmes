//
// Created by Florian on 13/10/2022.
//

#ifndef INC_5_SQUARE_DIAG_SCALAR_MATRIX_SQUAREMATRIX_H
#define INC_5_SQUARE_DIAG_SCALAR_MATRIX_SQUAREMATRIX_H


#include "Matrix.h"

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size = 0, double x = 0.0);

    SquareMatrix(const Matrix& matrix);
};

#endif //INC_5_SQUARE_DIAG_SCALAR_MATRIX_SQUAREMATRIX_H

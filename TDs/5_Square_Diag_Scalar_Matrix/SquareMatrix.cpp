//
// Created by Florian on 13/10/2022.
//

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(int size, double x) : Matrix(size, size, x) {
}

SquareMatrix::SquareMatrix(const Matrix &matrix) : Matrix(matrix.nlines(), matrix.ncols()){
    if (matrix.ncols() != matrix.nlines()){
        throw Bad_Dimensions();
    }

    static_cast<Matrix&>(*this) = matrix;
}

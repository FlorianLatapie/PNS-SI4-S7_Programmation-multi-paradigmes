//
// Created by Florian on 13/10/2022.
//

#ifndef INC_5_SQUARE_DIAG_SCALAR_MATRIX_SCALARMATRIX_H
#define INC_5_SQUARE_DIAG_SCALAR_MATRIX_SCALARMATRIX_H


#include "DiagonalMatrix.h"

class ScalarMatrix : public DiagonalMatrix {
public:
    ScalarMatrix(int size = 0, double x = 0.0);
    ScalarMatrix(const Matrix& m);
};


#endif //INC_5_SQUARE_DIAG_SCALAR_MATRIX_SCALARMATRIX_H

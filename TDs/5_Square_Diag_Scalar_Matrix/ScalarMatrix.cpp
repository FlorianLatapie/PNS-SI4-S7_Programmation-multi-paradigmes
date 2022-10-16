//
// Created by Florian on 13/10/2022.
//

#include "ScalarMatrix.h"

ScalarMatrix::ScalarMatrix(int size, double x) : DiagonalMatrix(size, x) {
}

ScalarMatrix::ScalarMatrix(const Matrix &m) : DiagonalMatrix(m.nlines()) {
    if (m.ncols() != m.nlines()){
        throw Bad_Dimensions();
    }

    for (int i = 0; i < m.nlines(); ++i) {
        (*this)[i][i] = m[i][i];
    }
}

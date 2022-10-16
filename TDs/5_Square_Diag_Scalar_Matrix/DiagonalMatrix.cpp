//
// Created by Florian on 13/10/2022.
//

#include "DiagonalMatrix.h"
#include "SquareMatrix.h"

DiagonalMatrix::DiagonalMatrix(int size, double x) : SquareMatrix(size, x) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i != j){
                (*this)[i][j] = 0;
            }
        }
    }
}

DiagonalMatrix::DiagonalMatrix(const MVector &mVector) : SquareMatrix(mVector.size()) {
    int size = mVector.size();
    for (int i = 0; i < size; ++i) {
        (*this)[i][i] = mVector[i];
    }
}

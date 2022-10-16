//
// Created by flori on 07/10/2022.
//

#ifndef INC_4_MATRIX_MATRIX_H
#define INC_4_MATRIX_MATRIX_H

#include <iostream>
#include "MVector.h"

class Matrix {
    std::vector<MVector> m;
public:
    Matrix();

    Matrix(int rows, int cols);

    Matrix(int rows, int cols, double value);

    Matrix(MVector v);

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    friend bool operator==(const Matrix &lhs, const Matrix &rhs);

    Matrix &operator+=(const Matrix &rhs);

    Matrix &operator-=(const Matrix &rhs);

    Matrix &operator*=(const Matrix &rhs);

    Matrix operator+(const Matrix &rhs) const;

    Matrix operator-(const Matrix &rhs) const;

    Matrix operator*(const Matrix &rhs) const;

    Matrix operator~() const;


    class Bad_Dimensions {
    };

    Matrix transpose() const;

    double operator()(int i, int j) const;

    double &operator()(int i, int j);

    const MVector &line(int i);

    MVector column(int j);

    double det() const;

    operator MVector(){
        return m[0];
    }
};


#endif //INC_4_MATRIX_MATRIX_H

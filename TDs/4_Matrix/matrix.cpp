//
// Created by flori on 07/10/2022.
//

#include "matrix.h"

Matrix::Matrix() {
    m = std::vector<MVector>();
}

Matrix::Matrix(int rows, int cols) {
    m = std::vector<MVector>();
    for (int i = 0; i < rows; ++i) {
        MVector v(cols, 0);
        m.push_back(v);
    }
}

Matrix::Matrix(int rows, int cols, double value) {
    m = std::vector<MVector>();
    for (int i = 0; i < rows; ++i) {
        MVector v(cols, value);
        m.push_back(v);
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    os << "[\n";
    for (MVector row: matrix.m) {
        os << "  [ ";
        for (int i = 0; i < row.size(); ++i) {
            os << row[i] << " ";
        }
        os << "]\n";
    }
    return os << "]";
}

bool operator==(const Matrix &m1, const Matrix &m2) {
    return m1.m == m2.m;
}

Matrix &Matrix::operator+=(const Matrix &m2) {
    if (m.size() != m2.m.size() || m[0].size() != m2.m[0].size()) {
        throw Bad_Dimensions();
    }
    for (int i = 0; i < m.size(); ++i) {
        m[i] += m2.m[i];
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m2) {
    if (m.size() != m2.m.size() || m[0].size() != m2.m[0].size()) {
        throw Bad_Dimensions();
    }
    for (int i = 0; i < m.size(); ++i) {
        m[i] -= m2.m[i];
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m2) {
    if (m[0].size() != m2.m.size()) {
        throw Bad_Dimensions();
    }
    std::vector<MVector> new_m;
    for (int i = 0; i < m.size(); ++i) {
        MVector v(m2.m[0].size(), 0);
        new_m.push_back(v);
    }
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m2.m[0].size(); ++j) {
            for (int k = 0; k < m[0].size(); ++k) {
                new_m[i][j] += m[i][k] * m2.m[k][j];
            }
        }
    }
    m = new_m;
    return *this;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    if (m.size() != rhs.m.size() || m[0].size() != rhs.m[0].size()) {
        throw Bad_Dimensions();
    }
    Matrix m = *this;
    m += rhs;
    return m;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    Matrix m = *this;
    m -= rhs;
    return m;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    if (m[0].size() != rhs.m.size()) {
        throw Bad_Dimensions();
    }
    Matrix m = *this;
    m *= rhs;
    return m;
}

Matrix Matrix::transpose() const {
    Matrix m2 = Matrix(m[0].size(), m.size());
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            m2.m[j][i] = m[i][j];
        }
    }
    return m2;
}

double Matrix::operator()(int i, int j) const {
    return 0;
}

double &Matrix::operator()(int i, int j) {
    return m[i][j];
}

const MVector &Matrix::line(int i) {
    return m[i];
}

MVector Matrix::column(int j) {
    MVector v(m.size(), 0);
    for (int i = 0; i < m.size(); ++i) {
        v[i] = m[i][j];
    }
    return v;
}


Matrix Matrix::operator~() const {
    return transpose();
}

    double Matrix::det() const {
        if (m.size() != m[0].size()) {
            throw Bad_Dimensions();
        }
        if (m.size() == 1) {
            return m[0][0];
        }
        if (m.size() == 2) {
            return m[0][0] * m[1][1] - m[0][1] * m[1][0];
        }
        double d = 0;
        for (int i = 0; i < m.size(); ++i) {
            Matrix m2 = Matrix(m.size() - 1, m.size() - 1);
            for (int j = 1; j < m.size(); ++j) {
                for (int k = 0; k < m.size(); ++k) {
                    if (k < i) {
                        m2.m[j - 1][k] = m[j][k];
                    } else if (k > i) {
                        m2.m[j - 1][k - 1] = m[j][k];
                    }
                }
            }
            d += m[0][i] * m2.det() * (i % 2 == 0 ? 1 : -1);
        }
        return d;
    }

Matrix::Matrix(MVector v) {
    m = std::vector<MVector>();
    m.push_back(v);
}







//
// Created by flori on 29/09/2022.
//

#include <vector>
#include "MVector.h"
#include <math.h>


MVector::MVector(int coef, double value) {
    v = std::vector<double>();
    for (int i = 0; i < coef; ++i) {
        v.push_back(value);
    }
}

MVector::MVector() {
    v = std::vector<double>();
}

MVector::MVector(std::vector<double> vv) {
     v = vv;
}

double MVector::norm() {
    double sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i] * v[i];
    }
    return sqrt(sum);
}

std::ostream &operator<<(std::ostream &os, const MVector &mVector) {
    os << "[ ";
    for (double i: mVector.v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

bool MVector::operator==(const MVector &rhs) const {
    return v == rhs.v;
}

MVector MVector::operator+=(const MVector &rhs) {
    for (int i = 0; i < v.size(); ++i) {
        v[i] += rhs.v[i];
    }
    return *this;
}

MVector MVector::operator-=(const MVector &rhs) {
    for (int i = 0; i < v.size(); ++i) {
        v[i] -= rhs.v[i];
    }
    return *this;
}

MVector MVector::operator+(const MVector &rhs) const{
    if (rhs.v.size() != v.size()){
        throw Bad_Dimensions();
    }
    MVector ret = *this;
    for (int i = 0; i < v.size(); ++i) {
        ret[i] += rhs.v[i];
    }
    return ret;
}

MVector MVector::operator-(const MVector &rhs) const{
    MVector ret = *this;

    for (int i = 0; i < v.size(); ++i) {
        ret[i] -= rhs.v[i];
    }
    return ret;
}

double MVector::operator[](int i) const {
    return v[i];
}

double operator*(const MVector &lhs, const MVector &rhs){
    double sum = 0;
    for (int i = 0; i < lhs.v.size(); ++i) {
        sum += lhs.v[i] * rhs.v[i];
    }
    return sum;
}

double &MVector::operator[](int i) {
    return v[i];
}

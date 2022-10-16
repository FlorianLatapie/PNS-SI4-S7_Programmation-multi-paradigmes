//
// Created by flori on 29/09/2022.
//

#ifndef INC_3_MVECTOR_MVECTOR_H
#define INC_3_MVECTOR_MVECTOR_H

#include <vector>
#include <ostream>

class MVector {
    std::vector<double> v;
public:
    MVector();
    MVector(int coef, double value);
    MVector(std::vector<double> v);

    double norm();

    friend std::ostream &operator<<(std::ostream &os, const MVector &mVector);

    bool operator==(const MVector &rhs) const;
    MVector operator+=(const MVector &rhs) ;
    MVector operator-=(const MVector &rhs);

    MVector operator+(const MVector &rhs)const;
    MVector operator-(const MVector &rhs)const;

    double operator[](int i) const;
    double &operator[](int i);

    friend double operator*(const MVector &lhs, const MVector &rhs);

    class Bad_Dimensions{};
};

double operator*(const MVector &lhs, const MVector &rhs);


#endif //INC_3_MVECTOR_MVECTOR_H

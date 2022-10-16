//=======================================================================
// Basic C++: a simple mathematical vector class
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: MVector.cpp,v 1.2 2004/11/28 16:50:16 jpr Exp $
//=======================================================================

#include "MVector.h"

/*!
 *  No surprise here: we simply call the adequate constructor of std::vector.
 *
 *  \param n number of elements 
 *  \param x the common value to initialize all components with
  */
MVector::MVector(int n, double x)
    : _ncomps(n), _components(n, x) 
{
    // Nothing else to do
}

/*!
 * We use the scalar product of the vector by itself.
 *
 * \note The syntax may seem strange, due to so many stars!
 */
double MVector::norm() const 
{  
    return *this * *this;  
}


/*!
 * To check for equality, simply use operator== for std::vector.
 */
bool operator==(const MVector& mv1, const MVector& mv2)
{
    if (mv1._ncomps != mv2._ncomps) return false;
    return mv1._components == mv2._components;
}

/*!
 * Since std::vector have no arithmetic operations, we have to do it ourselves.
 */
MVector operator+(const MVector& mv1, const MVector& mv2)
{
    if (mv1._ncomps != mv2._ncomps) throw MVector::Bad_Dimensions();

    int n = mv1._ncomps;
    MVector mv(n);    
    for (int i = 0; i < n; ++i)
        mv._components[i] = mv1._components[i] + mv2._components[i];
    return mv;
}

/*!
 * Since std::vector have no arithmetic operations, we have to do it ourselves.
 */
MVector operator-(const MVector& mv1, const MVector& mv2)
{
    if (mv1._ncomps != mv2._ncomps) throw MVector::Bad_Dimensions();

    int n = mv1._ncomps;
    MVector mv(n);    
    for (int i = 0; i < n; ++i)
        mv._components[i] = mv1._components[i] - mv2._components[i];
    return mv;
}

/*!
 * Since std::vector have no arithmetic operations, we have to do it ourselves.
 */
double operator*(const MVector& mv1, const MVector& mv2)
{
    if (mv1._ncomps != mv2._ncomps) throw MVector::Bad_Dimensions();

    int n = mv1._ncomps;
    double prod = 0.0;
    for (int i = 0; i < n; ++i)
        prod += mv1._components[i] * mv2._components[i];
    return prod;
}

double& MVector::operator[](int i)
{
    if (i < 0 || i >= _ncomps) throw Out_Of_Bounds();
    return _components[i];
}

double MVector::operator[](int i) const
{
    if (i < 0 || i >= _ncomps) throw Out_Of_Bounds();
    return _components[i];
}

/*!
 *  Enclose the list of component values between square brackets.
 */
ostream& operator<<(ostream& os, const MVector& mv)
{
    os << "[ ";
    for (int i = 0; i < mv._ncomps; ++i)
        os << mv._components[i] << ' ';
    os << ']';
    return os;
}

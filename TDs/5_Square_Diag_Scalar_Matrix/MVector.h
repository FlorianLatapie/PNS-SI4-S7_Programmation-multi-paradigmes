//=======================================================================
// Basic C++: a simple mathematical vector class
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: MVector.h,v 1.2 2004/11/28 16:50:16 jpr Exp $
//=======================================================================

#ifndef _MVECTOR_H_
#define _MVECTOR_H_

#include <iostream>
#include <vector>
using namespace std;

/*! \class MVector
 *
 * \brief Simple mathematical vectors as used in linear algebra.
 *
 * MVector is implemented using an STL vector<double>.
*/

class MVector
{
private:

    int _ncomps;		//!< number of elements (redundant yet convenient)
    vector<double> _components;	//!< the std::vector containing the elements
   
public:

    //! \class Index out of range exception.
    class Out_Of_Bounds {};

    //! \class Operation on vectors with incorrect dimensions exception.
    class Bad_Dimensions {};

    /*! \name Constructors, destructor, and conversions
     *
     *  \note No need for an explicit destructor nor for an explicit copy
     *  constructor: the default ones, automatically provided by C++, are fine.
     *
     * @{
     */

    //!Constructor (also usable as default constructor).
    MVector(int n = 0, double x = 0.0);

    /*@}*/

    /*! \name Assignments
     *
     *  \note No need for a copy assignment operator; the default one,
     *  automatically provided by C++ is fine.
     * 
     * @{
     */
    MVector& operator+=(const MVector& mv) {return *this = *this + mv;}
    MVector& operator-=(const MVector& mv) {return *this = *this - mv;}

    /*@}*/
    
    /*! \name Accessors
     *
     * @{
     */
    //! Number of elements.
    int ncomps() const {return _ncomps;}
    //! Number of elements.
    int size() const {return ncomps();}

    //! Compute the Euclidian norm of the vector.
    double norm() const;

    /*@}*/

    /*! \name Arithmetic operations
     *
     * @{
     */
    //! Addition.
    friend MVector operator+(const MVector& mv1, const MVector& mv2);
    //! Subtraction.
    friend MVector operator-(const MVector& mv1, const MVector& mv2);
    //! Scalar product.
    friend double operator*(const MVector& mv1, const MVector& mv2);
    //! Another denotation for scalar product.
    friend double dot(const MVector& mv1, const MVector& mv2)
    {
        return mv1 * mv2; 
    }    

    /*@}*/

    /*! \name Relational operations
     *
     * @{
     */
    //! Equality.
    friend bool operator==(const MVector& mv1, const MVector& mv2);
    //! Unequality.
    friend bool operator!=(const MVector& mv1, const MVector& mv2)
    {
        return ! (mv1 == mv2);
    }

    /*@}*/

    /*! \name Subscript
     *
     * @{
     */
    //! Subscript for non-constant vectors.
    double& operator[](int i);
    //! Subscript for constant vectors.
    double operator[](int i) const;

    /*@}*/

    //! IO operation: just display the contents.
    friend ostream& operator<<(ostream& os, const MVector& mv);
};

#endif

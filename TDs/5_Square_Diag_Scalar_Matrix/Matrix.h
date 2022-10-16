//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: Matrix.h,v 1.2 2004/11/28 16:50:16 jpr Exp $
//=======================================================================

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
using namespace std;

#include "common_defs.h"
#include "MVector.h"

/*! \class Matrix
 *
 * \brief Simple mathematical matrices as used in linear algebra.
 *
 * A Matrix is implemented as an STL vector (std::vector) of MVector's.
*/

class Matrix
{
private:

    int _nlines;		//!< Number of lines.
    int _ncols;			//!< Number of columns.
    vector<MVector> _lines;	//!< The elements themselves.
   
public:

    //! \class Index out of range exception.
    class Out_Of_Bounds {};

    //! \class Operation on vectors with incorrect dimensions exception.
    class Bad_Dimensions {};

    /*! \name Contructors, destructor, and conversions
     *
     *  \note No need for an explicit destructor nor for an explicit copy
     *  constructor: the default ones, automatically provided by C++, are fine.
     *
     * @{
     */

    //! Constructor (also usable as default constructor).
    Matrix(int nl = 0, int nc = 0, double x = 0.0); 

    //! Constructor creating a Matrix from a MVector. 
    Matrix(MVector mv, bool transp = false); 

    //! Conversion operator creating a MVector from a Matrix. 
    operator MVector() const;  

    //! Extract a column.
    MVector column(int j) const; 

    //! Extract a line.
    MVector line(int i) const;

    /*@}*/

    /*! \name Assignments
     *
     *  \note No need for a copy assignment operator; the default one,
     *  automatically provided by C++ is fine.
     * 
     * @{
     */
    Matrix& operator+=(const Matrix& mat) {return *this = *this + mat;}
    Matrix& operator-=(const Matrix& mat) {return *this = *this - mat;}
    Matrix& operator*=(const Matrix& mat) {return *this = *this * mat;}

     /*@}*/
    
    /*! \name Accessors
     *
     * @{
     */
    //! Number of lines.
    int nlines() const {return _nlines;}
    //! Number of columns.
    int ncols() const {return _ncols;}

     /*@}*/

    //! Transpose the matrix.
    /*!
     * \return a copy of the matrix, but transposed
     */
    Matrix transpose() const;
    //! Another denotation for transpose
    Matrix operator~() const {return transpose();}

    /*! \name Arithmetic operations
     *
     * @{
     */
    //! Addition.
    friend Matrix operator+(const Matrix& mat1, const Matrix& mat2);
    //! Subtraction.
    friend Matrix operator-(const Matrix& mat1, const Matrix& mat2);
    //! Product.
    friend Matrix operator*(const Matrix& mat1, const Matrix& mat2);

    /*@}*/

    /*! \name Relational operations
     *
     * @{
     */
    //! Equality.
    friend bool operator==(const Matrix& mat1, const Matrix& mat2);
    //! Unequality.
    friend bool operator!=(const Matrix& mat1, const Matrix& mat2)
    {
        return ! (mat1 == mat2);
    }

    /*@}*/

    /*! \name Subscript
     *
     *  \exception Out_Of_Bounds thrown if index is outside range
     *
     * @{
     */
    //! A reference to the line at index i (version for a non-constant matrix).
    MVector& operator[](int i);
    //! A reference to the line at index i (version for a constant matrix).
    const MVector& operator[](int i) const;

    //! Access to element at indexes (i,j) (version for a non-constant matrix).
    double& operator()(int i, int j);
    //! Access to element at indexes (i,j) (version for aconstant matrix).
    double operator()(int i, int j) const;
    //! Another denotation for at(i,j) (version for a non-constant matrix).
    double& at(int i, int j) {return (*this)(i, j);}
    //! Another denotation for at(i,j) (version for a constant matrix).
    double at(int i, int j) const {return (*this)(i, j);}

    /*@}*/

    //! IO operation: just display the contents.
    friend ostream& operator<<(ostream& os, const Matrix& mat);

    double det() const;
};

#endif

//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Specification (and implementation) of square matrices
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: SquareMatrix.h,v 1.3 2004/12/05 15:22:56 jpr Exp $
//=======================================================================

#ifndef _SQUAREMATRIX_H_
#define _SQUAREMATRIX_H_

#include "Matrix.h"

/*! \class SquareMatrix
 *
 * \brief Simple mathematical square matrices as used in linear algebra.
 *
 * Class SquareMatrix simply derives from Matrix. The following remarks apply:
 * 	- There is no need for local data members, thus the default copy
 *	  operations are sound (they invoke the ones of Matrix).
 *	- The subscripting operations of Matrix are fine too.
 */

class SquareMatrix : public Matrix
{
public:

    /*! \name Contructors, destructor, and conversions
     *
     *  \note The other constructor of Matrix is not adequate for sqare
     *  matrices. The conversion operator to MVector is not either. (In fact
     *  they are adequate in the case where the length of the MVector is 1, a
     *  special case that we do not consider here).
     *
     * @{
     */

    //! Regular constructor (also usable as default constructor).
    SquareMatrix(int n = 0, double x = 0.0)
        : Matrix(n, n, x)
    {}

    //! Construct a square matrix from a regular matrix when the latter is in
    //  fact square.
    /*!  This operator is useful (but not indispensible) to implement the
     *  arithmetic operators by simply calling the corresponding Matrix
     *  operator.
     *
     *  \note This is an explicit constructor to avoid create an ambiguity when
     *  mixing Matrix and SquareMatrix with the arithmetic operators (+, -,
     *  *). Indeed, if the conversion were implicit, then <tt>sqmat + mat</tt>
     *  could mean either <tt>sqmat + SquareMatrix(mat)</tt> (a SquareMatrix
     *  result) or <tt>Matrix(sqmat) + mat</tt> (a Matrix result). Only the
     *  latter is the intended implementation.  This is required by the ISO C++
     *  standard apparently, although it is bizarre: indeed converting a
     *  diagonal to a regular matrix is a standard (inheritance) conversion
     *  whereas the opposite is here a user conversion; the first should win
     *  (and seems to do in gcc before version 3.4?).
     */
    explicit SquareMatrix(const Matrix& mat)
    {
        if (mat.nlines() != mat.ncols()) throw Bad_Dimensions();
        static_cast<Matrix&>(*this) = mat;
    }

    //! Conversion operator creating a MVector from a Matrix.
    operator MVector() const
    {
        throw Bad_Dimensions();
    }

   /*@}*/

    //! Square matrix dimension.
    int size() const {return nlines();}

    /*! \name Arithmetic operations
     *
     * \note These operations are redefined here since the sum, difference, and
     * product of two square matrices is a square matrix. We use the operators
     * in Matrix, and, since we know that the result is a square matrix, we are
     * allowed to static cast the result downwards.
     *
     * @{
     */

    //! Addition.
    friend
    SquareMatrix operator+(const SquareMatrix& mat1, const SquareMatrix& mat2)
    {
        return static_cast<SquareMatrix>(
            static_cast<const Matrix&>(mat1) + static_cast<const Matrix&>(mat2));
    }

    //! Subtraction.
    friend
    SquareMatrix operator-(const SquareMatrix& mat1, const SquareMatrix& mat2)
    {
        return static_cast<SquareMatrix>(
            static_cast<const Matrix&>(mat1) - static_cast<const Matrix&>(mat2));
    }

    //! Product.
    friend
    SquareMatrix operator*(const SquareMatrix& mat1, const SquareMatrix& mat2)
    {
        return static_cast<SquareMatrix>(
            static_cast<const Matrix&>(mat1) * static_cast<const Matrix&>(mat2));
    }

    // return sub matrix without line number l
    //  
    Matrix sub_matrix_wo_line(int l) const
    {   
        Matrix r(_nlines-1,_ncols);

        if (l<0 || l>_nlines) throw Out_Of_Bounds();
        for (int i=0; i<l; i++) r[i] = _lines[i]; 
        for (int i=l+1; i<_nlines; i++) r[i-1] = _lines[i]; 
        return r;
    }   

    // return sub matrix without col number c
    //  
    Matrix sub_matrix_wo_col(int c) const
    {   
        return transpose() . sub_matrix_wo_line(c ) . transpose();
    }   


    // det
    //
    double det() const;

    /*@}*/
};

#endif

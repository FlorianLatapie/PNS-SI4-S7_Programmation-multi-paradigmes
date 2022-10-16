//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Specification of diagonal matrices
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: DiagonalMatrix.h,v 1.3 2004/12/05 15:22:56 jpr Exp $
//=======================================================================

#ifndef _DIAGONALMATRIX_H_
#define _DIAGONALMATRIX_H_

#include "SquareMatrix.h"

/*! \class DiagonalMatrix
 *
 * \brief Simple mathematical diagonal matrices as used in linear algebra.
 *
 * Class DiagonalMatrix simply derives from SquareMatrix. 
*/

class DiagonalMatrix : public SquareMatrix
{
public:

    /*! \name Contructors, destructor, and conversions
     *
     * @{
     */

    //! First constructor (also usable as default constructor).
    /*! It creates the nul matrix. */
    DiagonalMatrix(int n = 0)
        : SquareMatrix(n)
    {}

    //! Second constructor.
    /*! It creates a diagonal matrix from an MVector.
     *
     * \note As an implicit conversion operator, this constructor may be in
     * conflict with the same one in Matrix, since they construct different
     * objects. 
     */
    DiagonalMatrix(const MVector& mv)
        : SquareMatrix(mv.size())
    {
        for (int i = 0; i < mv.size(); ++i)
            (*this)(i, i) = mv[i];
    }

   /*@}*/


    /*! \name Arithmetic operations
     *
     * \note These operations are redefined here since the sum, difference, and
     * product of two diagonal matrices is a diagonal matrix. We do not use
     * the operators in Matrix, since we can give a better (faster)
     * implementation..
     *
     * @{
     */

    //! Addition.
    friend
    DiagonalMatrix operator+(const DiagonalMatrix& mat1,const DiagonalMatrix& mat2);

    //! Subtraction.
    friend
    DiagonalMatrix operator-(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2);

    //! Product.
    friend
    DiagonalMatrix operator*(const DiagonalMatrix& mat1, const DiagonalMatrix& mat2);

    /*@}*/
};

#endif

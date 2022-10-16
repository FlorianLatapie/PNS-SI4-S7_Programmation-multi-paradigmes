//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Specification of scalar matrices
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: ScalarMatrix.h,v 1.2 2004/12/05 07:15:21 jpr Exp $
//=======================================================================

#ifndef _SCALARMATRIX_H_
#define _SCALARMATRIX_H_

#include "DiagonalMatrix.h"

/*! \class ScalarMatrix
 *
 * \brief Simple mathematical scalar matrices as used in linear algebra.
 *
 * Class ScalarMatrix simply derives from DiagonalMatrix. The following remarks apply:
 * 	- There is no need for local data members, thus the default copy
 *	  operations are sound (they invoke the ones of Matrix).
 *	- The subscripting operations of Matrix are fine too.
 *	- 
*/

class ScalarMatrix : public DiagonalMatrix
{
public:

    /*! \name Contructors, destructor, and conversions
     *
     * @{
     */

    //! Constructor (also usable as default constructor).
    /*! It creates the nul matrix. */
    ScalarMatrix(int n = 0, double x = 0.0)
        : DiagonalMatrix(MVector(n, x))
    {}

   /*@}*/


    /*! \name Arithmetic operations
     *
     * \note These operations are redefined here since the sum, difference, and
     * product of two scalar matrices is a scalar matrix. We give a direct
     * (faster) implementation.
     *
     * @{
     */

    //! Addition.
    friend
    ScalarMatrix operator+(const ScalarMatrix& mat1,const ScalarMatrix& mat2);

    //! Subtraction.
    friend
    ScalarMatrix operator-(const ScalarMatrix& mat1, const ScalarMatrix& mat2);

    //! Product.
    friend
    ScalarMatrix operator*(const ScalarMatrix& mat1, const ScalarMatrix& mat2);

    /*@}*/
};

#endif

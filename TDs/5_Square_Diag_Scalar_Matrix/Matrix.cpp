//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: Matrix.cpp,v 1.3 2005/02/08 09:28:40 jpr Exp $
//=======================================================================

#include "Matrix.h"


/*!  
 *  The matrix is implemented as a std::vector of MVector's. Each MVector
 *  represents a line of the matrix. They have all the same size (which is the
 *  number of columns).
 *
 *  All MVector's are first created empty, then they are assigned to a
 *  temporary MVector (mv) with the correct initial values.
 *
 *  \param nl number of lines
 *  \param nc number of columns
 *  \param x the common value to initialize all components with
 *
 */
Matrix::Matrix(int nl,int nc,  double x)
    : _nlines(nl), _ncols(nc), _lines(nl, MVector(nc, x))
{
}

/*!  
 * 
 *  When called with only one parameter, this constructor aims at converting
 *  implicitely an MVector into a Matrix.
 *
 *  \param mv the MVector to convert
 *  \param transp if true the matrix will be a line-matrix; otherwise
 *  it will be a column-one (it uses transpose())
 */
Matrix::Matrix(MVector mv, bool transp)
    : _nlines(1),
      _ncols(mv.size()),
      _lines(_ncols)
{
    _lines[0] = mv;
    if (transp)
        transpose();
}

/*! 
 *  This operator creates an MVector from a Matrix, provided that one dimension
 *  of the matrix is exactly 1.
 *
 *  \exception Bad_Dimensions thrown if the above constraint is not fulfilled
 */
Matrix::operator MVector() const
{
    if (_nlines == 1) return _lines[0];
    else if (_ncols == 1)
        return column(0);
    else throw Bad_Dimensions();
}

/*! 
 * Return a copy of the column at index j, as an MVector.
 *
 * \exception Out_Of_Bounds no such column
 */
MVector Matrix::column(int j) const
{
    if (j < 0 || j >= _ncols) throw Out_Of_Bounds();
    MVector mv(_nlines);
    for (int i = 0; i < _nlines; ++i)
        mv[i] = _lines[i][j];
    return mv;
}

/*! 
 * Return a copy of the line at index i, as an MVector.

 * \exception Out_Of_Bounds no such line
 */
MVector Matrix::line(int i) const
{
    if (i < 0 || i >= _nlines) throw Out_Of_Bounds();
    return _lines[i];
}

/*!
 * Transpose the matrix (swap lines and columns).
 */
Matrix Matrix::transpose() const
{
    Matrix mat(_ncols, _nlines);
    for (int i = 0; i < _ncols; ++i)
	{
        mat._lines[i] = column(i);
	}
    return mat;    
}

/*!
 *  \exception Bad_Dimensions thrown if the matrix dimensions are different
 */
Matrix operator+(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1._nlines != mat2._nlines || mat1._ncols != mat2._ncols) 
        throw Matrix::Bad_Dimensions();

    int nl = mat1._nlines;
    int nc = mat1._ncols;
    Matrix mat(nl, nc);    
    for (int i = 0; i < nl; ++i)
        mat._lines[i] = mat1._lines[i] + mat2._lines[i];
    return mat;
}

/*!
 *  \exception Bad_Dimensions thrown if the matrix dimensions are different
 */
Matrix operator-(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1._nlines != mat2._nlines || mat1._ncols != mat2._ncols) 
        throw Matrix::Bad_Dimensions();

    int nl = mat1._nlines;
    int nc = mat1._ncols;
    Matrix mat(nl, nc);    
    for (int i = 0; i < nl; ++i)
        mat._lines[i] = mat1._lines[i] - mat2._lines[i];
    return mat;
}

/*!
 *  \exception Bad_Dimensions thrown if the matrix dimensionsdo not fit
 */
Matrix operator*(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1._ncols != mat2._nlines) 
        throw Matrix::Bad_Dimensions();

    int nl = mat1._nlines;
    int nc = mat2._ncols;
    Matrix mat(nl, nc); 
    for (int i = 0; i < nl; ++i)
        for (int j = 0; j < nc; ++j)
            mat._lines[i][j] = mat1.line(i) * mat2.column(j);
    return mat;
}

/*!
 *  \note We use MVector equality
 */
bool operator==(const Matrix& mat1, const Matrix& mat2)
{
    if (mat1._nlines != mat2._nlines) return false;
    for (int i = 0; i < mat1._nlines; ++i)
        if (mat1._lines[i] != mat2._lines[i]) return false;
    return true;
}

/*!
 *  This operator makes it possible to use double indexing with a Matrix
 *  (mat[i][ j])
 */
MVector& Matrix::operator[](int i)
{
    if (i < 0 || i >= _nlines) throw Out_Of_Bounds();
    return _lines[i];
}

/*!
 *  This operator makes it possible to use double indexing with a Matrix
 *  (mat[i][ j])
 */
const MVector& Matrix::operator[](int i) const
{
    if (i < 0 || i >= _nlines) throw Out_Of_Bounds();
    return _lines[i];
}


double& Matrix::operator()(int i, int j)
{
    if (i < 0 || i >= _nlines || j < 0 || j >= _ncols) throw Out_Of_Bounds();
    return _lines[i][j];
}

double Matrix::operator()(int i, int j) const
{
    if (i < 0 || i >= _nlines || j < 0 || j >= _ncols) throw Out_Of_Bounds();
    return _lines[i][j];
}

/*!
 *  We print each line of the matrix as an MVector on a single line. The whole
 *  matrix is also encolsed within square brackets.
 */
ostream& operator<<(ostream& os, const Matrix& mat)
{
    os << "[\n";
    for (int i = 0; i < mat._nlines; ++i)
        os << "  " << mat._lines[i] << '\n';
    os << ']';
    return os;
}

double Matrix::det() const {
    if (_lines.size() != _lines[0].size()) {
        throw Bad_Dimensions();
    }
    if (_lines.size() == 1) {
        return _lines[0][0];
    }
    if (_lines.size() == 2) {
        return _lines[0][0] * _lines[1][1] - _lines[0][1] * _lines[1][0];
    }
    double d = 0;
    for (int i = 0; i < _lines.size(); ++i) {
        Matrix m2 = Matrix(_lines.size() - 1, _lines.size() - 1);
        for (int j = 1; j < _lines.size(); ++j) {
            for (int k = 0; k < _lines.size(); ++k) {
                if (k < i) {
                    m2._lines[j - 1][k] = _lines[j][k];
                } else if (k > i) {
                    m2._lines[j - 1][k - 1] = _lines[j][k];
                }
            }
        }
        d += _lines[0][i] * m2.det() * (i % 2 == 0 ? 1 : -1);
    }
    return d;
}

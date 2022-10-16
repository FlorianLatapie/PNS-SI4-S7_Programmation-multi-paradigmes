#include "SquareMatrix.h"

// TO BE optimized !
double SquareMatrix::det() const
{
	double r=0;
	int k=1;

	if (_nlines==0) throw Bad_Dimensions();
	if (_nlines == 1) return _lines[0][0];

	Matrix sub = sub_matrix_wo_line(0);
	for (int i=0; i< _ncols; i++, k*=-1)
		r += k * line(0)[i] * SquareMatrix( sub.sub_matrix_wo_col(i) ).det();

	return r;
}

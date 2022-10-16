//=======================================================================
// Basic C++: a simple mathematical matrix class
//      Test
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: main_Matrix.cpp,v 1.2 2004/11/28 16:50:16 jpr Exp $
//=======================================================================

#include "common_defs.h"
#include "Matrix.h"

int main()
{
    cout << boolalpha; // pour afficher les booleens

    MSG(Constructors);

    Matrix mat0;
    Matrix mat1(5, 5, 1.5);

	// first implement accessor operator[](int i) const
	// ... and modifier operator[](int i)

    OUT(mat0);
    OUT(mat1);
    OUT(mat1 == mat0);

    MSG(Assignments);

    EXEC(mat0 = mat1);
    OUT(mat0);
    OUT(mat1 == mat0);
    OUT(mat1 += mat1);
    OUT(mat1 -= mat1);
    OUT(mat0 *= mat0);

    MSG (Arithmetic operations); 

    OUT(mat0 + mat0);
    OUT(mat0 - mat0);
    OUT(mat0 * mat0);

    try
    {
        Matrix mat(10, 10);
        OUT(mat0 + mat);
    }
    catch (Matrix::Bad_Dimensions)
    {
        cerr << "*** Bad dimensions" << endl;
    }

    try
    {
        Matrix mat(5, 10, 3.0);
        OUT(mat0 * mat);
        OUT(mat0 * mat.transpose());        
    }
    catch (Matrix::Bad_Dimensions)
    {
        cerr << "*** Bad dimensions" << endl;
    }
    
    MSG (Subscript and transpose);

    Matrix mat2(3, 4);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            mat2(i,j) = i;
    OUT(mat2);
    OUT(mat2.transpose());    
    OUT(~mat2);	// another notation for transpose : define operator~
    EXEC(mat2(0, 0) = 2.75); // define operator() (accessor and modifier)
    OUT(mat2(0, 0));

    MSG(Conversion between Matrices and MVectors);

    OUT(mat2.line(1));
    OUT(mat2.transpose().column(1));

    MVector mv(5, 2.5);
    Matrix mat3 = mv; // define conversion constructor
    OUT(mat3);
    OUT(mat3.transpose());
     
    EXEC(mv = mat3); // define conversion operator (only for 1 line or 1 col matrix of course)
    OUT(mv);
    OUT(static_cast<MVector>(mv));
   
    return 0;
}

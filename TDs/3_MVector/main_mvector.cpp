//=======================================================================
// Basic C++: a simple mathematical vector class
//      Test
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2004
// $Id: main_MVector.cpp,v 1.1 2004/11/28 11:38:07 jpr Exp $
//=======================================================================

#include "common_defs.h"
#include "MVector.h"

int main()
{
    MSG(Constructors);

	// HINT: use vector constructors (see cppreference on vector)

    MVector mv0; // initializes mv0 to [ ] (the empty MVector)
    MVector mv1(5, 1.5); // initializes mv1 to [1.5 1.5 ...1.5] with n coefs
    vector<double> vv(3, 3.14);
    MVector mv3(vv); // initialiazes mv3 with the coefs of vv

    OUT(mv0);
    OUT(mv1);
    OUT(mv0 == mv1);

	// HINT: first implement operator[] accessor AND operator[] modifier
	// so you can use it in your code

    MSG(Assignments);

    EXEC(mv0 = mv1);
    OUT(mv0);
    OUT(mv0 == mv1);
    OUT(mv1 += mv1);
    OUT(mv1 -= mv1);

    MSG (Scalar product and norm);

    OUT(mv0 * mv0);
    OUT(mv0.norm());

    MSG(Arithmetic operations);

    OUT(mv0 + mv0);
    OUT(mv0 - mv0);

	try { mv0+MVector(1,2.5); }
	catch ( MVector::Bad_Dimensions ) { cout << "*** Bad dimensions" << endl; }

    MSG(Subscript);

    EXEC(mv0[2] = 5.5);
    OUT(mv0[2]);

    const MVector cmv = mv1;
    OUT(cmv[2]);
    // cmv[2] = 3.5; DOES NOT COMPILE. WHY?

	OUT(mv3 * vv); // implicit conversion of second argument
	OUT(vv * mv3); // implicit conversion of first argument

    return 0;
}

//=======================================================================
// Basic C++: classe Date
//      Utilization of class Date
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_Date.cpp,v 1.3 2004/11/07 10:52:52 jpr Exp $
//=======================================================================

#include "common_defs.h"
#include "date.h"

int main()
{
    Date d0; // default initialization (eg your bith date)

    MSG(Default Constructors and Display);

    OUT(d0);

    MSG(Arithmetic operations);

    for (int i = 0; i <= 31; i++) OUT(d0 + i); // return date d0 plus i days to date d0

    Date d1(2003, 12, 31); // initialization to Dec 31. 2003
    OUT(d1);
    OUT(d1 + 0);
    OUT(d1 + 2);
    OUT(d1 + 365);

    Date d2(2003, 2, 1);
    OUT(d2);
    OUT(d2 - 0); // return date d2 minus 0 day
    OUT(d2 - 1); // return date d2 minus 1 day
    OUT(d2 - 2); // return date d2 minus 2 day

    for (int i = 0; i <= 31; i++) OUT(d0 - i);

    Date d3(2003, 1, 1);
    OUT(d3);
    OUT(d3 - 1);
    OUT(d3 - 365);


	cout << (d0 += 2);
	cout << d0;

	cout << (d0 -= 2);
	cout << d0;

    MSG(Relational operators);
    OUT(Date(2004, 3, 20) == Date(2004, 12, 8));
    OUT(Date(2004, 3, 20) != Date(2004, 12, 8));
    OUT(Date(2004, 3, 20) <= Date(2004, 12, 8));
    OUT(Date(2004, 12, 8) < Date(2004, 3, 25));
    OUT(Date(2004, 12, 8) < Date(2004, 3, 20) + 5);

    OUT(d0 - (d0 + 1)); // return the number of days between two dates
    OUT(d0 - (d0 - 1));
    Date d4(2002, 12, 31);
    OUT(d3);
    OUT(d4);
    OUT(d3 - d4);
    OUT(d4 - d3);
    OUT(d4 - (d4 + 366));

    OUT(Date(2003, 2, 10) - Date(2003, 6, 12));

    Date d5(2003, 5, 10);
    OUT(d5 + 5);

    Date din;
    cout << "Enter a date (yyyy/mm/dd, terminate with EOF): " << flush;

	while (cin >> din) 
	{
		OUT(din);
		cout << "Enter a date (yyyy/mm/dd, terminate with EOF): " << flush;
	}

	// side effect operator
	cout << d0++;
	cout << d0;
	cout << ++d0;
	cout << d0;

	cout << d0--;
	cout << d0;
	cout << --d0;
	cout << d0;

	// Conversion constructor
	cout << Date(1492992000);	// convert number of seconds since Jan 1. 1970 0h00 to Date. HINT: use localtime()
	cout << (din == 1492992000);	// Does is it work ? Why ?
	cout << (1492992000 == din);	// Does is it work ? Why ?
}

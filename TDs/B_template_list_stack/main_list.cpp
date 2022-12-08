//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_List.cpp,v 1.1 2005/02/20 14:50:29 jpr Exp $
//=======================================================================

#include "list-template.h"

List<int> SomeFunction()
{
    List<int> ltemp;
    for (int i = 0; i < 5; i++) ltemp.append(i);
    return ltemp;
}

int main()
{
    int i;

    MSG(List operations);
    
    List<int> l1, l2;

    OUT(l1);
    for (i = 0; i < 10; i++)
    {
        l1.append(i);
        l2.prepend(i);
    }
    OUT(l1); OUT(l2);

    l1.prepend(99);
    l2.append(99);
    OUT(l1); OUT(l2);

    OUT(l1.get_first()); OUT(l1);
    OUT(l2.get_first()); OUT(l2);

    while (!l1.is_empty()) OUT(l1.get_first());
    OUT(l1);

    MSG(List copy);

    // First, uncomment the following 3 lines first
    l1 = l2; 
    OUT(l1);
    OUT(l2);
    
    // Second, uncomment the next line
    OUT(SomeFunction());

    cout << "End of program" << endl;

    return 0;
}

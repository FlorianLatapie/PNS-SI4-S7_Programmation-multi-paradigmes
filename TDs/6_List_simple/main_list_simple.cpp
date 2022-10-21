//=======================================================================
// Basic C++: a simple (and uncomplete) class list_simple of int's
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_List.cpp,v 1.4 2004/11/20 17:02:51 jpr Exp $
//=======================================================================

#include "common_defs.h"
#include "list_simple.h"

int main() {
    int i;

    MSG(List operations);

    List l1, l2;

    OUT(l1);
    for (i = 0; i < 10; i++) {
        l1.append(i);
        l2.prepend(i);
    }
    OUT(l1);
    OUT(l2);

    l1.prepend(99);
    l2.append(99);
    OUT(l1);
    OUT(l2);

    OUT(l1.get_first()); // Suppress first element and return its value
    OUT(l1);
    OUT(l2.get_first());
    OUT(l2);

    while (!l1.is_empty()) OUT(l1.get_first());
    OUT(l1);

    List l3;        // insert in the right place in a sorted list
    l3.insert(20);
    l3.insert(10);
    l3.insert(25);
    l3.insert(15);
    l3.insert(3);
    OUT(l3);

    List l4;
    l4.append(20);
    l4.append(2);
    l4.append(10);
    l4.append(1);
    l4.sort(); // HINT: use get_first() and insert()

    OUT(l3.get_middle_value());
    OUT(l3.max());

    EXEC(l3.max() = 7); // HINT : see MVector::operator[]
    OUT(l3);

    OUT(l4.get_last());
    OUT(l4);

    // mirror reverses the order of elements of l2 (l2 is modified)
    OUT(l2);
    EXEC(l2.mirror());
    OUT(l2);
}

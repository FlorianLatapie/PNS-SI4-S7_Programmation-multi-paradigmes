//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List.h,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cassert>
using namespace std;

#include "common_defs.h"

class List
{
private:
    
   // The list Cell type 
    
    struct Cell
    {
        int val;
        Cell *next;
        Cell(int v, Cell *n = 0) : val(v), next(n) {}
    };

    // 
    Cell *head;         // Pointer to first cell
    Cell *tail;         // Pointer to last cell

public:
    // Exception

    class Empty {};

    // Construction

    List() : head(0), tail(0) {}

    // Accessor ?
    
    bool is_empty() const {return head == 0;}

    // Adding elements to the list
    
    void append(int);   // at the end
    void prepend(int);  // at the beginning
	void insert(int e); // at the right place (for sorted lists only !)

    // Removing elements from the list
    
    int get_first();

	void mirror();

    // Display
    
    friend ostream& operator<<(ostream&, const List&);

	int get_middle_value() const; // return value in the middle (accessor)

	int max() const;
	int &max();
};

#endif

//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List-final.h,v 1.3 2004/11/20 16:16:05 jpr Exp $
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
        ~Cell() {delete next;} // Recursive destructor
    };

    // 
    Cell *head;         // Pointer to first cell
    Cell *tail;         // Pointer to last cell

public:
    // Exception

    class Empty {};

    // Construction

    List() : head(0), tail(0) {}

    ~List()
    { 
	cout << "*** List destructor ***" << endl; 
	delete head; // Destroy first cell (recursive destruction) 
	// another solution is, of course, to loop other the cells 
	// (see the corresponding --- commented --- code in List-final.cpp 
    } 

    // Copy constructor and copy assignment
    List(const List&);
    List& operator=(const List&);

    // Accessor ?
    
    bool is_empty() const {return head == 0;}

    // Adding elements to the list
    
    void append(int);   // at the end
    void prepend(int);  // at the beginning
	void insert(int);	// for sorted lists : at the right place !

    // Removing elements from the list en tete de liste
    
    int get_first();

    // Display
    
    friend ostream& operator<<(ostream&, const List&);

	int get_middle_value() const
	{
		Cell *pp;	// previous pointer
		Cell *p;	// (fast) pointer

		for (pp=p=head; p!=0 && p->next !=0; pp=pp->next, p=p->next->next) ;  // nothing in the loop
		return pp->val;
	}
};



#endif

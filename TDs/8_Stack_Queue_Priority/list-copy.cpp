//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List-final.cpp,v 1.3 2004/11/20 16:16:05 jpr Exp $
//=======================================================================

#include "list-copy.h"

//-----------------------------------------------------------------------
// Another implementation of the destructor
//-----------------------------------------------------------------------

/*
List::~List()
{
    cerr << "*** List destructor ***" << this << endl;
    Cell *ptmp;
    for (Cell *p = head; p != 0; p = ptmp)
    {
	ptmp = p->next;  // memorize next cell
	delete p;	 // delete current cell
    }
}
*/

//-----------------------------------------------------------------------
// Copy constructor and copy assignment
//-----------------------------------------------------------------------

List::List(const List& l)
    : head(0), tail(0)
{
    for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
        append(pcell->val);
}

List& List::operator=(const List& l)
{
    if (this != &l)
    {
        delete head; head = tail = 0;
        for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
            append(pcell->val);
    }
    return *this;       
}

//-----------------------------------------------------------------------
// Adding elements to the list
//-----------------------------------------------------------------------

void List::append(int v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}

// Au debut

void List::prepend(int v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

void List::insert(int e)
{
    Cell *p, *pprev;

    for (p = head, pprev = 0; p != 0 && p->val < e; pprev = p, p = p->next) {}

    if (pprev != 0) // inserting in the middle or at the end
    {
        Cell *ptemp = new Cell(e, pprev->next);
        pprev->next = ptemp;
        if (p == 0) tail = ptemp;
    }
    else prepend(e);   // inserting in front
}

//-----------------------------------------------------------------------
// Removing elements from the list
//-----------------------------------------------------------------------

int List::get_first()
{
    if (head == 0) throw Empty();
    int v = head->val;
    if (tail == head) tail = 0;
    Cell *p = head;
    head = head->next;
    p->next = 0; // needed: otherwise the next line destroy the whole list!
    delete p;
    return v;
}

//-----------------------------------------------------------------------
// Display
//-----------------------------------------------------------------------

ostream& operator<<(ostream& os, const List& l)
{
    List::Cell *p;
    for (p = l.head; p != 0; p = p->next) cout << p->val << ' ';
    return os;
}

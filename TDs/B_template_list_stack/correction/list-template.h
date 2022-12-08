//=======================================================================
// Basic C++: a simple class template List
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List.h,v 1.3 2005/02/20 15:26:03 jpr Exp $
//=======================================================================

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cassert>
using namespace std;

#include "common_defs.h"

template <typename ELEM>
class List;
template <typename ELEM>
ostream& operator<<(ostream&, const List<ELEM>&);

template <typename ELEM>
class List
{
private:
    
   // The list Cell type 
    
    struct Cell
    {
        ELEM val;
        Cell *next;
        Cell(ELEM v, Cell *n = 0) : val(v), next(n) {}
        ~Cell() {delete next;} // Recursive destructor
    };

    // 
    Cell *head;         // Pointer to first cell
    Cell *tail;         // Pointer to last cell

public:
    // Exception

    class Empty {};

    // Construction and destruction

    List() : head(0), tail(0) {}

    // Destroy first cell (recursive destruction)
    // It's not necessary to be virtual, but if it is not we get a
    // warning in Queu ! 
    virtual ~List() {delete head;} 

    // Copy constructor and copy assignment

    List(const List&);
    List& operator=(const List&);

    // Accessor ?
    
    bool is_empty() const {return head == 0;}

    // Adding elements to the list
    
    void append(ELEM);  // at the end
    void prepend(ELEM);  // at the beginning
    void insert(ELEM);  // at its place, according to ELEM::operator<

    // Removing elements from the list en tete de liste
    
    ELEM get_first();

    // Display (obey the g++ warning message and add <>!)
    
    friend ostream& operator<< <>(ostream&, const List&);
};



// pas de compilation séparée avec les classes "template"
//


//=======================================================================
// Basic C++: a simple class template List
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

//-----------------------------------------------------------------------
// Copy constructor and copy assignment
//-----------------------------------------------------------------------
    
template <typename ELEM>
List<ELEM>::List(const List& l)
    : head(0), tail(0)
{
    for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
        append(pcell->val);
}

template <typename ELEM>
List<ELEM>& List<ELEM>::operator=(const List& l)
{
    if (this != &l)
    {
        delete head;
        head = tail = 0;
        for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
            append(pcell->val);
    }
    return *this;       
}

//-----------------------------------------------------------------------
// Adding elements to the list
//-----------------------------------------------------------------------

template <typename ELEM>
void List<ELEM>::append(ELEM v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}

template <typename ELEM>
void List<ELEM>::prepend(ELEM v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}

// Find the first elemeent in the list greater than e and insert before

template <typename ELEM>
void List<ELEM>::insert(ELEM e)
{
    Cell *p, *pprev;

    for (p = head, pprev = 0;
         p != 0 && p->val < e; pprev = p, p = p->next) {}

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

template <typename ELEM>
ELEM List<ELEM>::get_first()
{
    if (head == 0) throw Empty();
    ELEM v = head->val;
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

template <typename ELEM>
ostream& operator<<(ostream& os, const List<ELEM>& l)
{
    typename List<ELEM>::Cell *p;
    for (p = l.head; p != 0; p = p->next) cout << p->val << ' ';
    return os;
}


#endif

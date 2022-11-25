//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// Modified Sylvain Lippi --- 2020
// $Id: List.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include "list_simple.h"

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


void List::mirror()
{
	Cell *pp;	// cellule précédente
	Cell *p;	// cellule courante
	Cell *tmp;	// variable temporaire

	for (pp=0, p=head; p!=0; pp=p, p=tmp) // <<p>> parcourt toute la liste
	{
		tmp=p->next;  // sauvegarde de l'ancienne valeur de p->next
		p->next=pp;
	}

	// il ne reste plus qu'à échanger les valeurs de head et tail :
	tmp=head;
	head=tail;
	tail=tmp;
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

int List::get_middle_value() const
{
	Cell *normal;	// (normal) pointer
	Cell *fast;	// (fast) pointer

	for (normal=fast=head; fast!=0 && fast->next !=0; normal=normal->next, fast=fast->next->next) ;  // nothing in the loop
	return normal->val;
}

int List::max() const
{
	int r;
	if ( is_empty() ) throw Empty();

	r=head->val;
	for (Cell *p=head->next; p != 0; p=p->next)
		if (p->val > r) r=p->val;
	return r;
}

int &List::max()
{
	Cell *rp = head; // Result Pointer: more precisely, a Pointer to the Cell containing the result

	if ( is_empty() ) throw Empty();

	for (Cell *p=head->next; p != 0; p=p->next)
		if (p->val > rp->val) rp=p;
	return rp->val;
}

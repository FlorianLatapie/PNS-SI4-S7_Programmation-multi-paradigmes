//=======================================================================
// Basic C++: a simple class templates List, Queue, and Stack
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_LQS.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================
/*
#include "Queue.h"
#include "Stack.h"
#include "Priority_Queue.h"

int main()
{
    int i;

    // Test of FIFO queues 
    MSG(Test Queue);

    Queue<int> q;
    for (i = 0; i < 10; i++) q.put(i);
    OUT(q);
    Queue<int> q1 = q;
    OUT(q.is_empty());
    while (!q.is_empty()) OUT(q.get());

    // Test of LIFO stack
    MSG(Test Stack);

    Stack<int> s;
    OUT(s); s.push(10); OUT(s);
    for (i = 0; i < 10; i++) s.push(i);
    OUT(s);
    Stack<int> s1;
    s1 = s;
    OUT(s.is_empty());
    while (!s.is_empty()) OUT(s.pop());

    // Test of copy operations
    MSG(Test copy);
   
    OUT(q1);
    OUT(s1);

    // Test of Priority_Queue
    MSG(Test Priority_Queue);
    Priority_Queue<int> prioq;
    for (i = 9; i >= 0; --i) prioq.put(i);
    OUT(prioq);

    // Test virtual functions
    MSG(Virtual functions);
    Priority_Queue<int> prioq1;
    Queue<int> *pq = &prioq1;
    OUT(*pq);
    for (i = 9; i >= 0; --i) prioq1.put(i);
    OUT(prioq1);

    return 0;
}
*/
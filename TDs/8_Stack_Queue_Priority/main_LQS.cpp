//=======================================================================
// Basic C++: a simple class templates List, Queue, and Stack
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_LQS.cpp,v 1.2 2004/11/01 15:19:04 jpr Exp $
//=======================================================================

#include "pile.h"
#include "file.h"
#include "fileprior.h"
#include "common_defs.h"

int main()
{
    int i;

    // Test of LIFO stack
    MSG(Test Stack);

    Stack s;
    OUT(s); s.push(10); OUT(s);
    for (i = 0; i < 10; i++) s.push(i);
    OUT(s);
    Stack s1;
    s1 = s;
    OUT(s.is_empty());

    // append, prepend... are FORBIDDEN on stacks and should NOT compile !
    //
    s.append(12);

    while (!s.is_empty()) OUT(s.pop());

    // Test of FIFO queues 
    MSG(Test Queue);

    Queue q;
    for (i = 0; i < 10; i++) q.put(i);
    OUT(q);
    Queue q1 = q;
    OUT(q.is_empty());
    while (!q.is_empty()) OUT(q.get());

    // Test of copy operations
    MSG(Test copy);
   
    OUT(q1);
    OUT(s1);

    // Test of Priority_Queue
	// get returns the smallest value
    MSG(Test Priority_Queue);
    Priority_Queue prioq;
    for (i = 9; i >= 0; --i) prioq.put(i);
    OUT(prioq);


    // Test virtual functions (does NOT APPEAR in main_LQS.out)
    MSG(Virtual functions);
    Queue *pq = new Priority_Queue;
    OUT(*pq);
    for (i = 9; i >= 0; --i) pq->put(i); // which <<put>> is called ?
    OUT(*pq);

return 0;
}

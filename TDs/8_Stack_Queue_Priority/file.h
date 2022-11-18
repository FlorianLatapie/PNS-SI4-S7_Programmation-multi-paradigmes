//
// Created by Florian on 18/11/2022.
//

#ifndef INC_8_STACK_QUEUE_PRIORITY_FILE_H
#define INC_8_STACK_QUEUE_PRIORITY_FILE_H


#include "list-copy.h"

class Queue: protected List {
public:
    virtual void put(int value);

    int get();

    bool is_empty();


    friend std::ostream &operator<<(std::ostream &os, const Queue &queue);
};


#endif //INC_8_STACK_QUEUE_PRIORITY_FILE_H

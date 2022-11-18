//
// Created by Florian on 18/11/2022.
//

#ifndef INC_8_STACK_QUEUE_PRIORITY_PILE_H
#define INC_8_STACK_QUEUE_PRIORITY_PILE_H


#include <ostream>
#include "list-copy.h"

class Stack : private List {

public:
    // On ne met pas de constructeur pour initialiser aussi avec une liste vide

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack);

    void push(int value);

    int pop();

    bool is_empty();
};


#endif //INC_8_STACK_QUEUE_PRIORITY_PILE_H

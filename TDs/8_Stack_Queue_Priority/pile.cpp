//
// Created by Florian on 18/11/2022.
//

#include "pile.h"

std::ostream &operator<<(std::ostream &os, const Stack &stack) {
    os << static_cast<List>(stack);
    return os;
}

void Stack::push(int value) {
    prepend(value);
}

bool Stack::is_empty() {
    return List::is_empty();
}

int Stack::pop() {
    return get_first();
}

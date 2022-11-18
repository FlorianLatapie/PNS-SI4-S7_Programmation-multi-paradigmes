//
// Created by Florian on 18/11/2022.
//

#include "file.h"

void Queue::put(int value) {
    append(value);
}

std::ostream &operator<<(ostream &os, const Queue &queue) {
    return os << static_cast<List>(queue);
}

bool Queue::is_empty() {
    return List::is_empty();
}

int Queue::get() {
    return get_first();
}

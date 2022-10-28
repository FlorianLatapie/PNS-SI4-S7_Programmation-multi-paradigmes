//
// Created by Florian on 21/10/2022.
//

#include "cell.h"

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    if (cell.next == nullptr) {
        os << cell.value;
    } else {
        os << cell.value << " " << *cell.next;
    }
    return os;
}

Cell::Cell(int i) {
    value = i;
    next = nullptr;
}

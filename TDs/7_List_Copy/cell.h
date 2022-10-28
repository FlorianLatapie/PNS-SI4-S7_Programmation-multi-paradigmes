//
// Created by Florian on 21/10/2022.
//

#ifndef INC_6_LIST_SIMPLE_CELL_H
#define INC_6_LIST_SIMPLE_CELL_H


#include <ostream>

class Cell {
public:

    int value;
    Cell *next;

    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    Cell(int i = 0);
};


#endif //INC_6_LIST_SIMPLE_CELL_H

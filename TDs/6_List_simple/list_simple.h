//
// Created by Florian on 16/10/2022.
//

#ifndef INC_6_LIST_SIMPLE_LIST_SIMPLE_H
#define INC_6_LIST_SIMPLE_LIST_SIMPLE_H

#include <ostream>
#include "cell.h"

class List {
private:
    Cell *first;
    Cell *last;
public:
    List();
    friend std::ostream &operator<<(std::ostream &os, const List &list);

    void append(int i);

    void prepend(int i);

    int get_first();

    bool is_empty();

    void insert(int i);

    void sort();

    int get_middle_value();

    int& max();

    int get_last();

    void mirror();
};


#endif //INC_6_LIST_SIMPLE_LIST_SIMPLE_H

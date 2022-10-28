//
// Created by Florian on 28/10/2022.
//

#ifndef INC_7_LIST_COPY_LIST_COPY_H
#define INC_7_LIST_COPY_LIST_COPY_H

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

    int &max();

    int get_last();

    void mirror();

    List(const List &l);

    bool is_empty() const;

    List &operator=(const List &l);

    ~List();

    List operator+(const List &l) const;

    List operator*(const List &l) const;

    int size() const;
};

#endif //INC_7_LIST_COPY_LIST_COPY_H

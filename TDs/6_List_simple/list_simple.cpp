//
// Created by Florian on 16/10/2022.
//

#include "list_simple.h"

std::ostream &operator<<(std::ostream &os, const List &list) {
    if (list.first == nullptr) {
        return os;
    }
    return os << *list.first;
}

List::List() {
    first = nullptr;
    last = nullptr;
}

void List::append(int i) {
    Cell *c = new Cell(i);
    if (is_empty()) {
        first = c;
        last = c;
    } else {
        last->next = c;
        last = c;
    }
}

void List::prepend(int i) {
    Cell *c = new Cell(i);
    if (is_empty()) {
        first = c;
        last = c;
    } else {
        c->next = first;
        first = c;
    }
}

int List::get_first() {
    int ret = first->value;
    first = first->next;
    return ret;
}

bool List::is_empty() {
    return first==nullptr;
}

void List::insert(int i) {
    Cell *c = new Cell(i);
    if (is_empty()) {
        first = c;
        last = c;
    } else if (first->value > i) {
        c->next = first;
        first = c;
    } else {
        Cell *current = first;
        while (current->next != nullptr && current->next->value < i) {
            current = current->next;
        }
        c->next = current->next;
        current->next = c;
    }
}

void List::sort() {
    if (is_empty()) {
        return;
    }
    // using get_first and insert
    List sorted;
    while (!is_empty()) {
        sorted.insert(get_first());
    }
    first = sorted.first;
    last = sorted.last;
}

int List::get_middle_value() {
    if (is_empty()) {
        throw -1;
    }
    Cell *slow = first;
    Cell *fast = first;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->value;
}

int& List::max() {
    if (is_empty()) {
        throw -1;
    }
    int max = first->value;
    Cell *ret = first;
    Cell *current = first;
    while (current != nullptr) {
        if (current->value > max) {
            max = current->value;
            ret = current;
        }
        current = current->next;
    }

    return ret->value;
}

int List::get_last() {
    if (is_empty()) {
        throw -1;
    }
    if (first == last) {
        int ret = first->value;
        first = nullptr;
        last = nullptr;
        return ret;
    }
    Cell *current = first;
    while (current->next != last) {
        current = current->next;
    }
    int ret = last->value;
    last = current;
    last->next = nullptr;
    return ret;
}

void List::mirror() { 
    if (is_empty()) {
        return;
    }
    Cell *current = first;
    Cell *previous = nullptr;
    while (current != nullptr) {
        Cell *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    Cell *tmp = first;
    first = last;
    last = tmp;
}

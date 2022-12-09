//
// Created by Florian on 09/12/2022.
//

#ifndef C_UNIQUE_PTR_UNIQUEPTR_HPP
#define C_UNIQUE_PTR_UNIQUEPTR_HPP

#include <iostream>

static int count = 0;

template <typename T>
class UniquePtr {
    T *ptr;
    int instance_num;
public:
    UniquePtr(): ptr(new T()) {
    }

    UniquePtr(const T &p) : ptr(new T(p)) {
    }

    UniquePtr(UniquePtr<T> &&p) : ptr(p.ptr) {
        p.ptr = nullptr;
    }

    ~UniquePtr() {
        if (ptr != nullptr) {
            delete ptr;
        }
    }

    UniquePtr(const UniquePtr<T> &p) = delete;

    UniquePtr &operator=(const UniquePtr<T> &p) = delete;

    UniquePtr &operator=(UniquePtr<T> &&p) {
        if (this != &p) {
            if (ptr != nullptr) {
                delete ptr;
            }
            ptr = p.ptr;
            p.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() {
        return *ptr;
    }

};


#endif //C_UNIQUE_PTR_UNIQUEPTR_HPP

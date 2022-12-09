//
// Created by Florian on 09/12/2022.
//

#ifndef C_UNIQUE_PTR_MOVABLE_H
#define C_UNIQUE_PTR_MOVABLE_H

#include <iostream>

static int movable_count = 0;

class Movable {
public:
    int instance_num;
    Movable() {
        movable_count++;
        instance_num = movable_count;
        std::cout << "Default constructor " << movable_count << " called" << std::endl;
    }

    Movable(const Movable& other) {
        movable_count++;
        instance_num = movable_count;
        std::cout << "Copy constructor " << instance_num << " called" << std::endl;
    }

    Movable(Movable&& other){
        instance_num = other.instance_num;
        other.instance_num = 0;
        std::cout << "Move constructor " << instance_num << " called" << std::endl;
    }

    Movable& operator=(Movable&& other){
        instance_num = other.instance_num;
        other.instance_num = 0;
        std::cout << "Move assignment " << instance_num << " called" << std::endl;
        return *this;
    }

    ~Movable() {
        if (instance_num != 0)
            std::cout << "Destructor " << instance_num << " called" << std::endl;
    }

};


#endif //C_UNIQUE_PTR_MOVABLE_H

//
// Created by Florian on 09/12/2022.
//

#ifndef C_UNIQUE_PTR_COPIABLE_HPP
#define C_UNIQUE_PTR_COPIABLE_HPP


#include <iostream>

// static variable that counts the number of copiable objects created
static int copiable_count = 0;

class Copiable {
    int instance_num;
public:
    Copiable() {
        copiable_count++;
        instance_num = copiable_count;
        std::cout << "Default constructor " << copiable_count << " called" << std::endl;
    }

    Copiable(const Copiable& other) {
        copiable_count++;
        instance_num = copiable_count;
        std::cout << "Copy constructor " << copiable_count << " called" << std::endl;
    }

    Copiable& operator=(const Copiable& other) {
        copiable_count++;
        instance_num = copiable_count;
        std::cout << "Copy assignment " << copiable_count << " called" << std::endl;
        return *this;
    }

    ~Copiable() {
        std::cout << "Destructor " << instance_num << " called" << std::endl;
    }
};


#endif //C_UNIQUE_PTR_COPIABLE_HPP

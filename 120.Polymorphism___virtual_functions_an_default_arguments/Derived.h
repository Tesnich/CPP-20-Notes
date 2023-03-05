#ifndef DERIVED_H
#define DERIVED_H
#include <string>
#include <iostream>
#include "Base.h"

class Derived : public Base
{
public:
    Derived(/* args */) = default;

//                                      _________________ default argument BASE_DEFAULT forever baked into virtual function
    void Function(std::string_view sv = "DERIVED_DEFAULT") override{
//                                      ^^^^^^^^^^^^^^^^^ This will only be used in respect to scope of Derived objects
        std::cout << "Derived::Function() called : " << sv << "\n"; 
    }
};


#endif
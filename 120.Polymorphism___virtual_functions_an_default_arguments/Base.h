#ifndef BASE_H
#define BASE_H
#include <string>
#include <iostream>

class Base
{
public:
    Base(/* args */) = default;

//                                           _________ default argument BASE_DEFAULT forever baked into virtual function
//                                                     calls from Base& or Base* will always use "BASE_DEFAULT"
    virtual void Function(std::string_view sv = "BASE_DEFAULT"){
        std::cout << "Base::Function() called : " << sv << "\n"; 
    }
};


#endif
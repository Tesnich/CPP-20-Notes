#ifndef DERIVED_H
#define DERIVED_H
#include <iostream>
#include "Base.h"

class Derived : public Base
{
public:
    Derived() = default;
    //reminder, virtual here facilitates total destruction of Derived object from Base* ptrBase{...};
    //not really used here....
    virtual ~Derived() = default;

    virtual void SaySomething(){
        std::cout << "Derived::SaySomething() called!\n";
    }
};


#endif
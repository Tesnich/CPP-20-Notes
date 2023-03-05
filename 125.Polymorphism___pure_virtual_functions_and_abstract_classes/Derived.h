#ifndef DERIVED_H
#define DERIVED_H
#include <iostream>
#include "Base.h"

class Derived : public Base
{
public:
    Derived() = default;

    virtual ~Derived() = default;

    //Base class has a pure virtual function called 'SaySomething()'
    //If this class did not override it, it would also become an abstract class.
    void SaySomething() override {
        std::cout << "Derived::SaySomething() called!\n";
    }
    //Comment out the above to see this in action
};


#endif
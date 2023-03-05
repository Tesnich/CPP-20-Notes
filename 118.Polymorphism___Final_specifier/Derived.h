#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived : public Base
{
    public:
        Derived() = default;
//                            final access specifier here will prevent Derived2 from overriding this again
//                            _____
        void PrintSomething() final override {
//                            ^^^^^
            std::cout<< "Derived::PrintSomething() with override enabled\n";
        }
};


#endif
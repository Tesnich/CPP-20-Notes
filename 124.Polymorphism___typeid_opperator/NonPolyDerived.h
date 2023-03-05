#ifndef NON_POLY_DERIVED_H
#define NON_POLY_DERIVED_H
#include <iostream>
#include "NonPolyBase.h"

class NonPolyDerived : public NonPolyBase
{
public:
    NonPolyDerived() = default;

    //virtual removed from Derived.h
    ~NonPolyDerived() = default;

    //override identifier removed from Derived.h
    void SaySomething() {
        std::cout << "Derived::SaySomething() called!\n";
    }
};


#endif
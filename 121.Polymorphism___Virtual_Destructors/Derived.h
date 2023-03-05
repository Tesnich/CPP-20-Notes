#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived : public Base
{

public:
    Derived(/* args */) {
        std::cout<<"Derived() Constructor Called!\n";
    }
    //        v- would normally add identifier 'override' here, but without we can freely add/remove virtual in base to see results
    ~Derived() {
        std::cout<<"~Derived() Destructor Called!\n";
    };
};


#endif
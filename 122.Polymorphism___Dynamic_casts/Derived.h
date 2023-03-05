#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived : public Base
{

public:
    Derived() {
        std::cout<<"Derived() Constructor Called!\n";
    }
    ~Derived(){
        std::cout<<"~Derived() Destructor Called!\n";
    }

    void DerivedOnlyFunction(){
        std::cout<<"DerivedOnlyFunction() called!\n";
    }
};


#endif
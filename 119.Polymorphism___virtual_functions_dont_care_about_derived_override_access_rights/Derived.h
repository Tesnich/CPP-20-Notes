#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived : public Base
{
    public:
        Derived(/* args */) = default;
        void FunctionB()override{
            std::cout<<"PUBLIC FunctionB() called from Derived\n";
        }

    private:
        void FunctionA() override{
            std::cout<< "PRIVATE FunctionA() called from Derived\n";
        }
};

#endif
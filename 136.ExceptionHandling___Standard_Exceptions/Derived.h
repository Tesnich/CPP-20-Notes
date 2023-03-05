#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"

class Derived : public Base
{
    public:
        Derived() = default;
        virtual ~Derived() = default;
};

#endif
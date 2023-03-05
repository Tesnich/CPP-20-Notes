#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"
#include <iostream>

class Derived : public Base
{
    public:
        Derived() = default;

        inline static int publicStaticInt_{99};

        void ReadStaticMembers(){
            std::cout << "privateStaticInt_ : INACCESSIBLE\n";
            //std::cout << "privateStaticInt_ : " << privateStaticInt_ <<"\n";
            std::cout << "privateStaticInt_ : " << protectedStaticInt_ <<"\n";
            std::cout << "privateStaticInt_ : " << publicStaticInt_ <<"\n";
        }
};


#endif
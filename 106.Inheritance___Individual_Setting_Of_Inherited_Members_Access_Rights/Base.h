#ifndef BASE_H
#define BASE_H

#include "Utilites.h"
#include <iostream>
#include <iomanip>

class Base
{
    private :
        int basePrivateInt_{1};
    protected :
        int baseProtectedInt_{2};
    public :
        int basePublicInt_{3};

        Base() = default;

        void DisplayDirectlyAccessibleData(){
            UTIL::PrintTitleLine("Base Class");
            std::cout << std::setw(25) << "basePrivateInt_ : " << basePrivateInt_ <<"\n";
            std::cout << std::setw(25) << "baseProtectedInt_ : " << baseProtectedInt_ <<"\n";
            std::cout << std::setw(25) << "basePublicInt_ : " << basePublicInt_ <<"\n";
            UTIL::PrintEndLine();
        }

        void SimpleBaseClassFunction(){
            std::cout << "SimpleBaseClassFunction() called!\n";
        }
};

#endif
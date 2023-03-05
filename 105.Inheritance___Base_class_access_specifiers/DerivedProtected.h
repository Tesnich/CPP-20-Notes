#ifndef DERIVED_PROTECTED_H
#define DERIVED_PROTECTED_H

#include "Base.h"

//protected inheritance
class DerivedProtected : protected Base
{
    public:
        DerivedProtected() = default;
        void DisplayDirectlyAccessibleData();
};

void DerivedProtected::DisplayDirectlyAccessibleData(){
    UTIL::PrintTitleLine("DerivedProtected Class");
    // std::cout << std::setw(25) << "basePrivateInt_ : " << basePrivateInt_ <<"\n";
        std::cout << std::setw(25) << "basePrivateInt_ : " << "INACCESSIBLE" <<"\n";
    std::cout << std::setw(25) << "baseProtectedInt_ : " << baseProtectedInt_ <<"\n";
    std::cout << std::setw(25) << "basePublicInt_ : " << basePublicInt_ <<"\n";
    UTIL::PrintEndLine();
}

#endif
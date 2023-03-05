#ifndef DERIVED_PRIVATE_H
#define DERIVED_PRIVATE_H

#include "Base.h"

//private inheritance
class DerivedPrivate : private Base
{
    public:
        DerivedPrivate() = default;
        void DisplayDirectlyAccessibleData();
};

void DerivedPrivate::DisplayDirectlyAccessibleData(){
    UTIL::PrintTitleLine("DerivedPrivate Class");
    //std::cout << std::setw(25) << "basePrivateInt_ : " << basePrivateInt_ <<"\n";
        std::cout << std::setw(25) << "basePrivateInt_ : " << "INACCESSIBLE" <<"\n";
    std::cout << std::setw(25) << "baseProtectedInt_ : " << baseProtectedInt_ <<"\n";
    std::cout << std::setw(25) << "basePublicInt_ : " << basePublicInt_ <<"\n";
    UTIL::PrintEndLine();
}

#endif
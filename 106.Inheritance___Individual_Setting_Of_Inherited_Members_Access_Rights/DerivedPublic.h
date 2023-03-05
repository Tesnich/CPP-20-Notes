#ifndef DERIVED_PUBLIC_H
#define DERIVED_PUBLIC_H

#include "Base.h"

//public inheritance
class DerivedPublic : public Base
{
    protected:
        using Base::basePublicInt_;
    public:
        DerivedPublic() = default;

        void DisplayDirectlyAccessibleData(){
            UTIL::PrintTitleLine("DerivedPublic Class");
            //std::cout << std::setw(25) << "basePrivateInt_ : " << basePrivateInt_ <<"\n";
                    std::cout << std::setw(25) << "basePrivateInt_ : " << "INACCESSIBLE" <<"\n";
            std::cout << std::setw(25) << "baseProtectedInt_ : " << baseProtectedInt_ <<"\n";
            std::cout << std::setw(25) << "basePublicInt_ : " << basePublicInt_ <<"\n";
            UTIL::PrintEndLine();
        }
};



#endif
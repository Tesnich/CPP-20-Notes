#ifndef NON_POLY_BASE_H
#define NON_POLY_BASE_H
#include <iostream>

class NonPolyBase
{
public:
    NonPolyBase() = default;
    
    //virtual removed from Base.h
    ~NonPolyBase() = default;

    //virtual removed from Base.h
    void SaySomething(){
        std::cout << "Base::SaySomething() called!\n";
    }
};


#endif
#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
public:
    Base() = default;
    
    //reminder, virtual here facilitates total destruction of Derived object from Base* ptrBase{...};
    //not really used here....
    virtual ~Base() = default;

    virtual void SaySomething(){
        std::cout << "Base::SaySomething() called!\n";
    }
};


#endif
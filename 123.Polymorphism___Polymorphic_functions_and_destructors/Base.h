#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
public:
    Base() {
        std::cout<< "Base() : ";
        SaySomething();
    };
    //reminder, virtual here facilitates total destruction of Derived object from Base* ptrBase{...};
    //not really used here....
    virtual ~Base(){
        std::cout<< "~Base() : ";
        SaySomething();
    }

    virtual void SaySomething(){
        std::cout << "Base::SaySomething() called!\n";
    }
};


#endif
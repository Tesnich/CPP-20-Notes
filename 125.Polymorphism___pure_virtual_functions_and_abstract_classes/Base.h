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

//  _______                    ____         use of 'virtual' and '=0' here denote SaySomething()
    virtual void SaySomething() = 0;    //  as a pure virtual function. It has no definition.
//                             ^^^^         This makes the class 'Base' an abstract class.
};


#endif
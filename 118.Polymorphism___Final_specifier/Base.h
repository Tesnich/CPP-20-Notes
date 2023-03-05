#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
    public:
        Base() = default;

        virtual void PrintSomething(){
            std::cout << "Base::PrintSomething()\n";
        }

        virtual void PrintAnotherThing(){
            std::cout << "Base::PrintAnotherThing()\n";
        }
};

#endif
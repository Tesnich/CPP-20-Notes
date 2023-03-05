#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
    public:
        Base() {
            std::cout<<"Base() Constructor Called!\n";
        }

        virtual ~Base(){
            std::cout<<"~Base() Destructor Called!\n";
        }

};


#endif
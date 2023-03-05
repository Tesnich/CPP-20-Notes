#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
    public:
        Base(/* args */) = default;
    
        virtual void FunctionA(){
            std::cout<<"PUBLIC FunctionA() called from Base\n";
        }

    private:
        virtual void FunctionB(){
            std::cout<<"PRIVATE FunctionB() called from Base\n";
        }
};

#endif
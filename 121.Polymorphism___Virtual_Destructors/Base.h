#ifndef BASE_H
#define BASE_H
#include <iostream>

class Base
{
    public:
        Base(/* args */) {
            std::cout<<"Base() Constructor Called!\n";
        }
//      _______ this will allow you to use polymorphism to delete the entire object (derived elements in total)
//      virtual ~Base(){
        ~Base(){
            std::cout<<"~Base() Destructor Called!\n";
        }
//      ^^^^^^^
};


#endif
#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Pure virtual functions and abstract classes

    //Pure virtual functions are vitural functions that have been declared '=0' in a class. They have no definition. 
    //This turns the base class into something known as an "abstract class".

    //Abstract classes are classes that cannot be created alone. Since they have pure virtual functions
    //with no definition, instances of the class cannot be initialized and used on their own. Instead,
    //abstract classes serve simply as base classes for subsequent derived classes.

    //If a derived class inherits from an abstract class it must override the pure virtual function of the
    //abstract class, otherwise it becomes an abstract class itself.

    //Note, this is perfect for my observer pattern personal project since it would make no sense to have
    //and observer or subject without a derived class implementing custom functionality.


    //Base has the pure virtual function 'SaySomething()', and as such is an abstract class...

    //  Base base{}; //error: cannot declare variable 'base' to be of abstract type 'Base'

    //Since it is an abstract class we are not permited to create an instance of it


    Derived derived{};
    //Derived inherits from Base, but overrides the 'SaySomething()' pure virtual method.
    derived.SaySomething();

    return 0;
}
#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Polymorphic functions and destructors

    //IMPORTANT: Do not call polymorphic(virtual) functions from constructors & destructors

    //When you create a derived object...
    //      Derived derived{};
    //the most base class in its inheritance chain is created first. You may think that if you call a virtual
    //function from the constructor youll get the overriden version. THIS IS NOT THE CASE! 
    //When we construct the base obj the derived obj has not been created yet!as such we will only 
    //be calling the Base version of the virtual method.

    //A similar situation happens when we call a virtual method in a destructor. In (proper) destruction of
    //a derived object, the outer most derived layers are destructed first because they depend on the base
    //objects. As such, at the time we hit the destructor in the base class, we have no overrides to call
    //and end up with whatever definition we wrote for the base class.

    {
        Derived derived{};
    }
    //      ^^^^^^^^^^^^^^^ Result ^^^^^^^^^^^^^^^
    //     |    jameshillman@Jamess-MBP 123.Polymorphism___Polymorphic_functions_and_destructors % ./program
    //     |    Base() : Base::SaySomething() called!
    //     |    ~Base() : Base::SaySomething() called!

    //In short...
    //Don't rely on any polymorphic functionality from derived classes when constructing or destructing base classes

    return 0;
}
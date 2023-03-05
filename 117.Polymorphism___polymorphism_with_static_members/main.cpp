#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Static class members and inheritance/polymorphism

    //if a base class implements a static member, all derived classes have access to it just like
    //any other member. They can be private, protected, or public.  They can be overriden as well. 

    //Base has three static members private, protected, and public with values 1,2,and 3

    //Derived overrides the public static member 
    Derived derived{};
    derived.ReadStaticMembers();

    //publicStaticInt_ of base class overriden by publicStaticInt_ in derived.
    //We can still manually specify it though by side-stepping polymorphism.
    std::cout << "derived.Base::publicStaticInt_() : " << derived.Base::publicStaticInt_ << "\n";
    
    //NOTE!! There is one limitation in respect to static members. 
    //Because static members exist outside of an instance of a class they cannot have a pointer
    //to a derived version (There could be hundreds of derived classes, to which would it point?)

    //So real polymorphism cannot be achieved with static members using virtual...

    Base& baseRefDerived{derived};
    std::cout << "baseRefDerived.publicStaticInt_ : " << baseRefDerived.publicStaticInt_ << "\n";

    //HOWEVER, since the static members are shared if you dont override them in the derived class it
    //already supports polymorphic type behavior where changes to that static member by the derived class
    //can be seen by the base class!

    
    return 0;
}
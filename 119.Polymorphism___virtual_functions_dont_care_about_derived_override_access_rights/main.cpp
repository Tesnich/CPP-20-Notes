#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Virtual functions bypass access rights of derived class

    //This is a very strange aspect of the polymorphism. If a base class member is declared virtual,
    //no matter where the override is placed in the derived class (private, protected, public), a successful
    //call to the base class method will chain up to the derived version.

    //This means you can have a public method called Func() in Base, override it in the private clause of derived,
    //then using the derived obj make a call to Func(), and end up calling the private method on that derived obj.

    Derived derived{};
    //compilation error
    //derived.FunctionA(); 
                         //functionA is public in base but private in derived
                         //Since precedance is set by the most recent override we cannot access either the public method
                         //on Base, nor the private method from Derived from the perspective of public Derived object
                         //if we really wanted we could specify the Base class call, but this is about polymorphism

    Base& baseRefDerived{derived};
    baseRefDerived.FunctionA(); //functionA is public in base but private in derived
    //successful call to private function of derived object!

    //baseRefDerived.FunctionB(); //cant call function B from Base& because it was private in Base (despite being virtual)


    //Take away... the access rights of overriden VIRTUAL methods are irrevalent to polymorphism 
    //                                                                              (pointers or refs to Base)
    //Static binding works just like you would expect though (no virtual methods)

    return 0;
}
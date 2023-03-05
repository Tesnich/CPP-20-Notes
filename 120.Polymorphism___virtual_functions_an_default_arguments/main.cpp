#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Default arguments and polymorphism - Don't do this pls

    //Default arguments are handled during compile time! In a nutshell, calls to base class virtual functions
    //that cascade up to derived overrides will use their base call default arguments!!! There are handled like
    //static binding!

    //This is definitely another weird bit you'll have to remember when coding with polymorphism. Try to avoid
    //default arguments in virtual methods if you can.

    Derived derived{};
    derived.Function(); //because we are using this from the public scope of the Derived object polymorphism doesnt
                        //come into play an we call the default argument defined in the override of Function();

    Base& baseRefDerived{derived};
    baseRefDerived.Function();  //  default argument from base used! Default arguments are determined using
                                //  STATIC BINDING!


    return 0;
}
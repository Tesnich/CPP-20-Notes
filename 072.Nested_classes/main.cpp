#include <iostream>
#include "Nested.h"

int main(int argc, char **argv){

    //Nested Classes
    
    //Classes can be nested in other classes to help restrict how they can be created or used
    //  - A class named inner, defined within a class named outer
    //  - Outer does not have access to the private members of inner
    //  - Inner has access to all of outer (public and private)

    //This basically is just an exercise in understanding scope. Just imagine outer as somehting akin to main
    //and you get the idea...

    //Check out Nested.h and .cpp

    //Horrible example, just bare bones, but you get the picture

    Outer outer(2,10.0);
    outer.DoSomething();

    //The below works because Inner class was defined in the public domain of Outer
    //Scope of outter needed to access the public member class Inner
    Outer::Inner inner{};
    //If it was moved the the private section this would work cause a compiler error!

    return 0;
}
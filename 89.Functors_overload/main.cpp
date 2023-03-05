#include <iostream>
#include "FunctorClass.h"

int main(int argc, char **argv){

    //Functors

    //Functors are operator overloads for '()' alone. Peculiar, but possible!
    //Look at FunctorClass.h
    FunctorClass functorClass{};
    functorClass("pizza");
    functorClass("Rainbows", "Dragons");

    //Technology, am I right?

    //Since you are calling unnamed member functions this could mean reading your code could get hairy.
    //I mean, given a large enough code bade how do you find the definition for the above?
    //Cntrl + F 'operator()' I guess. But then if there are multiple you gotta find which one is which.

    //Maybe this is good for very straightforward classes? I will have to think about good use cases...
    return 0;
}
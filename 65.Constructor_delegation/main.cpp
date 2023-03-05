#include <iostream>
#include "Square.h"

int main(int argc, char **argv){

    //Constructor delegation

    //Constructor delegation is the chaining of different constructors through the use of list initializers
    //  Examine the constructors in "Square.cpp" to see how each constructor calls one with more arguments
    //  to ultimately initialize default values on all memeber variables (except first param)

    Square sqrA(10);
    sqrA.PrintInfo();

    //Each constructor couts a message to the terminal saying it was called.
    //  You will see that it is in backwards order!
    //  This is because list initialization occurs >>BEFORE<< the constructor body is called!
    //  Thus the first constructor called will be the last one to have its body executed! Reverse order!

    return 0;
}
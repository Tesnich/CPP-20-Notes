#include <iostream>
#include "other.h"

//essentially extern here tells compiler we want this object to have 'externally linkage'.
//Because of such externalLinkage as written here is a DECLARATION. When the linker starts linking
//declarations to definitions it will try to find where externalLinkage is defined elsewhere (main.cpp)
extern int externalLinkage;
//to note, this is not imediately available for const objects...not sure why. Will be discussed in next lecture.

extern const int constVarExternallyLinked;

namespace Other{ //not needed but helps me keep what's where in my head

    void PrintSomeStuff(){
        std::cout << "externalLinkage var read in other.cpp : " << externalLinkage << std::endl;
        std::cout << "constVarExternallyLinked var read in other.cpp : " << constVarExternallyLinked << std::endl;
    }

//   Read the debacle in main.cpp, basically static outside of a function or class
//   hides its target from other Translation Units. Gifts it 'internal linkage'.
//   You can put a matching declaration anywhere you want, but
//   the linker will never tie it back to this method...
//   |
//   V
    static void staticMethodOutsideClass(){
        std::cout << "Other::staticMethodOutsideClass() called!" << std::endl;
    }
}
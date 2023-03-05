#include <iostream>
#include "Derived2.h"

int main(int argc, char **argv){

    //  NOTE:: It was revealed in this section that 'final' and 'override' are not keywords. They are IDENTIFIERS,
    //  meaning that we can use them as variable names or methods. Don't do that though, its going to confuse anyone
    //  using these words only for specifiers...


    //Final access specifier

    //The 'final' specifier can be used in two spots.
    
    //Class definition
    //The first is in the declaration of a class, I think with emphasis on declaration of a derived class. In marking
    //a class definition as 'final', you are telling the compiler that you dont want anyone else to derive from your
    //class.Essentially, you would derived from a base class and draw a line in the sand saying that no one can
    //derive from your new class. Good if you design it with the idea that it will never be a component of something
    //else.

    //Override definition
    //The second spot you can put the 'final' specifier is on overrides of a virtual member. In this case you are
    //still allowing programmers to derive from your derived class, but preventing them from throwing an override
    //ontop of your override. You are telling the compiler that your override will be the last one accepted. Any
    //attempts to do otherwise will lead to compilation failure.

    //check out Base.h -> Derived.h -> Derived2.h(contains Derived3 attempt)

    Derived2 derived2{};
    Base& baseRefDerived2{derived2};
    baseRefDerived2.PrintSomething(); //derived2 was unable to override this method
    baseRefDerived2.PrintAnotherThing();

    return 0;
}
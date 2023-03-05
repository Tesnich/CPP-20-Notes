#include <iostream>
#include "utility1.h"
#include "utility2.h"

int main(int argc, char **argv){

    //inline functions

    //without inline, if these files were compiled together they would cause re-definition errors
    //because age{} and some_function() share the global space (this is even with declarations)

    //if they are labled inline however there is no issue

    //I have declared seperate namespaces for utility1 and 2, for which I have declared and
    //written CallSomeFunc() which calls the inline some_function()s for each

    Utility1::CallSomeFunc();
    Utility2::CallSomeFunc();

    //The addresses of the age returned for both are the same! This means that through use of the inline
    //keyword we have defined age twice in code, but they are actually they act as one in the same.

    // I have added two age2s, and defined them inline. This time I have changed the values to differ, 0 and 99.
    // I have also changed CallSomeFunc() to cout these

    //Ok!! So in doing so the compiler threw away the 99 result! Both inline ints age2 are at the same address
    //in memory, with the value 0! This is a little strange. I would have expected a compilation error or something.
    
    //Need to remember that this can be a problem, that dissapearing 99 is concerning...

    //This is another case where a keyword is a little confusing to me. I guess it can consolidate definitions,
    //and allow you to initialize static member variables of a class. I wish I just had a simple list of
    //functionalities for some of these keywords ... :/ !

    //More uses for inline!!

    //The main reason we don't typically include c++ definitions in header files is because whenever
    //they are included they are copied into the Translation Unit of the .cpp file that included them.
    
    //There is no problem with having declarations copied all over the place! That is good! It lets
    //the including files know that a function defintion exists somewhere that matches the declaration
    //and lets us call it expecting the linker to find them for us.

    //If we mark source code in a header file with inline, however, the defintions will be consolidated!
    //Just like age was across utility1.cpp and utility2.cpp. This is apparently really handy for
    //classic C people who write entire header only libraries. 

    //Check out InlineSourceCode.h (remove the inlines to watch compilation grind to a halt)

    return 0;
}
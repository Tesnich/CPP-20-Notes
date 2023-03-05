#include <iostream>
#include "other.h"

void someFunction(){
    int noLinkageVar{10}; //noLinkageVar is limited to the scope of someFunction()
}                         //    we say it has "no linkage"

const int internalLinkage{20}; //internalLinkage is in the global variable space. Since it is a const
//                                  var, we are unable to establish it as an extern variable for
//                                  use in another file as is. Its scope is limitied to this TU.
//                                  We say objects like this have "internal linkage"
//                                  (this is slightly confusing to me, but I think you can declare this extern? do some googling later...)

int externalLinkage{30}; //externalLinkage is a non-const variable. Unlike the const above,
//                             we can declare it as an extern var in another file. This will tell the
//                             compiler to look for its definition, and ultimately allow access!
//                             (a good question would be what were to happen if there were more than one with the same name...)

//the default internal linkage of constants can be overriden by labeling them extern (for non-consts only the declaration has to be labeled extern)
extern const int constVarExternallyLinked{40};

int main(int argc, char **argv){

    //Linkage

    //Names describing the levels of usability objects have across functions and files

    Other::PrintSomeStuff();

    //so here is some weird stuff I came across in a quiz on static function definitions

    //it said that if the declaration for a void function was in main.cpp like
    //      void do_stuff();
    //and in other.cpp the function definition was written as
    //      static void do_stuff() {...};
    //The code would fail to link because the declaration would have no matching definition.

    //  So I went as far as to try it with a function called staticMethodOutsideClass.
    //  It didnt build with the declaration in other.h and definition in other.cpp. The explanation
    //  behind which is that the static keyword on a definition limits it to the scope of the file
    //  it is defined in??? So this is way different than my understanding of how it works on a function
    //  that is part of a class? To me I understood that static meant a class member would exist without an object.
    //        Also, used on an object in a non-class function, its value would persist multible calls.

    //  I also tried it the way you would declare and define a static function as part of a class.
    //  I put the static keyword at the declaration and took it away from the source. Still didn't build.
    //      Now THIS surprised me. I have no idea what is happening here.
    //  Is it that the static keyword has a different meaning when used on members of a class than when
    //  used in the global space of a file? It makes sense because obviously there is no object, but a little
    //  strange to me that they just didnt use some other keyword for something so different in functionality?
    
    //Other::staticMethodOutsideClass(); // <- CALL FAILS!!!

    //OK I THINK I UNDERSTAND

    //In a nutshell... IT DOES HAVE A DIFFERENT MEANING ... some kind of hold over for original C
    //     It's a way of hiding symbols...

    //by declaring an object or function static outside a function or class
    //
    //      static int x{}; 
    //
    //you are essentially doing the same thing as wrapping said object or function in
    //  an anonymous namespace
    //
    //      namespace {
    //          static int x{}
    //      }
    //
    //This threw me for a loop, as in my head 'static' sorta gave class members
    //  MORE visibility (being able to see and use them outside of an object)...albeit this is
    //  is not the case when used on the objects inside a function (just persistance, no visibility)

    //  !!!LEARNING IS FUN!!!


    //Flipping Linkage -> giving const variables external linkage

    //by default a const variable in global scope has internal linkage, so trying to reference it with
    //an extern declaration in another file isnt quite enough.

    //look at the variable constVarExternallyLinked, at the top of this file.

    return 0;
}
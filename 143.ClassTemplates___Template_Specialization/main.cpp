#include <iostream>
#include "AddStruct.h"

int main(int argc, char **argv){

    //Template specialization

    //This is the process of specializing functionality for a template using a certain type
    //ie, if you want to process data differently based on its type.
    //We have seen this done for methods of a template class (folder 140), but the same can be done on a template
    //class itself!

    //Check out AddStruct, that has the method add. We can easily add ints together using '+'
    //but that isnt possible for c style string arrays.

    // char * cStrArray[100]{"Hello"};
    // char * cStrArray2[100]{"World"}; 

    //      had to remind myself how to deal with * chars here
    //      we need to define a new array and copy the literals into them so we aren't throwing away the const
    //      nature of string literals

    char cStrArray[] = "Hello";
    char cStrArray2[] = " World";

    //      not that these needed to be non const anyway since we werent going to modify them...

    AddStruct addStruct(cStrArray,cStrArray2);

    std::cout << addStruct.Add() <<"\n";

    //there, we can see that the specialized class of the template we wrote had its constructor called.
    
    //One thing to note here is that when we write specializations they are their own classes, and can have their
    //own unique methods or even a lack of template members and methods. Whats important is that the class name
    //is the same, and it has the 'template<>' line above the class declaration, in addition to having <char*> or
    //whatever type specified. Constructors should match aswell, otherwise you will just end up calling the 
    //constructor from the template.

    //Basic overload rules...well sorta (fyi I dont think you can overload a class)
    //I'm going to need some practice on these

    //I mean I completely fogot about how overloads of a function template are given precedence before checking
    //the specializations... read up
    //https://stackoverflow.com/questions/7108033/template-specialization-vs-function-overloading




    //NOTE:
    //I dont know where else to put this, so just slapping it here. We don't need inline on template method
    //definitions that are outside a class template in a header file. All members of a class template
    //have inline protection by default. So, unlike a normal class method definition that needs inline in
    //a header file to prevent re-definition errors, we need take no such precautions when dealing with them.

    //This does NOT extend to specializations of methods in a template. Template specializations are reall
    //c++ code definitions. If you want to keep them close to the class template they specialize, they will
    //need to be inline in header files.


    return 0;
}
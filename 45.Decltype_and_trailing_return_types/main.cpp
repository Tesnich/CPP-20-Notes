#include <iostream>
#include "functions.h"

//this is garbage
template <typename T, typename P> auto sillyFunction(T a, P b) { return (a+b)? a:b;}
template <typename T, typename P> decltype(auto) sillyFunction2(T a, P b) { return (a+b)? a:b;}
//end of garbage

int main(int argc, char **argv){

    //Decltype and Trailing Return Types

    //Decltype : getting the type of an expression
    int a{9};
    double b{5.5};

    std::cout << "size : " << sizeof(decltype((a>b)? a : b)) << std::endl;

    //decltype can even be used to create variables
    decltype((a>b)? a : b) c {67};

    //look at header file to see decltype used in template so that auto return type templates can be seperated into
    //  declarations and definitions

    //ILLEGAL, badly declared template will fail compilation because type of auto can't be resolved before linking
    //std::cout << "maximumBad result : " << maximumBad(a,b) << std::endl;

    //SAFE, working method for seperating template declaration and definition
    std::cout << "maximumGood result : " << maximumGood(a,b) << std::endl;

    //what fresh hell is this? Section 28 : #257
    //I literally have no idea what the meaning of wrapping auto with decltype could do.
    std::cout << "Size of sillyFunction return type " << sizeof(sillyFunction(a,b)) << std::endl;
    std::cout << "Size of sillyFunction2 return type " << sizeof(sillyFunction2(a,b)) << std::endl;

    return 0;
}

//1.) Bad in declaration!
//                                ----
template <typename T, typename P> auto maximumBad(T a, P b)
{//                               ----
    return ((a>b)? a : b);
}

//2.) Good in declaration!
//                                ----                      ------------------------
template <typename T, typename P> auto maximumGood(T a, P b)->decltype((a>b)? a : b)
{//                               ----                      ------------------------
    return ((a>b)? a : b);
}

//  Say we were just writing a definition (no seperated declaration) and wanted to write the above without
//  repeating '(a>b)? a : b' as input for decltype and in our return statement. We can use decltype(auto)...
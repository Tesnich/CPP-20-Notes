#include <iostream>
#include "functions.h"

int main(int argc, char **argv){

    //Function templates with multiple parameters
    int intA{5}, intB{2};
    double doubleA{99.9};
    // Refer to functions.h for template definitions                                    ReturnType is first type argument in template, others can be auto deduced or manually specified here. ie '<double, int, double>'
    //                                                                                  --------
    std::cout << "Result of problematicMaximum declared double : " << problematicMaximum<double>(intA, doubleA) << std::endl;
    //                                                                                  -------- //!!!! FYI THIS CHANGES RETURN TYPE ONLY (subsequent type arguments will change remaining template typenames though)
    std::cout << "Result of problematicMaximum declared int    : " << problematicMaximum <int>  (intA, doubleA) << std::endl;
    //                                                                                  --------

    //this sort of formating for template calls will also allow you to pass in vars for implicit conversion!
    std::cout << "The result of divideNums using intVariables is : " << divideNums<double>(intA, intB) << std::endl;
    //by specifying double type for divideNums' T, doubles were used in the definition in all spots there was a T
    //so the ints were copied in as doubles, and a fractional result was returned!

    //template functions with a seperate typename variable for the return type must have that type declared in the call!
    //without it, the code will not compile! The return type cannot be auto deduced!

    //Illegal!!!
    //problematicMaximum(intA, doubleA);

    //TO BE CAREFUL ABOUT >>> When specifying <double> where there are more than one typename in the template,
    //                        do not expect it to change how the variables are taken in. The first argument should
    //                        be the return type by general standard. adding just <double> though will still mean that
    //                        in code that ints will be divided. You will get the int result cast into the return type double.
    //                        Make sure to carefully read the order of the typename arguments in the template so that
    //                        you make properly keep track of which arguments you are specifying types for when calling
    //                        these functions!

    //You can also have a template where auto is used as a return type in a template, sorta like a function.
    //In these cases auto will use the largest type from those provided. That is gross and super hard to read, don't do it unless you want to hate yourself and co-workers.

    return 0;
}
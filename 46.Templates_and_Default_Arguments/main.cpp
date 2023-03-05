#include <iostream>

//                  Default Argument
//                 VVVVVVVVVVVVVVVVVVV
template <typename ReturnType = double, typename T, typename P>
ReturnType numDivision (T a, P b);


int main(int argc, char **argv){

    //default arguemnts in templates

    int a{5};
    double b{2};

    std::cout << "numDivision on " << a << " and " << b << " is " << numDivision(a,b) << std::endl; // default return type val is double
    std::cout << "numDivision on " << a << " and " << b << " is " << numDivision<int>(a,b) << std::endl; // double mathmatics result should be truncated to int
    //                                                                          ^^^^^
    return 0;//                                                                 Override default typename argument
}

template <typename ReturnType, typename T, typename P>
ReturnType numDivision (T a, P b)
{
    return a/b; //dividing an int by a double will give us a double result
}

//Something to be aware of, you can create non type template parameters

//In C++20 this can be anything from ints, bools, enums, class names etc...
//In C++17 and earlier ints were the only thing supported
//  I do not personally see the point. If there is a value that needs to be populated, it can be passed in as an
//  input argument. Maybe specifying classes may be good? I'd have to see a real life use case...
//  Below is an example of non types in use...

template <typename ReturnType, int baseline>
ReturnType nonTypeTemplateParameterExample (int a, int b)
{
    return baseline - (a/b); // baseline is passed in by <> tag when calling nonTypeTemplateParameterExample()
                             // 'nonTypeTemplateParameterExample<double,200>(a,b);'
}                            //                                        ^^^^
                             //                                    no reason why this shouldnt be an input argument
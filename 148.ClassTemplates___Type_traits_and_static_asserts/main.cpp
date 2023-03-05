#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //using Type Traits and Static Asserts to run compile time checks for class templates
    //remember #include <type_traits>

    Point point{1,2,3,4,5,6};
    std::cout << point << "\n";

    //below is a bad example
    //apparently chars fall under the arithmetic umbrella https://en.cppreference.com/w/cpp/types/is_arithmetic
    Point charPoint{'A','B','C','D','E','F'};
    std::cout << charPoint << "\n";

    //The below causes the static assert in Point.h to go off
    //you shouldn't use strings in a point!
    Point strPoint{"Hello", "Gov'na"};
    std::cout << strPoint << "\n";



    return 0;
}
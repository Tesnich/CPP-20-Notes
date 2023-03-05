#include <iostream>
#include <iomanip>
#include "Number.h"

int main(int argc, char **argv){

    //prefix and post fix, incrementing/decrementing, opperator overloading 

    //look at number.h for implementation

    Number numA(0);
    std::cout << std::setw(50) << std::setfill('-') << " prefix overload " << std::setfill(' ')<< std::endl;
    std::cout << "cout << numA (initial) : " << numA << std::endl;
    std::cout << "cout << ++numA         : " << ++numA << std::endl;
    std::cout << "cout << numA (after)   : " << numA << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " postfix overload " << std::setfill(' ')<< std::endl;
    std::cout << "cout << numA (initial) : " << numA << std::endl;
    std::cout << "cout << numA++         : " << numA++ << std::endl;
    std::cout << "cout << numA (after)   : " << numA << std::endl;

    //if you want to implement the decrement versions of these then simply copy the code and re-use it
    //with '--', simple

    return 0;
}
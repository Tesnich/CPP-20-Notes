#include <iostream>
#include "functions.h"
#include <iomanip>

int main(int argc, char **argv){

    //Template functions and overloading

    //look at functions.cpp and .h for the juicy bits

    std::cout << std::setw(50) <<std::setfill('-') << " " << std::setfill(' ') << std::endl;
    double doubleA{1.1}, doubleB{9.9};
    double doubleMax {maximum(doubleA, doubleB)};
    std::cout<<"doubleMax of" << doubleA << " and " << doubleB << ": " << doubleMax << std::endl;

    std::cout << std::setw(50) <<std::setfill('-') << " " << std::setfill(' ') << std::endl;
    double* pDoubleA{&doubleA}, *pDoubleB{&doubleB};
    double* pDoubleMax {maximum(pDoubleA, pDoubleB)};
    std::cout<<"pDoubleMax of" << *pDoubleA << " and " << *pDoubleB << ": " << *pDoubleMax << std::endl;

    std::cout << std::setw(50) <<std::setfill('-') << " " << std::setfill(' ') << std::endl;
    const char * pConstCharA {"AAAA"}, *pConstCharB {"BBBB"};
    const char * pCoChMax{maximum(pConstCharA,pConstCharB)};
    std::cout<<"pCoChMax of " << pConstCharA << " and " << pConstCharB << ": " << pCoChMax << std::endl;
    

    std::cout << std::setw(50) <<std::setfill('-') << " " << std::setfill(' ') << std::endl;
    return 0;
}
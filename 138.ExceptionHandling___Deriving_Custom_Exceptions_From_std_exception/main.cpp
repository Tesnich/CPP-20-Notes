#include <iostream>
#include "DivideByZeroException.h"

int Divide(int a, int b){
    if(b == 0)
        throw DivideByZeroException(a,b);
    return a/b;
}

int main(int argc, char **argv){

    if (argc < 3)
        return 0;

    int a{std::stoi(argv[1])}, b{std::stoi(argv[2])}; 

    try
    {
        std::cout << Divide(a,b) << "\n";
    }
    catch(const std::exception& ex)
    {
        std::cout<<"EXCEPTION :" << ex.what() << '\n';
    }
    

    return 0;
}
#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Assignment 14

    Point p1(1,1);
    Point p2(2,2);
    auto result1 = (p2 == p1);
    auto result2 = (p2 != p1);
    std::cout << std::boolalpha;
    std::cout << "result1 : " << result1 << std::endl;
    std::cout << "result2 : " << result2 << std::endl;

    return 0;
}
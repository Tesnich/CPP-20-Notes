#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //implementation of compound arithmetic overloads, and their reuse to implement non-compound variants

    //with careful planning you are able to develop the overload for something like '+=' and call
    //that in implementing the overload for '+'

    //view Point.h and .cpp

    Geometry::Point pointA(1.1,1.1);
    std::cout << pointA << std::endl;
    pointA += Geometry::Point(2.2,2.2);
    std::cout << pointA << std::endl;

    std::cout << pointA + Geometry::Point(2.2,2.2) << std::endl;
    std::cout << pointA << std::endl;

    pointA.DisplayInputParameterPrivateVars(Geometry::Point(11.11, 99.99));

    return 0;
}
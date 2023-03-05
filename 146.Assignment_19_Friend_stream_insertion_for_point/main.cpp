#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Assignment 19

    Point<int,3> point_3d;
    point_3d.set_value(0,10);
    point_3d.set_value(1,20);
    point_3d.set_value(2,30);
    std::cout << point_3d << std::endl;

    return 0;
}
#include "Square.h"
#include <cmath>
#include <iostream>

//Square class

Square::Square(double length)
    : length_(length)
{
    std::cout << ">> Square Constructed with length (" << length_ << ") << ";
}

double Square::ComputeSurfaceArea(){
    return std::pow(length_, 2);
}

//ExplicitSquare class

ExplicitSquare::ExplicitSquare(double length)
    : length_(length) {}

double ExplicitSquare::ComputeSurfaceArea(){
    return std::pow(length_, 2);
}
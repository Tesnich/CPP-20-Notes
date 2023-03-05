#include "Point.h"
#include <iostream>

Point::Point(const Point& sourcePoint) //copy constructor
    :Point(sourcePoint.x(),sourcePoint.y())//delegation to constructor
    {
        std::cout << " >> Copy Constructor Called! << " << std::endl;
    } 

Point::Point(Point&& sourcePoint) //move constructor definition
    :Point(sourcePoint.x(),sourcePoint.y()) //delegation to constructor
    {
        sourcePoint.invalidate(); //the important bit of a move constructor, need to set existing pointers to nullptr
        std::cout << " >> Move Constructor Called! << " << std::endl; // I imagine this could be done in here in the move method,
    }                                                                 // maybe the instructor just wanted to obfuscate?

    // NOTE -> I think I know why he uses this private invalidate method. By housing this as a private method in the header
    //         it will be easier to update the list of things that need to be invalidated
    //         as the method is right under where a programmer would add new member variables.
    //         One stop and you are good? I imagine there is a standard out there for formatting if I looked hard enough...

    // NOTE -> Lecturer shows that you can all create special getters for vars to both get the data then set the pointers to null
    //         A million ways to skin a cat... The general idea is the same. Setting up the move method to work with std::move, implement how you want.

Point::~Point() {
    delete x_;
    delete y_;
};

double Point::x() const {
    return *x_;
}
double Point::y() const {
    return *y_;
}
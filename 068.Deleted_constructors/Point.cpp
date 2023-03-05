#include "Point.h"
#include <iostream>

Point::Point(const Point& sourcePoint)
    :Point(sourcePoint.x(),sourcePoint.y())
    {
        std::cout << " >> Copy Constructor Called! << " << std::endl;
    } 

Point::Point(Point&& sourcePoint)
    :Point(sourcePoint.x(),sourcePoint.y())
    {
        sourcePoint.invalidate();
        std::cout << " >> Move Constructor Called! << " << std::endl;
    }

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
#include "Point.h"
#include <iostream>

namespace Geometry{

    Point::Point()
        :Point(0.0,0.0) {}

    Point::Point(double x, double y)
        :x_{x}, y_{y} {}

    Point& Point::operator+= (const Point& pointB){
        std::cout << ">> operator+= called <<" <<std::endl;
        x_ += pointB.x_; //is this a problem? accessing private data of another object?
        y_ += pointB.y_;    //WHY IS THIS WORKING???
        return *this;
    }

    Point Point::operator+ (const Point& pointB) const{
        std::cout << ">> operator+ called <<" <<std::endl;
        Point tempPoint(x_, y_);
        return tempPoint += pointB; //this line re-uses the work done in the above overload!
    }                               //by using += with a copy of this' object 'tempPoint' then
                                    //returning that copy
}
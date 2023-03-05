#include "Point.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

namespace Geometry{

    bool Point::constructorVisibility_{false};

    Point::Point()
        :Point(0.0,0.0) {}

    Point::Point(double x, double y)
        :x_{x}, y_{y}
        {
            if(constructorVisibility_)
                std::cout << "  >> Point (" << x_ << "," << y_ <<") Constructed <<" << std::endl;
        }

    //the definition of an operator overload is written like any other class definition
    //operator+ is the function name, for which we must use the scope resolution operator
    //to specify the class scope for the operator+ function we are defining...
    //    _______
    Point Point::operator+ (const Point& pointB)const{ //const used here because we want to be able to add const Point objects to create a new point
    //    ^^^^^^^
        return Point(x_+pointB.X(), y_+pointB.Y());
    }

    Point Point::operator+ (double offset) const{
        return Point(x_ + offset, y_+offset);
    }

    double Point::operator[] (unsigned int i) const{
        assert(i < 2); //if a value higher than 1 provided there is no data associated, throw assertion
        return (i) ? y_ : x_ ; 
    }

    double& Point::operator[] (unsigned int i) {
        assert(i < 2); //if a value higher than 1 provided there is no data associated, throw assertion
        return (i) ? y_ : x_ ; 
    }

    void Point::X(double x){
        x_ = x;
    }
    double Point::X() const {
        return x_;
    }

    void Point::Y(double y){
        y_ = y;
    }
    double Point::Y() const{
        return y_;
    }

    void Point::PrintData(){
        std::cout << std::left << "x_ : " << std::setw(PRINT_SPACING_) << x_ << "y_ : " << std::setw(PRINT_SPACING_) << y_ << std::endl;
    }

    double Point::CalculateDistance(Point* pointA, Point* pointB){
        return std::sqrt( std::pow(pointA->X() - pointB->X(), 2) + std::pow(pointA->Y() - pointB->Y(), 2) );
    }

    void Point::ConstructorVisibility(bool setting){
        constructorVisibility_ = setting;
    }

}
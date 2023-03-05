#include "Point.h"

//  when defining functions or member vars for classes in a namespace we can either
//      A.) use the scope opperator on each definition to tell it what namespace is relevant
//              (the commented out lines below containing "Geom::")
//      B.) wrap all the function calls in the same namespace
//              (I imagine this could allow for skipping the scope opperator of Point too... lets see!)
//                  ^^^^^ !!!! So this DIDNT WORK !!!! ^^^^
namespace Geom{
    //Geom::Point::Point() {}
    Point::Point() {}

    //Geom::Point::Point(double x, double y)
    Point::Point(double x, double y)
        :x_(x), y_(y) {}

    //Geom::Point::~Point() {}
    Point::~Point() {}

    //void Geom::Point::PrintInfo()const
    void Point::PrintInfo()const
    {
        std::cout << "Point " << this << " (" << x_ << "," << y_ << ")" << std::endl;
    }
}
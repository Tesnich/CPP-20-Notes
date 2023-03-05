#include "Line.h"
#include <iostream>

namespace Geom{
    Line::Line(Point& startPoint, Point& endPoint)
        :startPoint_(startPoint), endPoint_(endPoint) {}

    void Line::PrintInfo(){
        std::cout<< "-- Line ---------------" << std::endl;
        startPoint_.PrintInfo();
        endPoint_.PrintInfo();
        std::cout<< "-- Line End -----------" << std::endl;
    }
}
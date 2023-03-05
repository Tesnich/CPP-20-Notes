#include "Point.h"
#include <cmath>

namespace Geom{
    double Point::Distance() const {
        return std::sqrt(std::pow(x_,2) + std::pow(y_,2));
    }
    //custom operator overload
    // auto Point::operator<=>(const Point& pointB) const{
    // }
}
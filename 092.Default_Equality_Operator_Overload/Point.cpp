#include "Point.h"
#include <cmath>

namespace Geom{
    double Point::Distance() const {
        return std::sqrt(std::pow(x_,2) + std::pow(y_,2));
    }
    //custom operator overload
    bool Point::operator==(const Point& pointB) const{
        return Distance() == pointB.Distance();
    }
}
#include "Point.h"
#include <cmath>

namespace Geom{
    double Point::Distance() const {
        return std::sqrt(std::pow(x_,2) + std::pow(y_,2));
    }

    //partial_ordering selected as return type because double supports unordered infrastructure
    std::partial_ordering Point::operator<=>(const Point& pointB) const{
        if(Distance() == pointB.Distance())
            return std::partial_ordering::equivalent;
        else if (Distance() > pointB.Distance())
            return std::partial_ordering::greater;
        else if (Distance() < pointB.Distance())
            return std::partial_ordering::less;
        else
            return std::partial_ordering::unordered; //if NaN is compared with a double it will always
    }                                                //be false. In the event all conditionals fail and
                                                     //code reaches the else clause, we know that the result
                                                     //should be unordered!

    //ofcourse, in the above case the result of Distance() is a double. We could have easily used
    //<=> between them to get the same answers. This is mainly to show that this method can be used
    //to get the spaceship <=> working with non standard types that don't already implement it.
}
#ifndef POINT_H
#define POINT_H
#include <memory>

namespace Geom{
    class Point{
        private :
            double x_{}, y_{};
        public :
            Point() = default;
            Point(double x, double y)
                :x_{x}, y_{y} {}
            double Distance() const;

            //partial was selected because doubles can be values like NaN which aren't comparable
            //to normal values... more info in definition of this overload
            std::partial_ordering operator<=>(const Point& pointB) const;
    };
}

#endif
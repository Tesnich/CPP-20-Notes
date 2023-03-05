#ifndef POINT_H
#define POINT_H

namespace Geom{
    class Point{
        private :
            double x_{}, y_{};
        public :
            Point() = default;
            Point(double x, double y)
                :x_{x}, y_{y} {}
            double Distance() const;
            //custom operator overload
            bool operator==(const Point& pointB) const;
    };
}

#endif
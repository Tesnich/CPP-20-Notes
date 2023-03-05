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
            //default <=> operator overload, shallow member var comparison
            auto operator<=>(const Point& pointB) const = default;
            //auto allows for std::strong_ordering, std::weak_ordering, and std::partial_ordering

            //for the above case strong_ordering should be deduced because the int members will
            //be compared in declaration order, and the int var supports strong_ordering by default 
    };
}

#endif
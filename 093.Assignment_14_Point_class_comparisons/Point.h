#ifndef POINT_H
#define POINT_H

struct Point{
    Point(double x, double y)
        :m_x(x), m_y(y) {}
    ~Point(){
    }
    double m_x{};
    double m_y{};

    // My Code //////////////////////////////////////////
    bool operator==(const Point& pointB) const = default;
    /////////////////////////////////////////////////////
};

#endif
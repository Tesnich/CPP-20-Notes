#ifndef POINT_H
#define POINT_H

class Point {
    private :
        double* x_{}, *y_{};

        void invalidate(){
            x_ = nullptr;
            y_ = nullptr;
        }
    public :
        Point() = delete; // This will prevent users from creating a Point object with the default constructor
        Point(double x,double y)
            :x_(new double {x}), y_(new double {y}) {}
        Point(const Point& sourcePoint);
        Point(Point&& sourcePoint);
        ~Point();

        double x() const;
        double y() const;
};

#endif
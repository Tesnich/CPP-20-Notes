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
        Point(double x,double y) //constructor,
            :x_(new double {x}), y_(new double {y}) {}
        Point(const Point& sourcePoint); //copy constructor, delegation to constructor above, check source
        Point(Point&& sourcePoint); //move constructor denoted by '&&'
        ~Point();                   //examine rest in .cpp

        double x() const;
        double y() const;
};

#endif
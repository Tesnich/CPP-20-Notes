#ifndef POINT_H
#define POINT_H
#include "Number.h"
#include <iostream>

class Point {
    private :
        double x_{}, y_{};
    public :
        Point()
            :Point(0.0,0.0) {}
        Point(double x, double y)
            :x_{x}, y_{y} {
                std::cout << ">> Lord have mercy, a Point object with values " << x_ << " and " << y_ << " created. <<" << std::endl;
            }
};

//the gross, unexpected bit...

inline Point operator+ (const Number& numA, const Number& numB){
    std::cout << " >> inline Point operator+ (const Number& numA, const Number& numB) called <<" << std::endl;
    return Point(static_cast<double>(numA), static_cast<double>(numB));
}

#endif
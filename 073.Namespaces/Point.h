#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace Geom{
    class Point{
        private :
            double x_{}, y_{};
        public :
            Point();
            Point(double x, double y);
            ~Point();
            
            void PrintInfo()const;
    };
}
#endif
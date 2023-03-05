#ifndef LINE_H
#define LINE_H

#include "Point.h"

namespace Geom{
    class Line{
        private :
            //point class declared in geom namespace, but since line is too, we dont need scope resolution opperator
            Point &startPoint_, &endPoint_;
        public :
            Line() = delete;
            Line(Point& startPoint, Point& endPoint);
            void PrintInfo();
    };
}

#endif
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
    public:
        Shape() = default;
        void DrawShape() {
            std::cout << "The base class <Shape> has no drawable method.\n";
        };
};


#endif
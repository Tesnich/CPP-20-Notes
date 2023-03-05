#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string_view>

class Shape
{
    public:
        Shape() = default;
//      virtual keyword added below to facilitate polymorphism in ENTIRE inheritance heirchy tree
//      _______
        virtual void DrawShape() {
//      ^^^^^^^
            std::cout << "The base class <Shape> has no drawable method.\n";
        };

        virtual void DrawShape(std::string_view sv){
            Shape::DrawShape();
        }
};


#endif
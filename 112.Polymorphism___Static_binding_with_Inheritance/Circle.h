#ifndef CIRCLE_H
#define CIRCLE_H
#include "Oval.h"

class Circle : public Oval
{
    public:
        Circle()
            :Oval() {}
        Circle(double radius)
            :Oval(radius, radius) {}
        
        void DrawShape(){
            std::cout << "A Circle with a radius of " << xRadius_ << " drawn\n";
        }

        void CircleOnlyMethod(){
            std::cout << "A Circle with a radius of " << xRadius_ << " drawn\n";
        }

};

#endif
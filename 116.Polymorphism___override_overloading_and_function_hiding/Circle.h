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
//                       Overide specification!
//                       ________
        void DrawShape() override;
//                       ^^^^^^^^

};

//override doesnt seem to be needed here, but also builds with it here... your pick I suppose
inline void Circle::DrawShape(){
    std::cout << "A Circle with a radius of " << xRadius_ << " drawn\n";
}

#endif
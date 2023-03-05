#ifndef OVAL_H
#define OVAL_H
#include "Shape.h"

class Oval : public Shape
{
    protected:
        double xRadius_{};
        double yRadius_{};
    public:
        Oval()
            :Oval(0.0,0.0) {}
        Oval(double xRadius, double yRadius)
            :xRadius_{xRadius}, yRadius_{yRadius} {}
        
        void DrawShape(){
            std::cout << "An Oval with radius x " << xRadius_ <<" and radius y " << yRadius_ <<" drawn\n"; 
        }
};


#endif
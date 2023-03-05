#include "Cylinder.h"
#include <numbers>

//Really all that goes in the .cpp for a file are the methods for a class
//The header is where you go to find out more info on if the class inherits or extends anything else

//      Must denote these definitions as being for the Cylinder class with the scope resolution opperator '::'
//      |
//      V
Cylinder::Cylinder(double rVal, double hVal){
    m_base_radius = rVal;
    m_height = hVal;
}

double Cylinder::Volume(){
    return std::numbers::pi * m_base_radius * m_base_radius * m_height;
}

void Cylinder::SetHeight(double hVal){
    m_height = hVal;
}

double Cylinder::GetHeight() {
    return m_height;
}

void Cylinder::SetRadius(double rVal){
    m_base_radius = rVal;
}

double Cylinder::GetRadius() {
    return m_base_radius;
}
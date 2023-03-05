#include "Cylinder.h"
#include <cmath>
#include <iostream>

Cylinder::Cylinder(double radius, double height)
{
    radius_ = radius;
    height_ = height;
}

Cylinder::Cylinder(double radius, double height, std::string_view material)
    : radius_(radius), height_(height), material_(material) {}  //initalizer list format!
                                                                //  This method of initializing member variables prevents the creation of copies from assignment. 
double Cylinder::radius() const{                                //  Side steps default construction of member variables in class declaration.
    return radius_;                                             //  NOTE! : The order of initialization matters! They need to be list initialized in the order
}                                                               //      specified in the class declaration! Otherwise they would need to create the 
void Cylinder::radius(double radius){                           //      variables in order then assign, so not list initialization, thus... illegal.
    radius_ = radius;
}                                       //essentially, list initialization helps reduce memory overhead on construction
                                        //  especially if tons of instances of a class are being created with tons of mem vars
double Cylinder::height() const{
    return height_;
}
void Cylinder::height(double height){
    height_ = height;
}

double Cylinder::Volume() const
{
    return M_PI * std::pow(radius_, 2) * height_;
}

void Cylinder::InfoDump() const 
{
    std::cout << "Radius : " << radius_ << std::endl;
    std::cout << "Height : " << height_ << std::endl;
    std::cout << "Volume : " << Volume() << std::endl;
    if(!material_.empty())
        std::cout << "Material : " << material_ << std::endl;
    std::cout << std::endl;
}
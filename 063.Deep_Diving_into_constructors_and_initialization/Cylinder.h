#ifndef CYLINDER_H
#define CYLINDER_H

#include <string>
#include <string_view>

class Cylinder{
    private :
        double radius_{1}, height_{1};
        std::string material_{};

    public :
        Cylinder() = default;
        Cylinder(double radius, double height = 10); //if called with a radius argument but not height, this constructor gives height a default value of 10
        Cylinder(double radius, double height, std::string_view material); //list initialization format in .cpp

        //setters and getters
        double radius() const;
        void radius(double radius);

        double height() const;
        void height(double height);

        //public methods

        double Volume() const;
        void InfoDump() const;
};

#endif
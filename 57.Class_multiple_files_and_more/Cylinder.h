#ifndef CYLINDER_H
#define CYLINDER_H

//full class could be included here and it would work fine, but that clutters the header...

//Instead we just define the class, add any member variables, and declare methods here.
//Definitions for the methods will live in a .cpp file!

//This way you can see at a glance what all the methods and data types are in the class, without getting bogged down with their functionality
class Cylinder {
    private :
        double m_base_radius {1.0}, m_height {1.0};

    public :
        Cylinder() = default;

        Cylinder(double rVal, double hVal);

        double Volume();

        void SetHeight(double hVal);
        double GetHeight();

        void SetRadius(double rVal);
        double GetRadius();
}; 

#endif
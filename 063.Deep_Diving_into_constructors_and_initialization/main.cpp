#include <iostream>
#include "Cylinder.h"

int main(int argc, char **argv){

    //Deep diving into constructors and initialization

    //Default paramers for constructors (look in header for height = 10)

    Cylinder cylA; //using 'Cylinder() = default;'
    cylA.InfoDump();

    Cylinder cylB(5); //using 'Cylinder(double radius, double height = 10)'
    cylB.InfoDump();

    Cylinder cylC(10,10); //using 'Cylinder(double radius, double height = 10)'
    cylC.InfoDump();

    //if default parameters are established for all input parameters there will be ambiguity
    //  compiler cant reconcile between 'Cylinder() = default;' and 'Cylinder(double radius = 10, double height = 10);'

    //Up till this point we have been doing member wise assignment initialization^^^^^^^^^^


    //VVVVVVVV list initialization VVVVVVVV

    //I have edited the cylinder class to add a new constructor that has a 3rd parameter, material!
    //  View how cpp to see how list initialization is used to avoid adding a body to the constructor.

    //  Cylinder::Cylinder(double radius, double height, std::string_view material)
    //      : radius_(radius), height_(height), material_(material) {}                  //initalizer list format!

    Cylinder cylD(2.1,5, "Wood");
    cylD.InfoDump();

    return 0;
}
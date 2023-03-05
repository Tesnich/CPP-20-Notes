#include <iostream>
#include "Cylinder.h"
#include <iomanip>

int main(int argc, char **argv){

    //using Cylinder class from .h and .cpp
    Cylinder cylA;
    std::cout <<"Volume : "<< cylA.Volume() << std::endl;
    std::cout <<"cylA.GetHeight() : " << cylA.GetHeight() << std::endl;
    std::cout <<">> cylA.SetHeight(2) <<" << std::endl;
    cylA.SetHeight(2);
    std::cout <<"cylA.GetHeight() : " << cylA.GetHeight() << std::endl;
    std::cout <<"cylA.GetRadius() : " << cylA.GetRadius() << std::endl;
    std::cout <<">> cylA.SetRadius(3) <<" << std::endl;
    cylA.SetRadius(3);
    std::cout <<"cylA.GetRadius() : " << cylA.GetRadius() << std::endl;
    std::cout <<"Volume : "<< cylA.Volume() << std::endl;

    std::cout << std::endl << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //using the class object through pointers

    //dynamically create cylinder object on the heap
    Cylinder * cylB = new Cylinder(11,20);
    //de-referencing pointer to access member function volume
    std::cout << "(*cylB).Volume() : " << (*cylB).Volume() << std::endl;
    //using the -> operator to auto de-ref and call method, no '.' required
    std::cout << "cylB->Volume() : " << cylB->Volume() << std::endl;

    //don't forget to release memory from the object we created on heap when done with it
    delete cylB;


    return 0;
}
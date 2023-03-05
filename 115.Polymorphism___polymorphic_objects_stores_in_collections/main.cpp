#include <iostream>
#include <memory>
#include "Circle.h"

int main(int argc, char **argv){

    //Collections and Polymorphic objects

    //Remember that arrays make copies of data

    Oval oval1{}, oval2{};
    Circle circle1{}, circle2{};

    Shape shapes[]{oval1,oval2,circle1,circle2}; //creating copies, slicing!

    for (size_t i{}; i<4; ++i){
        shapes[i].DrawShape(); //all come back with just shape calls
    }

    //To use true polymorphism you must use pointers!
    
    Shape* shapes2[]{&oval1,&oval2,&circle1,&circle2}; //copies of addresses. No problem, nothing spliced!

    for (size_t i{}; i<4; ++i){
        shapes2[i]->DrawShape();
    }
    

    return 0;
}
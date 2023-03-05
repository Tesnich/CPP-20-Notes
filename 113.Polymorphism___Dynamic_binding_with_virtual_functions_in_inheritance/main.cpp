#include <iostream>
#include "Circle.h"

int main(int argc, char **argv){

    //Dynamic binding
    
    //Dynamic binding is the way of telling pointers (or references) to a base class to look for
    //the latest implemented version of a member by the derived class before calling. By enabling
    //dynamic binding in your inheritance hierchies, you will be enabling true polymorphism!

    //This is done by declaring the base members with the keyword 'virtual'. 

    //Examine Shape, Oval, and Circle again for virtual changes...

    Shape shape{};
    Oval oval(5,10);
    Circle circle(7);

    Shape* shapes[]{&shape, &oval, &circle}; //polymorphism and inheritance allow us to
                                             //make collections of very different objects!
    for (size_t i{0}; i < 3; ++i){
        shapes[i]->DrawShape();
    }

    //This modifier propogates to all subsequently derived classes.

    //ie.. since oval is derived from shape, its DrawShape() method is also virtual.
    //You can see below that an array of pointers to Oval classes with has the same functionality
    //between oval and circle even though neither use the keyword 'virtual'. There is no need to 
    //put the keyword virtual into oval or circle, however, it will help read-ability if we do.

    Shape* ovals[]{&oval, &circle}; //polymorphism and inheritance allow us to
                                    //make collections of very different objects!
    for (size_t i{0}; i < 2; ++i){
        ovals[i]->DrawShape();
    }


    //Success! A key component of modern programing achieved! Polymorphism rocks!

    return 0;
}
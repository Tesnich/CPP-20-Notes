#include <iostream>
#include "Circle.h"

int main(int argc, char **argv){

    //Size of polymorphic objects and slicing


    //Object Slicing

    Shape shape{};
    Oval oval(5, 10);

    Shape shapeB = oval; //Strips off the oval object and calls copy constructor for 'Shape(Shape)'

    //Since shape only has enough space for the Shape object, the derived class members are stripped.
    //This process we've seen before is actually called "object slicing" in c++.

    //Sizing...

    //So what is the downside of enabling dynamic binding? Well, now our base class
    //has to have enought size to hold the locations of derived methods. Run the below with
    //virtual and without to see results.

    std::cout << "sizeof(Shape) :" <<sizeof(Shape) <<"\n"; // 1 for virtual off | 8 virtual on
    std::cout << "sizeof(Oval) :" <<sizeof(Oval) <<"\n"; //16 for virtual off | 24 virtual on
    std::cout << "sizeof(Circle) :" <<sizeof(Circle) <<"\n"; //16 for virtual off | 24 virtual on

    //as you can see the size for each class has gone up significantly. So what is happening behind
    //the scenes? It wasn't explitly stated in lecture, but my guess is as follows...

    //The "1" we recieve as as size of class Shape is the bare minimum size of a function. 
    //That taken into account, we see that the size of Shape jumps up ~8 bytes 
    //when DrawShape() is given the virtual modifier.

    Oval* ptrOval{};
    std::cout << "sizeof(ptrOval) : " << sizeof(ptrOval) << "\n";

    //Well would you look at that. The size of a ptr to a class is 8 bytes! By giving a class
    //a virtual member, the class now has to store a ptr to another class. A DERIVED CLASS.
    //When we make a call on Shape class to a virtual function, there is some house keeping behind
    //the scenes where it probably checks to see if a hidden ptr ,example ptrToDerivedClass_, has 
    //a non-nullptr value. If it does, we move the call to that class.

    //Since placing a virtual modifier on a base class member carries over to all subsequent derived
    //members, each subsequent class in the hierchy chain also has to have a pointer to a possible
    //class derived from it. This is why the size of each class went up by 8 bytes when we added
    //virtual to Shape's DrawShape() method.

    //My guess is that if Shape had more functions that we labeled virtual, it would not increase its
    //size further. Instead one pointer to a derived class exists and a conditional flag is set on
    //each member. If the member is set 'virtual' it needs to check if there is an address stored.
    //If not, it doesnt check ptrToDerivedClass_ at all.


    //Breaking train of thought. When we perform slicing you can see that we do not store the entire
    //derived class. After slicing we only have a base class. No way to get original class back.

    std::cout<< "sizeof(shapeB) :" << sizeof(shapeB) <<"\n";

    return 0;
}
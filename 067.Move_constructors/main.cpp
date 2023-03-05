#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Move constructors

    //So it looks like a move constructor is very similar to the default copy constructor,
    //      The address of pointers to objects are copied exactly, HOWEVER, instead of leaving
    //      the old object alone, the move constructor will set those pointers to nullptr in the source object.

    //A good way of describing the move constructor is as a thief. It steals the data from already built objects
    //so the new object doesn't have to go through the rigormoral of setting up the data itself. Great for large objects!

    //The example given by the lecture is that of stealing the data of a temporary object to construct a lasting one.
    //Look below!

    Point pointA(Point(22.3, 99.5)); //idk why the lecturer added this line...
    
    //most compilers will recognize the redundancy above and optimize it out, pointless? ...

    //lecture shows the below way to evoke the move constructor |   It also forces the temp object to be created so
                                                        //      |   we actually lose efficiency with the below, but
    Point pointB(std::move(Point(22.3,99.5)));          //      |   I suppose it is the simplest way to demonstrate std::move()

    //I am sure I will run into a decent way to use this later. Perhaps saving the data of an object right before it leaves scope...
    
    return 0;
}
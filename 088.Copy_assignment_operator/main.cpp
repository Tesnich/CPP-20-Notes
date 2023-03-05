#include <iostream>
#include "Point.h"

using namespace Geometry;

int main(int argc, char **argv){

    //Copy assignment Operator

    //Comes in handy when developing classes that use dynamically allocated memory on the heap

    //I previously had experience in making deep copies earlier on in the course with the use
    //of a custom constructor that took a reference to an object of the same class.

    //From there I would allocate new memory on the heap and copy into it the value stored
    //stored where the source object had its pointer pointing to

    //In addition to that method it appears that we can also overload the assignment operator.
    //The difference being, if both the source and target objects objA and objB are already initalized,
    //we can inteligently load the target the with the contents of the first, in newly alocated spots on
    //the heap.

    //Examine Point.h and .cpp

    Point pointA{}, pointB(10,10);
    std::cout << "pointA : " << pointA << std::endl;
    std::cout << "pointB : " << pointB << std::endl;
    std::cout << ">> pointA = pointB <<" << std::endl;
    pointA = pointB; //calling custom overload
    std::cout << "pointA : " << pointA << std::endl;
    std::cout << "pointB : " << pointB << std::endl;

    //a point was brought up in lecture with regards to a possible bug where an object is assigned to itself
    //is this really a problem as simple as I have written this? Lets see...
    Point& pointB_ref{pointB};
    pointB = pointB_ref;

    std::cout << ">> pointB = pointB_ref; finished executing <<" << std::endl;
    //seems to work fine... because I'm not doing something ridiculous.
    //In the lecture the prof writes the overload to release the memory first then allocate new
    //memory from the input parameter object. This is how I structured mine before I caught myself.

    //!!!!! Essentially if you delete or reset pointers in the assignment overload you need to implement
    //a check to see if they are the same object, otherwise you release the memory then imediately
    //come back to use that released memory to initialize new heap memory, accessing memory that isn't
    //ours. Thats a pretty important thing to avoid.


    //something to be aware of, the below line wont compile

    //Point pointC = pointB;

    //This is because of a few reasons I think...
    //  A.) The first reason, and what I would expect, is that the above really isnt a call to the
    //      custom assignment operator overload we just wrote. What this is really being parsed by
    //      the compiler to do is construct pointC using pointB as an input parameter. 
    //
    //  B.) Ok, so what? You understand that it wouldn't call our custom assignment overload,
    //      but shouldnt it still compile? Shouldn't it call the default copy constructor and build
    //      a shallow copy at the very least?
    //      Well yeah, thats what I thought, EXCEPT that our member vars are UNIQUE POINTERS. With 
    //      unique pointers you are not allowed to copy from one to another! The default copy constructor
    //      for this class is automatically deleted because it wouldn't compile! Now that is nifty.

    return 0;
}
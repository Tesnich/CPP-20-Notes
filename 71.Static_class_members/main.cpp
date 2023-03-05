#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Static members...

    //usually member variables are different spaces in memory for each instance of a class
    //  However, static member variables of a class are shared with all instances!

    //Examine point class to see how this is used with the constructor and destructor to track
    //  - number of point objects
    //  - max of x and y for all point objects

    Point a(0,5);
    {
        Point b(1,1);
    }
    Point c(9,1);
    Point d(1,9);
    Point e(0,0);
    e.DisplayMetaData(); //Displays data compiled from multiple Point objects without user writing a lick of code in main.cpp!
                         //     Now THAT is neat!

    //I added the static vector of addresses to other points and updated DisplayMetaData()
    //  to display the object it is called on's distance to other points. 
    //  THIS BLOWS MY MIND! It is so freaking cool!!!

    //This does beg the question though... how reusable is this code WITHIN THE SAME PROJECT?
    //Like imagine something as big as the cad software I used to write... If there is any time where
    //this code is used by two different projects, could it cause a problem? Yes, I think so...

    //Something to gnaw on with the brain...

    //  If a method is set as const the compiler will typically prevent you from making changes to
    //  member variables in the const objects you call it in.
    //  >>>> HOWEVER <<<<
    //  Because static member functions do not belong to any particular instance of class, the
    //  compiler WILL let you modify them. Trippy, but it makes sense if you think about it.
    //      Basically, static member functions are created before any class objects are created.
    //      It has to service both non-const and const instances of the class. Because it doesn't know
    //      which kind of objects will be created during runtime, creating a non-const static var is the only choice.

    //      So the compiler is never going to yell at you, because you are never actually trying to
    //      assign to a non-const variable.

    //  I'm starting to understand this whole coding thing a little too well haha...

    
    //Additionally with these static vars, you can access them with just a class scope operator as long as they are public!

    std::cout <<"Point::publicStaticTest : " << Point::publicStaticTest << std::endl <<std::endl;

    //look in the header for a lot more info on inline static const member variables!!!


    //STATIC METHODS (AKA static member functions)

    //static member functions are callable without refering to an instance of the class
    //below you'll see where I have re-written DisplayMetaData() as a static member function
    //  overloaded with the input parameter of a pointer to the point class
    //  which simply calls the other version of DisplayMetaData(). 
    //      Nothing new is accomplished, this is just to show off static member methods.

    Point::DisplayMetaData(e);
    //      ^- Static member function declared with keyword "static" in header and is defined 
    //      like a normal member function in the .cpp

    //Static members can be void, return a value, have input arguments, use references, pointers etc...
    //  Don't mistake my laziness in reusing DisplayMetaData() as a requirement in naming or input
    //  arguments having to be instances of a class (although most of the time it just makes sense)

    //To be honest, a GREAT, static member function to implement here would be something like
    //  Point::ScalePoints(double multiplier); 
    //For which we could access the vector of all known points and scale the grid by multiplier!
    //Its greate because if it doesnt require an object there is no mistaking it as a function that
    //will only effect one object. (Easier to understand it effects all instances of class)

    return 0;
}
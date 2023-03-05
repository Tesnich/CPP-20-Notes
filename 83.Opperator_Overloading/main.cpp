#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Operator Overloading

    //The process in which we associate custom processing for the use of standard operators
    //on classes we write ourselves ie... +,-,*,/ etc...

    Geometry::Point pointA(5,10);
    pointA.PrintData();

    Geometry::Point origin{};
    origin.PrintData();

    std::cout << "Distance from pointA to Origin is : " << Geometry::Point::CalculateDistance(&origin,&pointA) << std::endl;

    Geometry::Point pointB(1,1);
    pointB.PrintData();

    //look in Point.h and .cpp for operator overloading
    //operator+
    Geometry::Point pointC{pointA + pointB};
    pointC.PrintData();

    //to note about the above... technically all I have overloaded is the + operator and made it
    //so that it returns a new point. At the moment there is no copy constructor implemented so
    //either pointC is a shallow copy of the temp result of pointA+pointB or the compiler was 
    //clever enough to optimize the result to store the newly created result directly into pointC.

    //This should be easy enough to see if we allow for constructor visability.
    Geometry::Point::ConstructorVisibility(true);
    Geometry::Point pointD{pointA + pointB};
    Geometry::Point::ConstructorVisibility(false);
    //With the option on we can see that the compiler was smart enough to store the temp
    //directly into the point we were creating in main. Only one constructor was called.

    //I have overloaded + (again) so that it accepts a double as right hand argument...
    Geometry::Point pointE{origin +9.9};
    pointE.PrintData();
    //Works perfectly fine!


    //operator overload as a non member functions

    //where as before we had overloaded the operator+ function as a member of the Point class, we will now create one
    //that is a static global function and exists without an instance of the class

    //look at the end of the point.h file for the Point overload of operator-
    //NOTICE it is OUTSIDE the class declaration...
    (Geometry::Point(20.0,20.0) + Geometry::Point(1,1)).PrintData(); //class member function overload
    (Geometry::Point(20.0,20.0) - Geometry::Point(1,1)).PrintData(); //non-class member function overload
    //both work exactly the same! (well despite the - and + functionality)

    //NOTE - Techincally the non class operator- overload is defined within the Geometry namespace,
    //however, it does not appear that we need to resolve the scope for the call
    //curious...

    //I have overloaded operator* outside of the class AND namespace
    //(Geometry::Point(20.0,20.0) * Geometry::Point(2,2)).PrintData();
    //Yeah the above doesnt compile

    //we can also explicitly state the call of opperators we overload as non member functions
    (operator- (Geometry::Point(20.0,20.0), Geometry::Point(1,1))).PrintData();
    //not that this is super useful, but know that this is a possibility...


    //Overloading the subscript operator for reading
    //ie... 'array[i]' format

    //This will allow us to read the x and y coordinates of our point objects using the values 0 and 1
    //unlike the + and - opperators, this has to be overloaded as a member function
    Geometry::Point pointF(11.11, 99.99);
    pointF.PrintData();
    std::cout << "pointF[0] : " << pointF[0] << std::endl;
    std::cout << "pointF[1] : " << pointF[1] << std::endl;

    //with the first overload for subscript I was returning a normal double, HOWEVER, if I make another to
    //return a double ref 'double&' we will then be able to use this format to change the data too!

    pointF[0] = 22.22;
    pointF.PrintData(); //it works!
    std::cout << "pointF[0] : " << pointF[0] << std::endl;
    std::cout << "pointF[1] : " << pointF[1] << std::endl;

    //reasoning for writing another another overload instead of editing the current
    //is that this current one is a const member function, facilitating reading but
    //not editing of object members. Can't return a non const ref. If we made in non const
    //then subscripts couldn't be used on const objects of that class.

    //Thus, best approach is to have two functions.

    return 0;
}
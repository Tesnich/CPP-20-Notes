#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Default ordering with <=>
    //Three way comparison operator

    //This allows access to >, >=, <, <=, ==, !=

    //In c++20 if you set up a <=> overload, the above will be automatically derived from it

    //check point.h for default implementation of the <=> operator, implemented just like == overload default

    Geom::Point pointA(1,2), pointB(1,3);
    Geom::Point pointC(9,1), pointD(1,3);

    //Default compares each member var in order of initialization. As set up in point.h,
    //this means x_ then y_

    std::cout << std::boolalpha;
    std::cout << "pointA(1,2) > pointB(1,3) : " << (pointA > pointB) << "\n";
    //      ^since <=> is the only operator overloaded, the C20 compiler derives > overload in
    //       terms of <=>'s implementation
    //
    //       ie. the overload for > on Point is most likely...
    //
    //              bool opperator>(const Point& pointB){
    //                 return (pointA <=> pointB) > 0;
    //              }
    //
    //      This is somewhat similar to how rel_ops templates are implemented using negation of < and ==
    //      My guess is that these are created from templates in terms of <=> instead,
    //      most likely always present but unable to build if <=> hasn't been overloaded
    //
    std::cout << "pointA(1,2) < pointB(1,3) : " << (pointA < pointB) << "\n";
    std::cout << "pointC(9,1) > pointD(1,3) : " << (pointC > pointD) << "\n";
    std::cout << "pointC(9,1) < pointD(1,3) : " << (pointC < pointD) << "\n";
    //the resulting output of the above shows how the earlier member vars are compared before
    //later ones for default <=> implementation 

    //my guess is there is some sort of short circuit evaluation behind the scenes for > and < where
    //the first member comparison to not be equal prevents following members from being checked
    //since they would have no impact on result
    

    return 0;
}
#include <iostream>
#include "Item.h"
#include "Point.h"

int main(int argc, char **argv){

    //Default Equality operator overload

    //chec out class Item
    Item itemA(1), itemB(1);

    std::cout << "itemA == itemB : " << (itemA == itemB) << "\n";
    //if you set up an == overload c++20 will generate a != operator for you for free
    std::cout << "itemA != itemB : " << (itemA != itemB) << "\n";
    //The above builds fine!

    //something fun, before if we wanted the ability to add or compare and int and an item of this class
    //we would have to ensure that either the int came second (and therefore could be implicitly converted)
    //or
    //we would have to write the overload for said comparison to be a non member taking in (const Item& ref1, const Item& ref2)

    //however, since itemA == itemB is equivalent to itemB == itemA
    //if we try the below
    std::cout << "(5 == Item(5)) : " << (5 == Item(5)) << "\n";
    //it succeeds even though we implemented the == overload as a member function
    //This is because the compiler is smart enough to identify that equivalency operation results
    //are not dependent on order, and re-arranges our statement in the Translation Unit to be 
    //something akin to...
    //      std::cout << "(5 == Item(5)) : " << (Item(5) == 5) << "\n";
    //and call the == member function on Item(5)
    //where our new rhs int 5 can be implicitly converted to an Item through the constructor we created on
    //line 9 of Item.h

    //Smart compiler!

    //this behavior extends to the automatically generated != overload
    std::cout << "(5 != Item(5)) : " << (5 != Item(5)) << "\n";

    //but what if we do not necessarily want to compare direct member vars? Well we need to implement our
    //own custom == operator.

    //Check out Point.H where the Point class has its == operator overloaded to be true if the points
    //distances to the origin are equivalent

    Geom::Point pointA (-2,4), pointB(2,4);
    //The above would fail a default member wise comparison, but with our special logic
    std::cout<< "Point(-2,4) == Point(2,4) : " << (pointA == pointB) << "\n";
    //!= automatically implemented just like with default
    std::cout<< "Point(-2,4) != Point(2,4) : " << (pointA != pointB) << "\n";

    return 0;
}
#include <iostream>
#include "Item.h"
#include "Point.h"

int main(int argc, char **argv){

    //Custom <=> operator overloading

    //I have written the Item class in such a way that it has two member vars...
    //      1.) unsigned int instanceId_ - set on construction using an ever increasting static unsigned int
    //      2.) std::unique_ptr ptrVal_ - set on construction via int or pulled during copy construction

    //For this class I wrote a custom copy constructor that will create a new unique_ptr to a new spot
    //on the heap with the same value as its source. 

    //If itemB is made from itemA then the instanceId_ will be one more, the address stored in ptrVal_ will
    //differ, but the de-reference of ptrVal_ will be the same.

    //Since I wrote this in such a way that every instance of the class will have a different instanceId_,
    //a default implementation of a <=> overload would be pointless, always returning a false based on that
    //value alone. Additionally, imagine we have no interest in whether the address of our stored value is
    //when comparing, we only want to know if the values are the same.

    //Thus, we must implement a custom spaceship overload in Item.h...

    Item itemA(99);
    Item itemB{itemA};
    std::cout << itemA << "\n" << itemB << "\n";
    std::cout << "((itemA <=> itemB) == 0) : " << ((itemA <=> itemB) == 0) << "\n";

    //Ta-da! We have written a spaceship overload that works for our needs, returning true for the
    //comparison of these two objects.

    //By overloading <=> successfuly we also generate all of the standard comparison operators!
    std::cout << "(itemA < itemB) : "<< (itemA < itemB) << "\n";
    std::cout << "(itemA <= itemB) : "<< (itemA <= itemB) << "\n";
    //NOTE!!!! Unfortunately, if we write a custom spaceship overload we DO NOT automatically
    //generate overloads for == and !=.
    //HOWEVER!!!! If we do a default <=> overload for any class, all logical operators are created!
    //This includes == and != .

    //In some cases we may not be able to delegate further to <=> on member functions.
    //Ints support <=>, but if we are making use of custom classes that were written before
    //CPP20 and still want to make use of the spaceship we will have to manually return the
    //results

    //examine the point class to see how we do this... (check out Point.cpp, juicy info there!)
    Geom::Point pointA(1,1), pointB(1,2);
    //we do the manual work of providing 'less', 'greater', 'equivalence', and 'unordered' results
    //in our overload, and it works just as fine as the delegation of <=> in the Item class
    std::cout << "((pointA <=> pointB) < 0) : "<< ((pointA <=> pointB) < 0) << "\n";
    //again, by successfully overloading <=> we get access to the 4 logical operators
    std::cout << "(pointA < pointB) : "<< (pointA < pointB) << "\n";
    std::cout << "(pointA <= pointB) : "<< (pointA <= pointB) << "\n";
    std::cout << "(pointA > pointB) : "<< (pointA > pointB) << "\n";
    std::cout << "(pointA >= pointB) : "<< (pointA >= pointB) << "\n";
    //Compile Error vvvvvvv == overload not automatically generated from custom <=> overload
    //std::cout << "(pointA == pointB) : "<< (pointA == pointB) << "\n";

    //reminder ==, !=, and <=> overloads support implicit construction from either side unlike member function
    //overloads of <,<=, >,>= that need to be implemented as non member functions inorder to do so
    //(clever compiler re-arrangement of expression)

    return 0;
}
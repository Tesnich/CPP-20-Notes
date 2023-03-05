#include <iostream>
#include "ClassWithFriends.h"

int main(int argc, char **argv){

    //Setting friend functions for class templates

    //overloading the << operator to work on and return std::ostream references, means that the overload
    //we create cannot be a member function of the class.

    //In the past declared this method as a friend of the class in question so it could directly
    //access member variables without going through accessors

    //How does this work for classes?

    //Checkout ClassWithFriends.h

    ClassWithFriends classWithFriends{10};
    std::cout << "classWithFriends : " << classWithFriends << "\n";

    return 0;
}
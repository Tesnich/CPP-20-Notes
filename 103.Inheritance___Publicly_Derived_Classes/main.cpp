#include <iostream>
#include "UcGraduate.h"
#include "Engineer.h"

int main(int argc, char **argv){

    //Inheritance! (Getting into the good stuff)

    //Inheritance is a feature in c++ that allows us to build classes based on already existing
    //classes

    // class Graduate
    //          |
    //          `--- class Engineer
    //                         |
    //                          `--- class Computer Science

    //For instance, an Engineer class can be built off a person class, and subsequently
    //a Computer Science class could be built off that Engineer class.

    //Ultimately, through inheritance the Computer Science class could be seen as a
    //"Computer Science Engineer Graduate" class, implementing all the members and functions declared
    //in the above classes. This allows for a tremedous amount of code re-use.

    //Inheritance tree
    //Shows the path of inheritance from class to class
    //
    //             class Graduate
    //                     |  |
    //    class Doctor <--'    `--> class Engineer
    //          |   |                      |   |
    //  ... <--'     `--> ...      ... <--'     `--> class Computer Science
    //

    //check out the first class defined in UcGraduate.h
    UcGraduate gradA("James","Hillman");
    std::cout << "gradA : " << gradA << "\n";

    //now check out Engineer.h, where Engineer is derived from public UcGraduate

    //Doesnt look like constructors are shared (at least from a publicly derived class)
    //Illegal call!!! vvvvvvvvvv
    //Engineer engineerA("James", "Hillman");

    //right now the only decent constructor we have takes in a string for engineeringID_, lets try it
    Engineer engineerA("554433");
    std::cout<< "engineerA : " << engineerA <<"\n"; //<< overload not shared for below reason
    //There is a friend class declared in UcGraduate that has the input arguments (std::ostream&, const UcGraduate&)
    //that prints private member vars .firstName_ and .lastName_ (direct access).

    //Another friend class was declared in Engineer that has the input arguments (std::ostream&, const Engineer&)
    //and it prints .engineeringId_ (direct access) and firstName()/lastName() (public accessors)

    //Obviously this friend class is useless to us in the Engineer class, because Engineer 
    //is a different class from UcGraduate! It will only be called if UcGraduate is the rhs of an ostream.

    //  *NOTE
    //  I think I am getting a little ahead of the material, but I imagine we could get around this
    //  by making the non-member << overload in UcGradute a template instead. This template could take
    //  in a typename T instead of the UcGraduate and call something like GetMembers(). Get members
    //  could be created on each class and retrieve all data members we want to print, and have the
    //  template body print them all out. (I'll save this for my own experimentation though)

    engineerA.firstName("James");
    engineerA.lastName("Hillman");
    //Becuase UcGraduate had the above public accessors for firstName_ and lastName_, our 
    //publicly derived class inherited those functions. We can now use them to set the obfuscated
    //firstName_ and lastName_ that exist on our Engineer instance. Without them we would be carrying
    //those members as dead weight, unable to read or write to them.

    //It is through these public members that we are able to read the names in our <<overload on Engineer
    std::cout<< "engineerA : " << engineerA << "\n";


    return 0;
}
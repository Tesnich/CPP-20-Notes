#include <iostream>
#include "Dice.h"

int main(int argc, char **argv){

    //Abstract Classes as Interfaces

    //An interface in Object Oriented Programming is an abstract class
    //that only has pure virtual functions and no member variables.

    //In a nutshell, an interface serves as a specification or blueprint to be fully implemented in
    //a derived class. 


    //Ok, so this is actually very clever. The way to make full use of an interface is by declaring a friend
    //in it that ultimately calls the class.

    
    //Look at how the StreamInsertable interface is used to easily grant a << overload to any class that 
    //inherits from it (and overrides the associated pur virtual method)
    Dice dice{};
    for(size_t i{}; i<5; ++i){
        std::cout << "Dice roll is " << dice << "\n";
    }

    //Obviously this is a ton of work to save maybe like one line each overloading << in derived classes,
    //but it highlights how powerful interfaces are! We can provide functionality to classes with very little
    //implementation on the classes themselves! Create straight to the point simple pure virtual functions to handle
    //the important changing bit per class, and leave the majority of processing to a friend of the interface.

    //I imagine the same could be done by putting that functionality in the class (which wouldn't make it an interface)
    //just an abstract class, but the advantages of doing it one way and not the other is unknown to me.

    return 0;
}
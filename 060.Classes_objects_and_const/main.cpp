#include <iostream>
#include <iomanip>
#include <string_view>
#include "Dog.h"

const unsigned int SEPERATOR_LENGTH = 50;

inline void LineBreak(std::string_view message){
        std::cout << std::setw(SEPERATOR_LENGTH) << std::setfill('-') << message << std::setfill(' ') << std::endl;
}

void DogPassByValue(Dog dogObject){
    dogObject.name("Maxine");
    dogObject.PrintInfo();
}

void DogPassByPtr(Dog *dogObject){
    dogObject->name("Maxine");
    dogObject->PrintInfo();
}

void DogPassByRef(Dog &dogObject){
    dogObject.name("Maxine");
    dogObject.PrintInfo();
}

int main(int argc, char **argv){

    //objects and the const keyword

    LineBreak("non const Dog object Dog1");

    Dog dog1("Flatcher", "Sheppard", 3);
    dog1.PrintInfo();
    dog1.name("Charlie"); //setter for name
    dog1.PrintInfo();

    LineBreak("const Dog object Dog2");

    //if you create a const instance of an object you will be locked out of public member functions

    const Dog dog2("Spot", "Beagle", 4);
    //illegal!!!
    //dog2.name("Max"); //because dog2 is a const object non const method name() wont build!

    //because the compiler isnt aware which dog2 public methods will read or write to all objects they are locked out!

    //HOWEVER! we can tell the compiler which member methods should be callable when an object instance is const!!
    //  this is done by declaring BOTH method declarations and definitions const! Goes after the input argument parentheses () but before the ; for declarations and before {body} in definitions
    //  for ie. examine getters and printInfo() methods in dog.h and dog.ccp!

    dog2.PrintInfo();

    //interestingly enough, the const specifier is enough to overload a method!!
    //  you could have one method name but two distinct functionalities based on if the object is const or not!
    dog1.ShowConstStatus();
    dog2.ShowConstStatus();
    std::cout << std::endl;

    //what happens when we try to pass a const object in as input for a function?
    //  The same thing as if we were to pass a const variable!
    //  We can pass a const Dog into a method that accepts a dog pass by value (a non const copy of dog is created we can edit)

    LineBreak("const Dog2 pass by value (copy)");
    DogPassByValue(dog2);   //The copy of dog2 will be completely editable in this method
                            //careful though, in doing so we inadvertantly copy pointer to heap int ptrAge_ and delete it when it leaves scope
                            //dog2 will now cause program crash when it leaves scope and tries to delete ptrAge_ itself

    //because dog2 is a const object, it cannot be used as input for methods that take pointers or ref to non const objects

    //wont compile 
    //DogPassByPtr(&dog2); // (cant establish a non const pointer to const object)

    //wont compile 
    //DogPassByRef(dog2); // (cant establish a non const ref to const object)

    //if you wanted to though, you could write methods with const input arguments and they would work
    //ie...
    //          void DogPassByPtrToConst(const Dog* dogObject) {...}
    //          void DogPassByRefToConst(const Dog& dogObject) {...}
    //
    //but since the dogObject alias for dog2 are still refering to a const instance of dog,
    //      you will only be able to run const memeber methods

    std::cout << "Error below from deletion of copied pointer to heap memory!" << std::endl;

    return 0;
}
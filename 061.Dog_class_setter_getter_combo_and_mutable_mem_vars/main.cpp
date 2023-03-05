#include <iostream>
#include <iomanip>
#include <string_view>
#include "Dog.h"

const unsigned int SEPERATOR_LENGTH = 50;

inline void LineBreak(std::string_view message){
        std::cout << std::setw(SEPERATOR_LENGTH) << std::setfill('-') << message << std::setfill(' ') << std::endl;
}

void DogPassByValue(Dog dogObject){
    dogObject.name() = "Maxine"; //using reference returned by name() as setter
    dogObject.PrintInfo();
}

void DogPassByPtr(Dog *dogObject){
    dogObject->name() = "Maxine"; //using reference returned by name() as setter
    dogObject->PrintInfo();
}

void DogPassByRef(Dog &dogObject){
    dogObject.name() = "Maxine"; //using reference returned by name() as setter
    dogObject.PrintInfo();
}

int main(int argc, char **argv){

    Dog dog1("Flatcher", "Sheppard", 3);
    dog1.PrintInfo();
    dog1.name() = "Charlie"; //using reference returned by name() as setter
    std::cout << "NAME : " << dog1.name() << std::endl; //using reference returned simply for reading value
    dog1.PrintInfo();

    return 0;
}
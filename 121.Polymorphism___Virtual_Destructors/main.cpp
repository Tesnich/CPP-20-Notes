#include <iostream>
#include "Derived.h"
#include <memory>

int main(int argc, char **argv){

    //Virtual Destructors

    //essentially if you have something like

    //      Animal* animal1 = new Dog("dark yellow", "Spot");
    //      delete animal1;

    //Only the destructor for the animal object baked into Dog will be called. Dog will still exist
    //on the heap! MEMORY LEAK!!!

    //If we intend on deleting the entire object we need to specify the Base class' destructor as 'virtual'!

    //remove or add virtual to the Base.h class to see impact

    std::unique_ptr<Base> uniquePtrBase{std::make_unique<Derived>()};

    uniquePtrBase.reset();

    //See the difference? Without that virtural keyword the Derived class continues to live on!


    //With the above lesson it is becoming quite cleary to me how useful polymorphism can be in creating and managing
    //different types of objects. This is actually quite lovely!

    //ie... you can have an array of entities in a video game all with their on functionality and rendering. As long
    //as they inherit from one class that has a virtual destructor implemented, all of them can be completely deleted
    //without having to go to the effort of specifying the most derived classes' destructors!

    //Coding is so cool!

    return 0;
}
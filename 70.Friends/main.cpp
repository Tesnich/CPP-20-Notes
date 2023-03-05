#include <iostream>
#include "Dog.h"
#include "DogReader.h"

//friend function in Dog.h
void debug_dog_info(const Dog& dog)
{
    //friend functions are not member functions...
    //  as such they do not have access to "this" or direct access to memeber vars through name only "dogName_"
    //
    //Since friend functions are not bound to an instance of a class when called
    //  they can only access member vars through the class itself, accessing data memebers
    //  like they were public memebers of a class or struct
    //                       ____________                             ___________
    std::cout << "Name :" << dog.dogName_ << std::endl << "Age  :" << dog.dogAge_ << std::endl;
    //                       ------------                             -----------
    //Since this function was declared as a friend in the Dog class the above private members were
    //accessed without issue!
}

//friend function in Dog.h
void debug_dog_info()
{
    //being declared a friend function means any it can access the data for any instance of the class
    //the class doesnt have to be passed in... ie. The below expression creates a dog object in this
    //scope and the function accesses it's data just like normal
    Dog internalDog("Pinch", 4);
    //                       ____________________                             ___________________
    std::cout << "Name :" << internalDog.dogName_ << std::endl << "Age  :" << internalDog.dogAge_ << std::endl;
    //                       ____________________                             ___________________
}

int main(int argc, char **argv){

    //Friends...    Method to give acces of a class' member variables to external functions or classes.

    //examine Dog class header for declaration of friend functions
    Dog superDog("Charlie", 8);
    debug_dog_info(superDog);
    debug_dog_info();

    //examine Dog class header for declaration of friend class DogReader
    DogReader dogReader(&superDog);
    dogReader.Read();

    //friendship declaration works in one direction
    //DogReader was declared as a friend of Dog, that doesn't mean dog is a friend to DogReader

    return 0;
}
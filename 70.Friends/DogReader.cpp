#include "DogReader.h"
#include <iostream>

//DogReader class is declared as a friend of Dog, allowing access to private class members
void DogReader::Read(){
    std::cout << "Name :" << ptrDog_->dogName_ << std::endl << "Age  :" << ptrDog_->dogAge_ << std::endl;
}
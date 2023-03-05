#include "Dog.h"

Dog::Dog(std::string_view dogName, int dogAge)
{
    dogName_ = dogName;
    dogAge_ = dogAge;
}
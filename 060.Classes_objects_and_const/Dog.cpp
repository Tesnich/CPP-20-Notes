#include "Dog.h"
#include <iostream>
#include <iomanip>

Dog::Dog(const std::string& name, const std::string& breed, int age)
{
    name_ = name;
    breed_ = breed;
    ptrAge_ = new int{age};
}

Dog::~Dog(){
    delete ptrAge_;
}

//setter
void Dog::name(const std::string& name){
    name_ = name;
}
//getter
//                        allow for name() to execute when an instance of Dog object is declared const
//                        V
std::string Dog::name() const {
    return name_;
}

//setter
void Dog::breed(const std::string& breed){
    breed_ = breed;
}
//getter
//                         allow for breed() to execute when an instance of Dog object is declared const
//                         V
std::string Dog::breed() const {
    return breed_;
}

//getter
//                  allow for ptrAge() to execute when an instance of Dog object is declared const
//                  V
int Dog::ptrAge() const {
    return *ptrAge_;
}

//                      allow for PrintInfo() to execute when an instance of Dog object is declared const
//                      V
void Dog::PrintInfo() const{
    std::cout << std::setw(TABLE_SPACING_) << "Name :" << std::setw(TABLE_SPACING_) << name_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Breed :" << std::setw(TABLE_SPACING_) << breed_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Age :" << std::setw(TABLE_SPACING_) << *ptrAge_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Address :" << std::setw(TABLE_SPACING_) << this << std::endl << std::endl;
}

void Dog::ShowConstStatus () const{
    std::cout << "ShowConstStatus() was called with CONST overload!" << std::endl;
}
void Dog::ShowConstStatus (){
    std::cout << "ShowConstStatus() was called with NON CONST overload!" << std::endl;
}
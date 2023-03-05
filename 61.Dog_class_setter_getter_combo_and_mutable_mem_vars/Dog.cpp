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

std::string& Dog::name() {      // Where we had two distinct methods overloaded for getting and setting before,
    return name_;               //    ie. name() and name(std::string val),
}                               // We now have just one method with no input parameters that returns a reference
                                // to the std::string member variables.
std::string& Dog::breed() {     //
    return breed_;              // You can see these methods use in main.cpp to both
}                               //      Use the ref returned to set new values for the member variables (setter)
                                //      and only read the value of the ref returned (getter)
int* Dog::ptrAge() {            //
    return ptrAge_;             // Note that while this approach may save some room, there is no good approach we can use to
}                               // label the method as both const and non const to seperate read and write privileges.
                                // Only option would be to overload this with a const version that only returns a const ref. look below VVVVV

const std::string& Dog::name() const{ //this overload of the name method above will be called if its parent object is const
    return name_; //because of the const modifier on the function we are telling the compiler that it shouldnt modify anything in the object
}                 //as such it compiler will enforce no changes. The return type also must be const std::string ref since the compiler yells at you for dropping the
                  //const on name_, this must mean that in creating a const object, code wise all member variables are given const specifier

void Dog::PrintInfo() const{
    std::cout << std::setw(TABLE_SPACING_) << "Name :" << std::setw(TABLE_SPACING_) << name_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Breed :" << std::setw(TABLE_SPACING_) << breed_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Age :" << std::setw(TABLE_SPACING_) << *ptrAge_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Address :" << std::setw(TABLE_SPACING_) << this << std::endl;
    //interesting aspect of const objects, if you mark a variable as "mutable" you will be able to change it even if the object is const
    //this is useful for debugging purposes, like counting times a method executes
    ++printCount_; //printCount_ is marked mutable in header so even though PrintInfo() is const method we are allowed to edit the class!
    //Lecturer said this is somewhat dangerous because people dont expect const member methods to modify an object
    //  So try not to do this if it can be helped...
    std::cout << std::setw(TABLE_SPACING_) << "Print Count :" << std::setw(TABLE_SPACING_) << printCount_ << std::endl << std::endl;

}

void Dog::ShowConstStatus () const{
    std::cout << "ShowConstStatus() was called with CONST overload!" << std::endl;
}
void Dog::ShowConstStatus (){
    std::cout << "ShowConstStatus() was called with NON CONST overload!" << std::endl;
}
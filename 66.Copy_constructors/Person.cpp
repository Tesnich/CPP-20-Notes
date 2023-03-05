#include "Person.h"
#include <iostream>
#include <iomanip>

Person::Person( std::string_view lastName, std::string_view firstName, unsigned int age)
    :lastName_(lastName), firstName_(firstName), age_(new unsigned int {age})
{
}

Person::Person( std::string_view lastName, std::string_view firstName)
:Person(lastName, firstName, 0)
{
}

Person::Person( std::string_view lastName)
    :Person(lastName, "firstName")
{
}

std::string_view Person::lastName()const{
    return lastName_;
}
void Person::lastName(std::string_view lastName){
    lastName_ = lastName;
}

std::string_view Person::firstName()const{
    return firstName_;
}
void Person::firstName(std::string_view firstName){
    firstName_ = firstName;
}
        
unsigned int Person::age()const{
    return *age_;
}
void Person::age(unsigned int age){
    *age_ = age;
}

void Person::PrintInfo()
{
    std::cout << std::endl << "Person object (" << this << ")" << std::endl;
    std::cout << std::setw(tableSpacing_) << "lastName_ :" << std::setw(tableSpacing_) << lastName_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "firstName_ :" << std::setw(tableSpacing_) << firstName_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "*age_ :" << std::setw(tableSpacing_) << *age_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "age_ :" << std::setw(tableSpacing_) << age_ << " <- Look" <<std::endl<<std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//PersonSmartCopy ///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

PersonSmartCopy::PersonSmartCopy( std::string_view lastName, std::string_view firstName, unsigned int age)
    :lastName_(lastName), firstName_(firstName), age_(new unsigned int {age})
{
}

PersonSmartCopy::PersonSmartCopy( std::string_view lastName, std::string_view firstName)
:PersonSmartCopy(lastName, firstName, 0)
{
}

PersonSmartCopy::PersonSmartCopy( std::string_view lastName)
    :PersonSmartCopy(lastName, "firstName")
{
}

//Lecture version of copy constructor
// PersonSmartCopy::PersonSmartCopy( const PersonSmartCopy& sourcePerson)
//     : lastName_(sourcePerson.lastName()), firstName_(sourcePerson.firstName()), age_(new unsigned int {sourcePerson.age()}) {}

//Lecture version of copy constructor with delegation
PersonSmartCopy::PersonSmartCopy( const PersonSmartCopy& sourcePerson)
    : PersonSmartCopy(sourcePerson.lastName(), sourcePerson.firstName(), sourcePerson.age())
    {
        std::cout<< std::endl << " >>Custom Copy Constructor Called!<< " << std::endl;
    }

//Destructor
PersonSmartCopy::~PersonSmartCopy(){
    delete age_;
}

std::string_view PersonSmartCopy::lastName() const{
    return lastName_;
}
void PersonSmartCopy::lastName(std::string_view lastName){
    lastName_ = lastName;
}

std::string_view PersonSmartCopy::firstName() const{
    return firstName_;
}
void PersonSmartCopy::firstName(std::string_view firstName){
    firstName_ = firstName;
}
        
unsigned int PersonSmartCopy::age() const{
    return *age_;
}
void PersonSmartCopy::age(unsigned int age){
    *age_ = age;
}

void PersonSmartCopy::PrintInfo()
{
    std::cout << std::endl << "PersonSmartCopy object (" << this << ")" << std::endl;
    std::cout << std::setw(tableSpacing_) << "lastName_ :" << std::setw(tableSpacing_) << lastName_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "firstName_ :" << std::setw(tableSpacing_) << firstName_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "*age_ :" << std::setw(tableSpacing_) << *age_ <<std::endl;
    std::cout << std::setw(tableSpacing_) << "age_ :" << std::setw(tableSpacing_) << age_ << " <- Look" <<std::endl<<std::endl;
}
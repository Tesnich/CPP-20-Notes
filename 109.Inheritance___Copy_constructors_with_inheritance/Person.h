#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <iomanip>

class Person
{
    protected:
        std::string firstName_{}, lastName_{};
        const unsigned int spacing_{30};
    public:
        Person() = default;
        Person(std::string_view firstName, std::string_view lastName)
            :firstName_{firstName}, lastName_{lastName} {
                std::cout << "Person() constructor called!\n";
            }
        Person(const Person& source)
            :Person(source.firstName_, source.lastName_){//copy constructor delegation to constructor
                std::cout << "Person() Copy constructor called!\n";
            } 
        
        void PrintMemberVars(){
            std::cout<< std::setw(spacing_) << "firstName : " << firstName_ <<"\n";
            std::cout<< std::setw(spacing_) << "lastName : " << lastName_ <<"\n";
        }
};

#endif
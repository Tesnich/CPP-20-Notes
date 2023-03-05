#ifndef ENGINEER_H
#define ENGINEER_H
#include "Person.h"

class Engineer : public Person
{
    protected:
        std::string almamater_{};
    public:
        Engineer() = default;
        Engineer(std::string_view firstName, std::string_view lastName, std::string_view almamater)
            : Person(firstName, lastName), almamater_{almamater} {
                std::cout << "Engineer() constructor called!\n";
            }
        Engineer(const Engineer& source)
//            ______________ Similar to the constructor above, this copy constructor initializes the Person object
            : Person(source), almamater_{source.almamater_} {
//            ^^^^^^^^^^^^^^ Right here is a bit of clever c++ behavior. C++ is smart enough
//                           to recognize that you are trying to initialize a base class with
//                           a class that inherits from it, so it will strip away the derived bit,
//                           and in reality you end up with the calling the Person constructor
//                           with source's Person object as an argument. 'Person(Person)' This will
//                           end up calling Person's copy constructor!

//                           My first guess was that I had to do something like source::Person...
//                           This is nice! Just gotta remember this is how it works.
                std::cout << "Engineer() Copy constructor called!\n";
            }
        
        ~Engineer() {
            std::cout << ">> ~Engineer() called! <<\n";
        }

        void PrintMemberVars(){
            Person::PrintMemberVars();
            std::cout<< std::setw(spacing_) << "almamater : " << almamater_ <<"\n";
        }
};

#endif
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
//            ___________________________
            : Person(firstName, lastName), almamater_{almamater} {
//            ^^^^^^^^^^^^^^^^^^^^^^^^^^^ Constructor call for baked in Person base class!
                std::cout << "Engineer() constructor called!\n";
            }

        void PrintMemberVars(){
            //fyi vvvvvvvv You can use scope resolution operator if there are naming overlaps
            //between derived and base classes!
            Person::PrintMemberVars();
            std::cout<< std::setw(spacing_) << "almamater : " << almamater_ <<"\n";
        }
};

#endif
#ifndef CS_ENGINEER_H
#define CS_ENGINEER_H
#include "Engineer.h"

class CsEngineer : public Engineer
{
    protected:
        std::string programmingLanguage_{};
    public:
        CsEngineer() = default;
        CsEngineer(std::string_view firstName, std::string_view lastName, std::string_view alamater, std::string_view programmingLanguage)
            : Engineer(firstName, lastName, alamater), programmingLanguage_{programmingLanguage} {
                std::cout << "CsEngineer() constructor called!\n";
            }
        CsEngineer(const CsEngineer& source)
//            ________________ Similar to the constructor above, this copy constructor initializes the Engineer object
            : Engineer(source), programmingLanguage_{source.programmingLanguage_} {
//            ^^^^^^^^^^^^^^^^ Right here is a bit of clever c++ behavior. C++ is smart enough
//                             to recognize that you are trying to initialize a base class with
//                             a class that inherits from it, so it will strip away the derived bit,
//                             and in reality you end up with the calling the Engineer constructor
//                             with source's Engineer object as an argument. 'Engineer(Engineer)' This will
//                             end up calling Engineers's copy constructor!
                std::cout << "CsEngineer() Copy constructor called!\n";
            }

        void PrintMemberVars(){
            //fyi vvvvvvvv You can use scope resolution operator if there are naming overlaps
            //between derived and base classes!
            Engineer::PrintMemberVars();
            std::cout<< std::setw(spacing_) << "programmingLanguage : " << programmingLanguage_ <<"\n";
        }
};

#endif
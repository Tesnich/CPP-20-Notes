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
//            _______________________________________
            : Engineer(firstName, lastName, alamater), programmingLanguage_{programmingLanguage} {
//            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Constructor call for baked in Engineer base class!
                std::cout << "CsEngineer() constructor called!\n";
            }

        void PrintMemberVars(){
            //fyi vvvvvvvv You can use scope resolution operator if there are naming overlaps
            //between derived and base classes!
            Engineer::PrintMemberVars();
            std::cout<< std::setw(spacing_) << "programmingLanguage : " << programmingLanguage_ <<"\n";
        }
};

#endif
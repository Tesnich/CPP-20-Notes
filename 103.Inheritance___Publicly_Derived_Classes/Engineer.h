#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
#include <string>

//if you aren't making use of parent class attributes in class definition you dont need the below
#include "UcGraduate.h"
//You can forward declare instead
//class UcGraduate;

//below the engineer class is derived from the UcGraduate class.
//The important bit right now is the syntax with ':' which denotes the class to derive from 
//             ___________________
class Engineer : public UcGraduate
//             ^^^^^^^^^^^^^^^^^^^
//  With the syntax
//      class a : b {...}
//  class a is considered "derived" from class b. 
//
//  However, by putting the keyword 'public' infront of UcGraduate. We are stipulating that Engineer
//  should only be derived from the public aspects the UcGraduate class. In doing so Engineer is 
//  unable to directly access any of the private members of UcGraduate.
//
//  THIS IS IN RIGHTS ALONE. As far as I can tell, these members are created on the derived class.
//
//  Unless we give firstName_ and lastName_ accessors in UcGraduate, Engineer has no way of
//  using those members. (I did later... see operator<< overload)
//
//  The rights of a class extend to their declared friends. The opperator<< overload
//  declared as a friend below will also be unable to access private members of the source
//  class.
{
    friend std::ostream& operator<<(std::ostream& os, const Engineer& engineer);

    private:
        //note that the first name and last name member vars are not implemented here
        //however, because Engineer is derived from UcGraduate it has those members!

        //new member var
        std::string engineeringId_{};
    public:
        Engineer() = default;

        Engineer(std::string engineeringId)
            :engineeringId_{engineeringId} {}
        ~Engineer() = default;
};

inline std::ostream& operator<<(std::ostream& os, const Engineer& engineer){
    //illegal access using '.lastName_' and '.firstName_' (also needs full header not forward declaration of UcGraduate)
    //return os << "("<<engineer.engineeringId_ << " : "<< engineer.lastName_ << "," << engineer.firstName_ << ")";
    return os << "("<<engineer.engineeringId_ << " : "<< engineer.lastName() << "," << engineer.firstName() << ")";
};

#endif
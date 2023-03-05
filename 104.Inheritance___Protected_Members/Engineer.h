#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
#include <string>

//if you aren't making use of parent class attributes in class definition you dont need the below
#include "UcGraduate.h"
//You can forward declare instead
//class UcGraduate;


//FYI, the situation below seems to be refered to as "Public Inheritance"
class Engineer : public UcGraduate
{
    friend std::ostream& operator<<(std::ostream& os, const Engineer& engineer);

    private:
        //new member var
        std::string engineeringId_{};
    public:
        Engineer() = default;

        Engineer(std::string_view engineeringId)
            :engineeringId_{engineeringId} {}
        //ok...interesting point...I don't seem to have the ability to list initialize the protected
        //members I inherited from UcGraduate 
        Engineer(std::string_view engineeringId, std::string_view firstName, std::string_view lastName)
            //the below line is illegal because : "firstName_" is not a nonstatic data member or base class of class "Engineer"
            //
            //  :engineeringId_{engineeringId}, firstName_{firstName}, lastName_{lastName} {}
            //
            //My only other option at this point is to assign these in the body of this constructor...
            :engineeringId_{engineeringId} {
                firstName_ = firstName;
                lastName_ = lastName;
            }
        ~Engineer() = default;
};

inline std::ostream& operator<<(std::ostream& os, const Engineer& engineer){
    //since lastName_ and firstName_ of UcGraduate are in the protected clause instead of the private
    //our derived class Engineer has direct access to them. Since friends of a class share the
    //same rights as the class, this function is now able to directly access these members!
    return os << "("<<engineer.engineeringId_ << " : "<< engineer.lastName_ << "," << engineer.firstName_ << ")";
    //nary an accessor in sight :D
};

#endif
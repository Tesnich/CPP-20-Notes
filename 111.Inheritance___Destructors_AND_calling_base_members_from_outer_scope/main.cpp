#include <iostream>
#include "CsEngineer.h"
#include "Utilites.h"

int main(int argc, char **argv){

    //Destructors and Inheritance

    //Destructors are called in reverse order since Derived classes are dependant on their Base
    //intances. Observe...

    {
        CsEngineer CsEngineer("James", "Hillman", "University of Cincinnati", "C++");

        Util::PrintTitleLine("Calling Public base Methods From Outside Scope");
        //fyi, You should also know that you can access base class members with the following syntax
        //provided they were not obfuscated by protected or private inheritance
        CsEngineer.Person::PrintMemberVars();
        //dont even need to go through engineer...
        Util::PrintEndLine();
    }

    return 0;
}
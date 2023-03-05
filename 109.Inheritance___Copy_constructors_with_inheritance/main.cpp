#include <iostream>
#include "CsEngineer.h"
#include "Utilites.h"

int main(int argc, char **argv){

    //Copy constructors and inheritance

    //Essentially, if you your base class implements a custom copy constructor you can write your
    //derived class' copy constructor to utilize it using the initializer list syntax.

    //Observe modified classes from previous folder...

    Util::PrintTitleLine("csEngineer");
    CsEngineer csEngineer("James", "Hillman", "University of Cincinnati", "C++");
    csEngineer.PrintMemberVars();
    Util::PrintEndLine();

    std::cout << ">> CsEngineer csEngineerCopy(csEngineer) <<\n";
    CsEngineer csEngineerCopy(csEngineer);

    Util::PrintTitleLine("csEngineerCopy");
    csEngineerCopy.PrintMemberVars();
    Util::PrintEndLine();

    //For such simple classes as these there really wasn't a need to implement custom copy constructors.
    //With no member variables pointing to stack memory the default copy constructors would have
    //worked fine shallow copying one another. C++ is smart enough to call default copy constructors
    //for each level of inherited classes.

    //This folder serves as a great reference for more complex cases though...

    return 0;
}
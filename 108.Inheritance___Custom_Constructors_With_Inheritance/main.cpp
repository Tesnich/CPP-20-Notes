#include <iostream>
#include "CsEngineer.h"
#include "Utilites.h"

int main(int argc, char **argv){

    //Calling custom constructors from derived classes!

    //  We already saw earlier that there is no way to list initialize the members of a base class
    //  int he constructor of a derived class. Also, by the point you get to the body of the derived
    //  constructor we have seen that the default constructor for the base class has already been
    //  executed!

    //  So how do we call base constructors with non-default input?

    //  Well, think of the base class as a member variable of the derived class... We use
    //  an initializer list! Just like we would initialize an int or string, we can pass
    //  the arguments for a base constructor.

    //  Examine Engineer.h to see!


    //  In a way, this is somewhat like Constructor delegation but backwards. In constructor
    //  delegation, if you delegate construction to another constructor, that is the only thing
    //  you are allowed to put in the initializer list. In calling the constructor of a base 
    //  class, however, you are welcome to initialize member variables of the derived class
    //  after calling a custom constructor for the base class!

    Util::PrintTitleLine("Person person{...}");
    Person person("James", "Hillman");
    person.PrintMemberVars();
    Util::PrintEndLine();

    Util::PrintTitleLine("Engineer engineer{...}");
    Engineer engineer("James", "Hillman", "University of Cincinnati");
    engineer.PrintMemberVars();
    Util::PrintEndLine();

    Util::PrintTitleLine("CsEngineer csEngineer{...}");
    CsEngineer csEngineer("James", "Hillman", "University of Cincinnati", "C++");
    csEngineer.PrintMemberVars();
    Util::PrintEndLine();

    return 0;
}
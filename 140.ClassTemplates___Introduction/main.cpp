#include <iostream>
#include "BoxContainer.h"

int main(int argc, char **argv){

    //Class Templates

    //Remember, templates are blueprints to define classes or functions using types not known until compile time
    //WHEN WRITING CLASS TEMPLATE, DEFINITIONS SHOULD BE SPECIFIED IN SAME HEADER AS TEMPLATE!

    //Re-using BoxContainer class I built in previous folder...

    BoxContainer<int> intBoxContainer{10};
    intBoxContainer.AddItem(5);
    intBoxContainer.AddItem(6);
    std::cout<<"intBoxContainer : " << intBoxContainer<<"\n";
    BoxContainer<std::string> strBoxContainer{10};
    strBoxContainer.AddItem("Alpha");
    strBoxContainer.AddItem("Omega");
    std::cout<<"strBoxContainer : " << strBoxContainer<<"\n";

    //ta-da, our class now works with both ints and strings!

    //testing my hypothesis about manual definition of template class methods with concrete typenames
    std::cout<< intBoxContainer.capacity() << "\n";
    std::cout<< strBoxContainer.capacity() << "\n";

    //look at that! Works like a charm. Just need to tell the compiler we are specializing a template method
    //with the use of an empty 'template<>' line above the definition. COOL BEANS!

    //TO NOTE: quick reminder that if a method of a template is not used, no c++ method of that type will
    //be created. No real impact, just important to know. You can act like all the methods are there and it
    //will work fine.

    return 0;
}
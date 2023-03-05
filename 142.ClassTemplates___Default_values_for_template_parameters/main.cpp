#include <iostream>
#include "DefaultTemplate.h"

//We can also tell the compiler to generate a class from a template without calling its constructor...
//This is called EXPLICIT TEMPLATE INSTANTIATION
template class DefaultTemplate<std::string>;
//Why this is useful? I am not sure...

int main(int argc, char **argv){

    //Default values for template parameters

    //Normally if you call a constructor for a template class that takes no input, you will get a
    //compiler error because the template types can't be deduced

    //However, you can set up default parameters so that you dont have to. The template will
    //still work fine for cases where the template types are supplied

    DefaultTemplate defaultTemplate{};
    std::cout << "defaultTemplate.Type() : "<<defaultTemplate.Type() << "\n";

    DefaultTemplate<double> doubleTemplate{};
    std::cout << "doubleTemplate.Type() : "<<doubleTemplate.Type() << "\n";

    return 0;
}
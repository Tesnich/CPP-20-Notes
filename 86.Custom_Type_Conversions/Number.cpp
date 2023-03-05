#include "Number.h"
#include <iostream>

//still no return type needed for conversion
Number::operator double() const {
    std::cout << ">> Conversion to double triggered <<" << std::endl;
    return static_cast<double>(intVal_);
    //say we wanted to convert to a different custom class entirely, and not a standard type
    //instead of 'double()' we would have the class name 'ClassName()'
    //then we would create the object here, with whatever conversion processing needed
    //and return it! simple
}
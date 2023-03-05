#include <cstring>
#include <iostream>

//definition for raw overload for maximum, this will take precedence over going through template for matching type
const char * maximum (const char * a, const char * b)
{
    std::cout << "**** Raw Overload Ran!" << std::endl;
    return (std::strcmp(a, b) > 0)? a : b;
}
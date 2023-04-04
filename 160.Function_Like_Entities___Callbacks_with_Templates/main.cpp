#include <iostream>
#include "TemplateFunctions.h"

int main(int argc, char **argv){

    //Check out TemplateFunctions which defines compareItems template function as well as the compare functions
    //we intend on using

    //using namespace TemplateFunctions;
    //above works I just want to practice how to do this without global namespace modifier
    //scope resolution TemplateFunctions:: of namespace I defined in TemplateFunctions.h files

    double doubleA{10.0001}, doubleB{99.9999};
    int intA{2}, intB{88};

    std::string stringA{"SuperCalifragiSomething"}, stringB{"Cat"};

    std::cout << "Largest of doubleA and doubleB : " << TemplateFunctions::compareItems(doubleA, doubleB, TemplateFunctions::isLarger) << "\n";
    std::cout << "Smallest of doubleA and doubleB : " << TemplateFunctions::compareItems(doubleA, doubleB, TemplateFunctions::isSmaller) << "\n";

    //the compiler has enough information to deduce which instance of the template functions isLarger and isSmaller
    //we are using because of how we defined the template compareItems. The same typename T is shared between
    //all input arguments.
    std::cout << "Largest of intA and intB : " << TemplateFunctions::compareItems(intA, intB, TemplateFunctions::isLarger) << "\n";
    std::cout << "Smallest of intA and intB : " << TemplateFunctions::compareItems(intA, intB, TemplateFunctions::isSmaller) << "\n";

    std::cout << "Largest of stringA and stringB : " << TemplateFunctions::compareItems(stringA, stringB, TemplateFunctions::isLarger) << "\n";
    std::cout << "Smallest of stringA and stringB : " << TemplateFunctions::compareItems(stringA, stringB, TemplateFunctions::isSmaller) << "\n";

    //Beautiful!

    return 0;
}
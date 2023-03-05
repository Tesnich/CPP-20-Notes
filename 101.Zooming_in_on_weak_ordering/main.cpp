#include <iostream>
#include "ComparableString.h"
#include "CaseInsensativeString.h"

int main(int argc, char **argv){

    //Zooming in on Weak Ordering

    //Example 1

    //this example sees strings compared by size

    //imagine one is "Dog" and the other is "Fog", they are not equal but we can consider them equivalent
    //in terms of our need case

    //look in ComparableString.h ...

    ComparableString compStrA("Dog"), compStrB("Cat");
    //these should be equivalent because they both have 3 characters!
    std::cout << std::boolalpha;
    std::cout << "(compStrA == compStrB) : "<< (compStrA == compStrB) << "\n";
    std::cout << "((compStrA <=> compStrB) == 0) : "<< ((compStrA <=> compStrB) == 0) << "\n";
    //fyi, comparison with zero will return true for values of ::equal and ::equivalent
    //if specific need for notice of one or the other when using strong_ordering, directly compare it with std::strong_ordering::equal or ::equivalent

    //mission accomplished

    //I have used ComparableString as a template to write another class called CaseInsensativeString,
    //which rings equivalency when two strings have the same contents regardless of case

    CaseInsensativeString casInsStrA("pizza-call-555-555-5555"), casInsStrB("PIZZA-CALL-555-555-5555");
    std::cout << "(casInsStrA == casInsStrB) : "<< (casInsStrA == casInsStrB) << "\n";
    CaseInsensativeString casInsStrC("AAAA"), casInsStrD("aaab");
    std::cout << "(casInsStrC < casInsStrD) : "<< (casInsStrC < casInsStrD) << "\n";
    std::cout << "(casInsStrC > casInsStrD) : "<< (casInsStrC > casInsStrD) << "\n";
    std::cout << "(casInsStrC == casInsStrD) : "<< (casInsStrC == casInsStrD) << "\n";

    return 0;
}
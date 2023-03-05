#include <iostream>
#include <string>


int main(int argc, char **argv){

    //Three way comparison operator (c++ 20) A.K.A the spaceship operator <=>

    //An opperator that takes in two arguments (a and b) and tell us if 
    //a is < b, a is > b, or if both a and b are equal to one another

    //This is very similar to std::strcmp() call where the returned int value is
    //      negative - a is < b
    //      positve - a is > b
    //      zero - a and b are equal

    //the opperator syntax is <=>
    //Note! Unlike strcmp(), this new opperator doesn't actually return an int.
    //What it returns is a special type that is comparable to the literal 0.

    std::cout << std::boolalpha;
    std::cout << "((int{1} <=> int{2}) < 0) : " << ((int{1} <=> int{2}) < 0 )<< "\n";
    std::cout << "((int{2} <=> int{1}) < 0) : " << ((int{2} <=> int{1}) < 0 )<< "\n";
    std::cout << "((int{1} <=> int{1}) == 0) : " << ((int{1} <=> int{1}) == 0 )<< "\n"; //absolute equality
    std::cout << "((int{1} <=> int{1}) == 0) : " << ((int{1} <=> int{2}) == 0 )<< "\n";
    std::cout << "((int{2} <=> int{1}) > 0) : " << ((int{2} <=> int{1}) > 0 )<< "\n";
    std::cout << "((int{1} <=> int{2}) > 0) : " << ((int{1} <=> int{2}) > 0 )<< "\n";

    //illegal!! because you cant compare <=> result with an int
    int zero{0};
    //std::cout << "((int{1} <=> int{2}) > 0) : " << ((int{1} <=> int{2}) > zero )<< "\n";

    //it doesn't seem like you can print the result of <=> directly, whatever type it is
    //does not have << implemented

    //the return type can be
    //      std::strong_ordering (implies absolute equality... if a==b, foo(a) == foo(b). The values are indistinguishable)
    //          https://en.cppreference.com/w/cpp/utility/compare/strong_ordering
    //                 ^type has 4 vals : less, greater, equivalent, and equal
    //
    //      std::weak_ordering (equivalent values but not absolutely equal, think "Hello" vs "HELLO)
    //          https://en.cppreference.com/w/cpp/utility/compare/weak_order
    //                 ^type has 3 vals : less, greater, and equivalent
    //
    //      std::partial_ordering (used to describe comparisons between two un-comparable types)
    //          ie...
    //          double{12.9} < double{std::numeric_limits<double>::quiet_NaN()}
    //      NaN here as a value is not comparable to other values, doing so will always result if false with '==, <, >'
    //                 ^type has 4 vals : less, equivalent, greater, and unordered

    auto result = (10 <=> 20); //the result here is of type strong ordering because ints have built in behavior for absolute quality

    auto result = (10.1 <=> 20); //here the result is partial ordering because double can have values like NaN that are not comparable to normal values of a double

    auto result = ("Hello" <=> "HELLO"); //here the result is also strong ordering, however, later we may see a way to make use of the equivalence of something like this

    //strong_ordering can implicitly convert to weak_ordering, and weak_ordering can implicitly convert to partial_ordering

    //this is a useful operator when implementing overloads >,>=,<,<= for classes

    //usually overloaded as a member function
    //will come back when I have more info on how...

    return 0;
}
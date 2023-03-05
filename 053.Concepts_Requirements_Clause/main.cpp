#include <iostream>

//A deep dive on the requirements clause of concepts

template <typename T>
concept TinyType = requires (T t){
    sizeof(T) <= 4; //  Requires only checks expression syntax!! An object of 8 bytes can still be passed in!
};                  //  As long as the type is a suitable argument for the sizeof call, the type is good!

//However! You can actually add another level of requires so that the expression IS evaluated!
template <typename T>
concept TinyType2 = requires (T t){
    sizeof(T) <= 4; //  Syntax only checked
    requires sizeof(T) <= 4; // This expression WILL evalute! 
                             // If the type passed in is greater than 4 bytes compilation will fail!
};

//we can also have Compound requirements!
template <typename T, typename P>
concept TinyType3 = requires (T a, P b){
    sizeof(T) <= 4; //  Syntax only checked
    requires sizeof(T) <= 4; // This expression WILL evalute! 
                             // If the type passed in is greater than 4 bytes compilation will fail!
    //  checked for syntax
    //  |      noexcept optional arg
    //  |      |        Checks to see that the result of the expression on the left is convertible to int!
    //  V      V        V
    {a + b} noexcept -> std::convertible_to<int>;
};

//using && and || in requires clause!
//we can also have Compound requirements!
template <typename T>
//                This could be swapped out for : (std::integral<T> || std::floating_point<T>) if you wanted to allow both integrals and precision nums
//                V
requires std::integral<T> && requires (T t) {
                                                sizeof(T) <= 4;
                                                requires sizeof(T) <=4;
                                            }
T func (T t){
    std::cout << "value : " << t << std::endl;
    return (2*t);
};

//concept implementing the logic above for func^ This could be included in the requires line instead of how it is currently set up
//requires funcConcept<T>
template <typename T>
concept funcConcept = std::integral<T> && requires (T t) {
                                                sizeof(T) <= 4;
                                                requires sizeof(T) <=4;
                                            };



int main(int argc, char **argv){

    return 0;
}
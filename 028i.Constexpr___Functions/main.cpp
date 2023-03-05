#include <iostream>

constexpr int getValue(int multiplier);
consteval int getValueConsteval(int multiplier);

int main(){

    //Constexpr functions, functions with the potential to be evaluated at compile time!

    int val1 {getValue(4)}; // get value is a constexpr method, but since val1 is not also constexpr
                            // and val1 is created and initialized during runtime (aka runtime variable),
                            // it WILL NOT be evaluated at compile time! What we get after compilation is 'int val1 = 12;'
    constexpr int val2 {getValue(5)}; //this statement IS EVALUATED AT COMPILE TIME thanks to constexpr declaration of val2

    //consteval functions, essentially they are constexpr but will fail compilation in the event they are not executed at compile time
    int a{6};
    int val3 {getValue(a)}; //constexpr can be used with input not ready at compile time
    //Ilegal!!!
    //int val4 {getValueConsteval(a)}; //a is evaluated at runtime and as such can not be used at input for the consteval function
    //However, if we were to put a const infront, the compiler will see that and determine that it can and will be evaluated during compilation and this would succeed
    //ie.....
    const int b{6}; //this const relies on no runntime variables (only a const literal) so it works as input for consteval func
                    //if this was 'const int b{a};' it could not be evaluated at compile time and as such would be unsuitable input for consteval func
    int val4 {getValueConsteval(b)}; //Valid!

    return 0;
}

constexpr int getValue(int multiplier)
{
    return 3 * multiplier;
}

consteval int getValueConsteval(int multiplier)
{
    return 3 * multiplier;
}
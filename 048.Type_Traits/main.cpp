#include <iostream>

//stop templates from being used with types you dont want!
template <typename T>
void printNumber(T number){
    static_assert(std::is_integral<T>::value, "Must pass in an integral argument!"); //This will kill compilation on condition, dropping the message into build failure!
    //the same call but without having to specify value, using a slightly different call
    //std::is_integral_v<T>
    std::cout << "n : " << number << std::endl;
} //this situation doesnt really call for it, but I could understand blocking fractional numbers for some uses!


int main(int argc, char **argv){

    //TYPE TRAITS, using standard library to find what type a function may return
    //             in <type_traits> header. Check in cpp reference...there are hundreds!

    int a {45};
    std::cout << std::boolalpha; //                        VVV          Targert of query
    std::cout << "is_integral<int>::value : " << std::is_integral<int>::value << std::endl;
    std::cout << "is_integral_v<int> : " << std::is_integral_v<int> << std::endl;
    std::cout << "is_integral<double>::value :" << std::is_integral<double>::value << std::endl;
    //providing a variable alone will give you a compile error, wrap in decltype()
    std::cout << "is_integral<decltype(a)>::value : " << std::is_integral<decltype(a)>::value << std::endl;
    //is_floating_point is one too, check cpp reference for more

    //using this to prevent calls to templates with wrong types!
    //printNumber(99.99); //This will trigger the static_assert condition we set up!

    //this will pass!
    printNumber(15);

    return 0;
}
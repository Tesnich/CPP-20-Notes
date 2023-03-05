#include <iostream>
#include <iomanip>

void compute(int age = 34, double weight = 70.5, double distance = 4); //These "=" signs denote the default parameters

int main(){

    //calling function with pre-defined default arguments
    compute();
    //calling with different levels of inputs
    compute(99);
    compute(99, 11);
    compute(99, 11, 1);
    // NOTE: There is no way to pass an argument to a later parameter and still use the defaults from earlier ones
    // C++ will assume you are tring to pass an argument to the first parameter expecting some sort of implicit conversion

    return 0;
}

void compute(int age, double weight, double distance) //default arguments can't be defined in a function's definition, only at the declaration
{
    std::cout << "Age : " << age << std::endl;
    std::cout << "Weight : " << weight << std::endl;
    std::cout << "Distance : " << distance << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

}
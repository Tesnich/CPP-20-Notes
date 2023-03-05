#include <iostream>

//  return_type  function_name (parameter list)
//  {
//      Do stuff....
//
//      return return_type;
//  }

bool EnterBar(unsigned int age) //age is called a parameter here, you may have any number of input parameters for a function
{
    return (age >= 21) ? true : false;
}

int Maximum(int a, int b)
{
    return (a>b) ? a : b;
}

void SayHello()
{
    std::cout << "Hello there!" << std::endl;
    return; //you can omit this for void return type functions
}

double IncrementMultiply(double a, double b) //copies of values passed to method
{
    std::cout << "Inside function IncrementMultiply ... " << std::endl;
    std::cout << "a : " << a << "\nb : " << b << std::endl;
    double result = ((++a) * (++b)); //this is a change to the local versions of a and b, only for this scope
    std::cout << "Inside function IncrementMultiply, after increment ... " << std::endl;
    std::cout << "a : " << a << "\nb : " << b << std::endl;
    std::cout << "Function IncrementMultiply, finished ... " << std::endl;
    return result;
}

int main(){

    //Functions! (Finaly)
    //Re-usable code!

    unsigned int age {27};
    std::cout << "EnterBar(27) : " << EnterBar(age) << std::endl; //age is called an argument of the EnterBar method here

    int age2 {17};
    std::cout << "EnterBar(17) : " << EnterBar(age2) << std::endl;

    std::cout << "The max between " << age << " and " << age2 << " is " << Maximum(age,age2) << std::endl;

    SayHello();

    std::cout << "IncrementMultiply(age,age2) : " << IncrementMultiply(age,age2) << std::endl; // age and age2 remain unchanged

    return 0;
}
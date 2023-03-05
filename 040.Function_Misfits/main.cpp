#include <iostream>

int globalVariable1{30}; //static variable that survives for the lifetime of the function

void studentFunction();
inline int max(int a, int b);
int fib(unsigned int n);


int main(int argc, char **argv){

    //Function misfits - miscellaneous items
    //static variables, inline functions, and recursive functions

    //Static Variables
    //check out 'globalVariable1'
    std::cout << "The value of the global static variable globalVariable1 is : " << globalVariable1 << std::endl;

    //check out 'studentFunctionRuns'
    for(size_t i{0}; i < 4; ++i)
        studentFunction();

    //Inline functions - method to suggest to the compiler to avoid overhead on loading functions in memory
    //place entire function in TU (translation unit) where it is called so that it doesnt have to be loaded from another location
    std::cout << max(10, 20) << std::endl; //look at function definition for 'inline' keyword
    //best for use on small, frequently used functions (max() would be great here in a large loop)

    //recursion... you know this

    //check out the function fib
    for(size_t i{0}; i < 10; ++i)
    {
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}

void studentFunction()
{
    //there are also static typed variables that can be defined within functions with the 'static' keyword
    static unsigned int studentFunctionRuns{0}; //scope of studentFunctionRuns is limited to studentFunction()
                                       //however, it survives the entire lifetime of the program
    ++studentFunctionRuns;
    ++globalVariable1;
    //this right here is a good way to count the number of times a function is run!
    std::cout << "studentFunction has run " << studentFunctionRuns << " times" << std::endl;
}

inline int max(int a, int b) //inline keyword basically means that this function is loaded in memory to where the call is
{                            //during compilation. This is a SUGESSTION to the compiler. No gaurantee.
    return (a>b)? a : b;     //KEEP IN MIND: If successful, the binary created on compilation will larger because
}                            //              the code for the function is literally copy and pasted everywhere!!

int fib(unsigned int n)
{
    if(n > 1)
        return fib(n-1) + fib(n-2);
    return (n)? 1 : 0;
}
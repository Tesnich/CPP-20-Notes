#include <iostream>
#include <string_view>
#include <iomanip>

//using function parameters to get data out of a function
void maxStr(std::string_view input1, std::string_view input2, std::string& output); //pretty basic pass by ref
void maxInt(const int& input1, const int& input2, int& output); //pretty basic pass by ref
void maxDouble(const double& input1, const double& input2, double* output); //pointer to double used

//using return by value to get data out of a function
int sum(const int& input1, const int& input2);
//using return by value that the compiler makes return by ref
std::string addStrings(std::string_view input1, std::string_view input2);

//explicit return by reference
// V
int& maxIntReturnByReference(int& input1, int& input2); //look at function defition for full explination!
// ^

//testing things....
int& maxIntReturnByReference2(int input1, int input2); //look at func def (the func def is bad, not declaration, why it lets you do this... god knows)
int maxIntReturnByValue(int& input1, int& input2);

//return by pointer
int* maxReturnByPointer(int* a, int* b);

int main(int argc, char **argv){

    //getting data out of a function using function parameters

    std::string stringOutput{};
    maxStr("Pizza", "Burger", stringOutput);
    std::cout << "The output of maxString is :" << stringOutput << std::endl;

    int intOutput{};
    maxInt(10, 99, intOutput);
    std::cout << "The output of maxInt is :" << intOutput << std::endl;

    double doubleOutput;
    double * pointerToDoubleOutput{&doubleOutput};
    maxDouble(7.9, 7.2, pointerToDoubleOutput);
    std::cout << "The output of maxInt is :" << doubleOutput << std::endl;

    //using return by value to get data out of a function

    std::cout << "sum(3,7) : " << sum(3,7) << std::endl;

    //something to note: the compiler will sometimes improve your function to use references when it thinks it can improve performance
    //watch the addresses for the main and function local scope for the std::strings...
    std::string stringInMain = addStrings("Hello ", "Friends!");
    std::cout << "Adress in memory of stringInMain : " << &stringInMain << std::endl;
    //reading the code you would expect two distinct strings, however, THE ADDRESS IS SHARED
    //^^^^^ Just neat little behavior! People are smart :)

    //return by reference, look in function definition for explanation
    int intValueA{20};
    std::cout << "Address of intValueA : " << &intValueA << " value : " << intValueA <<std::endl;
    int intValueB{40};
    std::cout << "Address of intValueB : " << &intValueB << " value : " << intValueB << std::endl;
    int resultInt = maxIntReturnByReference(intValueA, intValueB);
    std::cout << "Address of resultInt : " << &resultInt << " value : " << resultInt << std::endl;
    std::cout << ">> Change intValueB +10 <<" << std::endl;
    intValueB +=10;
    std::cout << "Address of intValueB : " << &intValueB << " value : " << intValueB << std::endl;
    std::cout << "Address of resultInt : " << &resultInt << " value : " << resultInt << std::endl;
    //ok I really am missing the point here....
    //uh....
    //wait....
    //I think I got it...
    //So really what I want to take advantage of this is to ASSIGN it to a reference to int. Take 2!
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    int intValueC{20};
    std::cout << "Address of intValueC : " << &intValueC << " value : " << intValueC <<std::endl;
    int intValueD{40};
    std::cout << "Address of intValueD : " << &intValueD << " value : " << intValueD << std::endl;
    //important bit!
    int& resultInt2 = maxIntReturnByReference(intValueC, intValueD);
    std::cout << "Address of resultInt2 : " << &resultInt2 << " value : " << resultInt2 << std::endl;
    std::cout << ">> Change intValueD +10 <<" << std::endl;
    intValueD +=10;
    std::cout << "Address of intValueD : " << &intValueD << " value : " << intValueD << std::endl;
    std::cout << "Address of resultInt2 : " << &resultInt2 << " value : " << resultInt2 << std::endl;

    //ok so I think that straigtens things out a bit... except what would happen if I tried to assign to an int&
    //from a method that didn't return an int&...oh god I have to go to copy paste city again dont i...
    //nah, thats too much work...
    //uggggggghhhhhhhh...FOR SCIENCE

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    int intValueE{20};
    std::cout << "Address of intValueE : " << &intValueE << " value : " << intValueE <<std::endl;
    int intValueF{40};
    std::cout << "Address of intValueF : " << &intValueF << " value : " << intValueF << std::endl;
    //important bit!
    //ILEGAL...IT WONT EVEN LET YOU DO THIS!
    //int& resultInt3 = maxIntReturnByValue(intValueE, intValueF);
    
    //in conclusion... 1.) the variable you assign to the output of a return by ref can be either and int (the &int returned is copied) or int& reference (the &int assigned references whatever what was returned was referencing)
    //                 2.) the variable you assign to the output of a return by val can be an int (copy) only
    //                 I mean this is how ref and non ref variables work, why am I surprised?
    
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //return by pointer
    int intValueG{11}, intValueH{66};
    int * resultPointer {maxReturnByPointer(&intValueG, &intValueH)}; //similar stuff to what we saw with references
    std::cout << "Address of intValueG : " << &intValueG << " value : " << intValueG <<std::endl;
    std::cout << "Address of intValueH : " << &intValueH << " value : " << intValueH << std::endl;
    std::cout << "Address of resultPointer : " << resultPointer << " value : " << *resultPointer << std::endl;
    std::cout << ">> Change intValueH +10 <<" << std::endl;
    intValueH += 10;
    std::cout << "Address of intValueH : " << &intValueH << " value : " << intValueH << std::endl;
    std::cout << "Address of resultPointer : " << resultPointer << " value : " << *resultPointer << std::endl;

    //looks complex, but all this is really just a thin layer ontop of a bunch of the basics we've learned

    return 0;
}

void maxStr(std::string_view input1, std::string_view input2, std::string& output)
{
    //modifying the output here will std::string input argument because it is passed by ref
    output = (input1 > input2)? input1 : input2;
}

void maxInt(const int& input1, const int& input2, int& output)
{
    //modifying the output here will std::string input argument because it is passed by ref
    output = (input1 > input2)? input1 : input2;
}

void maxDouble(const double& input1, const double& input2, double* output)
{
    //dereferencing and using the assignment opperator here will modify data that output points to
    *output = (input1 > input2)? input1 : input2;
}

int sum(const int& input1, const int& input2)
{
    return input1 + input2;
}

std::string addStrings(std::string_view input1, std::string_view input2)
{
    std::string stringInAddStrings {input1};
    stringInAddStrings += input2;
    std::cout << "Adress in memory of stringInAddStrings : " << &stringInAddStrings << std::endl;
    return stringInAddStrings;
}

int& maxIntReturnByReference(int& input1, int& input2)
{
    //the idea here isnt that you return to the variable you assign this to using the caller

    //the idea is that you are actually RETURNING A REFERENCE to another variable
    return (input1 > input2)? input1 : input2;
    //^^^^^^^^^^^^ the above would fail if the input arguments were (const int& input1, const int& input2)
    //             because you can't assign a reference to something that is cosnt
    //             so really what we are returning here are references to input1 and input2, which are really just
    //             references to whatever input1 and input2 are in main
    //             (I wonder if this would build if input1 and input2 were by value, since their ref would survive end of scope)
}

int& maxIntReturnByReference2(int input1, int input2)
{
    return (input1 > input2)? input1 : input2; //this is allowed? whyyyyyy? What do we return???
    //OK, compilation produces warnings that this points to stack memory...
    //that would seem to indicate that returning by reference is a clever way to use new and heap memory without pointers
    //...I wonder why this is just a warning and not a full on compilation error though. It's pretty easy to know that at the end
    //   of scope the values to which this the return ref will be to will be dead?
}

int maxIntReturnByValue(int& input1, int& input2)
{
    return (input1 > input2)? input1 : input2;
}

int* maxReturnByPointer(int* a, int* b) //pretty straight forward
{
    return (*a > *b)? a : b;
}
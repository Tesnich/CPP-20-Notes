#include <iostream>

//oh my what a lovely processNumber method! wait what does it return? Guess I gotta look inside....
//auto processNumber(int value);

//read comments in main for why declaration is commented out (fyi: full definition of auto return type functions needs to be before it is used)
auto processNumber(int value)  //auto as a return type
{
    if(value < 10)
    {
        return 22; // the compiler now has to deduce the return type based on what is returned
    }              // in this case it is an int based on the literals we feed return
    else
    {
        return 55; // the compiler is smart enough to determine whether returned value types are not the same
    }              // and should throw an error when you try to build the code (ie.. if this was 55.0 indicating a double )
}

//like with other variables we can also make use of & to make output of the function a reference to auto type
auto& refToMaxOfValues(int& val1, int& val2)
{
    return (val1 > val2)? val1: val2; //    returns reference to input arguments used for val1 and val2, with the type autodeduced to that of val1/val2
}   //  again, this is ugly and confusing, declare your types you casual!

int main(int argc, char **argv){

    //auto as a return type? This is absolutely gross
    //I can not fathom why you would want to do this.
    //It is going to make reading your code at a glance way more difficult than it needs to be.

    //this will take the int autodeduced result and convert to double, see how confusing that is if you make an assumption on just the declaration!
    //double processedNum{processNumber(1)};

    //PROBLEM? I originally had a declaration above main and the definition below. 
    //Compiler is yelling at me saying that 
    //"Function 'processNumber' with deduced return type cannot be used before it is defined!

    //so if you are using an auto return type (gross) you need to have the definition before it is used in code
    //****moving definition above and commenting out declaration

    //fyi: linker stage is after compilation stage. Linking declarations to their definition takes place AFTER compiling and the
    //     creation of the translation units (TU). So obviously, if the compiler cant find the definition for an auto return type func
    //     used in a statement because it needs to be linked first, the compiler cant wait for the linker and
    //     thus, build failure!

    std::cout << "processedNum value : " << processNumber(1) << std::endl;

    return 0;
}
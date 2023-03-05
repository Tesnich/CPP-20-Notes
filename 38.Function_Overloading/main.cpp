#include <iostream>
#include <string>
#include <string_view>

//max overloaded with ints, doubles, and strings
int max(int a, int b);
double max(double a, double b);
std::string_view max(std::string_view a, std::string_view b);
//we could also have a max function with int max(int a, double b); and it would be distinct from the above
//the input arguments needs to be different in some way, ie different types, different type order, different number of inputs

//since pointers are typed (ie 'pointer to int' is different than 'pointer to double') they can also be used to overload functions
int max(int * numbers, size_t size);
double max(double * numbers, size_t size);
//the same thing goes for const and pointers (ie 'pointer to const int' is differnt than 'pointer to int'!)
const int* max(const int * numbers, size_t size); //this requires a pointer to an array of CONST integers, distinct from max on line #13!

                                                  //fyi, goes without saying, but making the input argument itself const will not create distinct function signatures
                                                  //ie.. the compiler would see 'int max(int* const numbers, size_t size);' as the same
                                                  //as function declaration as on line #13

                //note! 'int foo(const int& value);' is distinct from 'int foo(int& value);' for the same reason lines 13 and 16 are different

//The above are valid overloads, however, the below would be considered re-definition because
//the input argument 'array' is simply a pointer to int just like 'numbers' above!!

//ILEGAL!!!!!!!!!!
//int max(int array[], size_t);
//int max(int array[10], size_t);

//THERE IS NO SUCH THING AS OVERLOADING BY RETURN TYPE ONLY
//  the calls have to be distinct in their input arguments because the returned value
//  we have seen that func results can be implicitly converted to another just by assignment 
//  if this is the case how would the compiler know which overload to use?

int main(int argc, char **argv){

    //Function overloading, using the same function name with different inputs to distinguish between functions

    int intA{10}, intB{20};

    std::cout << "The max of " << intA << " and " << intB << " : " << max(intA,intB) <<std::endl;

    double doubleA{5.5}, doubleB{9.9};

    std::cout << "The max of " << doubleA << " and " << doubleB << " : " << max(doubleA,doubleB) << std::endl;

    std::string_view svA {"AAAA"}, svB{"BBBB"};

    std::cout << "The max of " << svA << " and " << svB << " : " << max(svA,svB) << std::endl;

    //overloading with pointers

    int intArray[] {1,1,9,1,1};
    double doubleArray[] {0.1,0.1,0.1,99.9,0.1};

    std::cout << "The max of ints is : " << max(intArray, std::size(intArray)) << std::endl;
    std::cout << "The max of doubles is : " << max(doubleArray, std::size(doubleArray)) << std::endl;

    //ambiguous calling

    //Warining:::passing by reference and overloading can cause ambiguity in calls!!!!!!!

    char charA{6}, charB{9};

    //imagine you we changed the first max function 'int max(int a, int b)' to 'int& max(int& a, int& b)'
    //between this new function and our double variant which one would we expect to run 'max(charA, charB);'?

    //the answer is the double! Weird but let me explain,
    //    with an int& we need to reference an non temp int variable
    //    sure the values in charA and charB will convert well implicitly, but temp int variables are created in doing so
    //    since this will fail compilation, the compiler makes the assumption the programmer is looking to implicitly
    //    convert the chars to DOUBLE. (next best thing that works) This is something you need to watch out for when
    //    creating overload functions with references as input arguments!!!!!!!!!

    //to get arount this issue we could explicitly convert charA and charB into new variables that match our input arguments

    int charAAsInt{static_cast<int>(charA)}, charBAsInt{static_cast<int>(charB)};

    //these new values could be passed in!!

    //additionally we re-write our method and arguments to be 'const int& max(const int& a, const int& b);'
    //  adding the const means we will never change it, so the compiler is fine with giving us const references to temporary variables created from implicit conversions
    return 0;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

double max(double a, double b) //max overloaded with doubles
{
    return (a > b)? a : b;
}

std::string_view max(std::string_view a, std::string_view b) //max overloaded with strings
{
    return (a > b)? a : b;
}

int max(int * numbers, size_t size)
{
    int maxNum{numbers[0]};
    for(size_t i{1}; i < size; ++i)
    {
        maxNum = (numbers[i] > maxNum)? numbers[i] : maxNum;
    }
    return maxNum;
}

double max(double * numbers, size_t size)
{
    double maxNum{numbers[0]};
    for(size_t i{1}; i < size; ++i)
    {
        maxNum = (numbers[i] > maxNum)? numbers[i] : maxNum;
    }
    return maxNum;
}

const int* max(const int * numbers, size_t size)
{
    const int* maxNum{numbers};
    for(size_t i{1}; i < size; ++i)
    {
        maxNum = (*(numbers + i) > *maxNum)? numbers + i : maxNum;
    }
    return maxNum;
}
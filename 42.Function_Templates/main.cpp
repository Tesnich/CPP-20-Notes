#include <iostream>
#include <optional>

template <typename T> T maximum(T a, T b);

template <typename T> std::optional<size_t> searchCollection(T* array, size_t arraySize, const T& searchElement);

//template specialization
template <> //empty <> where the 'typename T' would have gone
//                 -------------
const char* maximum<const char*>(const char* a, const char* b); //added <const char*> input arguments
//                 -------------
//if you specialize a template this way you need to add a definition as well to handle it! //look below

int main(int argc, char **argv){

    //Function Templates

    //  These flexible function blueprints are capable of taking in a data type in addition to input arguments
    //  with the idea of performing the same opperations on the data regardless of type

    //  Instead of writing a function to find the max of two ints and another to find the max of two doubles,
    //  we can write one template to work for both!

    /* Formatting 

            template <typename T> T maximum(T a, T b){
                return (a > b) ? a : b;
            }

    */

    int intA{1}, intB{9};
    double doubleA{0.1}, doubleB{0.9};

    //you call the template function just like any other, providing the int and double input arguments a and b

    std::cout << "The maximum of the ints " << intA << " and " << intB << " is : " << maximum(intA, intB) << std::endl;
    //^^^^ Behind the scenes the compiler is actually creating overloads for us in the translation units
    //     If you could see after compilation, this line creates forces the compiler to make an int version of maximum
    //     ie. 'int maximum(int a, int b){...}'

    std::cout << "The maximum of the doubles " << doubleA << " and " << doubleB << " is : " << maximum(doubleA, doubleB) << std::endl;
    //^^^^ When it sees another call to the template function that doesnt match an overload already created, it makes another
    //     ie. 'double maximum(double a, double b){...}'

    // Imagining the program was complete at this point, the TU would only contain two overloaded function definitions.
    // There is no 'WILD CARD' template that can be called during runtime.

    // The template blueprint will successfully create a function if the opperations in the resulting definition
    // are possible on the data types passed in. ie... trying to multiply string would cause the compilation to fail

    //EXPLICIT TEMPLATE ARGUMENTS
    /////////////////////////////

    //say we end up in a situation where we want to pass a double and an int into a template but want the int to be
    //  converted into a double? If we just pass the int and the double, the compile will have no way to handle the 
    //  descrepancy in types and compilation will fail. HOWEVER, we can add a tag to the call to force it to adopt
    //  a type as T.
    //                                                                                                 --------
    std::cout << "The maximum between int " << intA << " and double " << doubleB << " is : " << maximum<double>(intA, doubleB) << std::endl;
    //                                                                                                 --------
    //  as long as the passed in type can be converted to the explicit type given, compilation should pass!
    //  NOTE!! The maximum will return a double here, even if int is greater, since the typename T type was
    //      specified as the return type!

    //  when you do not specify the type on the call to the template, the act of the compiler deducing the right type
    //  is refered to as "template type deduction"

    //  if you would like to see the TUs that the compiler generates check out the website below
    //  cppinsight.io 

    //template for searching through any kind of array type for a match

    int intArray[] = {0,1,2,3,99,5,6}, intSearchVal{99};
    double doubleArray[] = {0.1,0.2,0.3,0.4,0.5,99.9}, doubleSearchVal{99.9};

    std::optional<size_t> result = searchCollection(intArray, std::size(intArray), intSearchVal);
    if(result.has_value())
        std::cout << "The int value " << intSearchVal << " is located at index : " << result.value() << std::endl;

    result = searchCollection(doubleArray, std::size(doubleArray), doubleSearchVal);
    if(result.has_value())
        std::cout << "The double value " << doubleSearchVal << " is located at index : " << result.value() << std::endl;

    //Template Specialization - a little fuzzy on the example given below but bear with me

    //Template specialization is a method for us to pre-declare and implement unique definitions for a template function blueprint

    //imagine you have the bellow
    std::string stringA{"University"}, stringB{"High School"};

    std::cout << "The maximum between " << stringA << " and " << stringB <<" is : " <<maximum(stringA, stringB) << std::endl;
    //the above line provides strings to the templates, and as such a definition for std::strings is created,
    //  and the > opperator works properly and we get the lexigraphical greater string

    //however, if we pass in the below with the idea of comparing c strings we will have an issue...
    const char* charA{"BBBB"}, *charB{"AAAA"};

    std::cout << "The maximum between " << charA << " and " << charB <<" is : " <<maximum(charA, charB) << std::endl;
    //The compiler would see this as const char* and create a definition with it and the standard functionality.
    //Unfortunately that compares pointers, not alphabetical order of strings! To avoid this we can implement
    //a manual version of the template with slightly differnt functionality. refer to declaration and definition to continue...
    //  ie. template<>

    //without : answer is AAAA
    //with custom definition : answer is BBBB

    return 0;
}

template <typename T> T maximum(T a, T b) // technically this is not a function, not real c++ code, just a blueprint for functions!
{                                         // the real functions are made during compilation
    return (a > b)? a : b;
}

//any of these Ts can be swapped out as needed with actual type names

//check out the below template to find the index of a search element of any type of array!

template <typename T> std::optional<size_t> searchCollection(T* array, size_t arraySize, const T& searchElement)
{//              ^^^^^^it goes without saying that you can pass pointers or references to T as input arguments
    for(size_t i{0}; i < arraySize; ++i)
        if(array[i] == searchElement) return i;
    return {std::nullopt}; 
}

//template specialized version for const char* of maximum above!
template<>
const char* maximum<const char*> (const char*a, const char* b)
{
    return (std::strcmp(a,b) > 0) ? a : b; // now instead of comparing pointer locations we can use std::strcmp
}//                                           for a lexigraphical comparison 

//I messaged kevin on dec 14th around 3pm to talk about why youd do this over just overloading, good thoughts passed around
//look at that convo if you forget


//Ok some interesting learing...

//I havent been doing this but the lectures have talked about it. The template definition should really be one with
//the declaration. Meaning, dont declare it, just define it. And put that definition in the header. 

//A template definition IS NOT real c++ code. So when header it is in is included it isnt going to be copied all over
//creation.

//A template specialization, on the other hand, IS REAL C++ CODE. Despite the same syntax misleading you, you DONT
//want to put a template specialization in a header file. This will copy it where it is included and could cause
//re-definition issues.

//  MAIN POINT : Put template specialization code in cpp files. Keep main template definition in header.
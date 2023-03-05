#include <iostream>
#include <string>
#include <optional>
#include <iomanip>

int findCharInString(char* stringArray, char searchChar, int& index); //stringArray and searchChar are inputs, index is output 

std::optional<int> findCharInString2(char* stringArray, char searchChar); //implementation of findCharInString but with std::optional return type

std::optional<int> findCharInString2WithDefault(char* stringArray, std::optional<char> searchChar = std::nullopt); // truely some modern c++ code (why do this instead of just what the default case is?)
                                                                                                                   // my guess, imagine there is a valid input for searchChar from 0 - 265 (all values)
                                                                                                                   // in the event that no value is given we may need to process data differently...
                                                                                                                   // if all values are valid our default value will give us no clue that the user didnt supply it!
                                                                                                                   // VERY INTERESTING! Obviously doesnt apply to this case I wrote though.

int main(int argc, char **argv){

    //Optional output from functions, refering to using the return type as an int to indicate success or failure

    //char * inputString {"012345X789"}; //compiler is saying this isnt legal in c++ 11, I know I've done this before without warning...
                                         //I was being silly, i need to create a cstring ARRAY with the following syntax
    char inputString[] {"012345X789"};   //this way you can even use size
    int index{0};

    if(findCharInString(inputString, 'X', index)) //anything that isnt 0 will flag as true, negative or postive
    {
        //function failure case
        std::cout << "Abort, could not find the X char in string!" << std::endl;
        //return -1; //failure for main...
    }

    std::cout << "The X character was found at index : " << index << std::endl;

    if(findCharInString(inputString, 'Y', index)) //anything that isnt 0 will flag as true, negative or postive
    {
        //function failure case
        std::cout << "Abort, could not find the Y char in string!" << std::endl;
        //return -1; //failure for main...
    }

    std::cout << "The Y character was found at index : " << index << std::endl;

    //there are also other ways to get this success data, ie.. using a pointer or reference to success flag (bool or error code with some explanitory value)
    
    std::cout << std::setw(50) << std::setfill('-') << "std::optional" << std::setfill(' ') << std::endl;

    //INCLUDING... A NEW C++ 17 concept! std::optional! REQUIRES #include <optional>
    //std::optional is basically a template where you have a wrapper around a type ... with a custom null case

    std::optional<int> items{3};
    std::optional<std::string> name{"James"};
    std::optional<double> second {33.4};
    //these dont need to be filled, they can be empty
    std::optional<std::string> dogName{};  //Initializes to std::nullopt
    std::optional<int> age {std::nullopt}; //manual declaration of std::nullopt, std::nullopt is the null or zero equivalent for std::optional

    //viewing the values inside!
    std::cout << "items : " << items.value() << std::endl;
    std::cout << "items : " << *items << std::endl; //  '*' here will also give you the same thing as
                                                    //  .value(), but its incredibly strange...
                                                    //  since 'items' is not a pointer and dereferencing it has no meaning
                                                    //  We shouldnt use this syntax because it will lead
                                                    //  anyone reading your code to believe it is a pointer.

    age = 27; //you can assign these std::optional types just like it was any other variable

    //WARNING!!!!!!!!!!! if you try to use .value() when it is set to std::nullopt, IT WILL THROW AN EXCEPTION! check first!
    if(age.has_value()) //.has_value() is true if optional type not set to std::nullopt
        std::cout << "Age is : " << age.value() << std::endl;
    //or check like ...
    if(age != std::nullopt)
        std::cout << "Age is : " << age.value() << std::endl;

    //now for use in optional output... 
    //look at findCharInString2()

    char inputString2[] {"012345X789"};
    std::optional<int> resultOpt = findCharInString2(inputString2, 'X');
    if(resultOpt.has_value())
    {
        std::cout << "resultOpt.has_value() is true! value is " << resultOpt.value() << std::endl;
    }
    else
    {
        std::cout << "resultOpt.has_value() is false! No value to report! " << std::endl;
    }

    //also give a look at the fancy way you can set default values for input arguments using std::optional in 
    //  findCharInString2WithDefault()

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    std::optional<int> resultOpt2 = findCharInString2WithDefault(inputString2);
    if(resultOpt2.has_value())
    {
        std::cout << "resultOpt2.has_value() is true! value is " << resultOpt2.value() << std::endl;
    }
    else
    {
        std::cout << "resultOpt2.has_value() is false! No value to report! " << std::endl;
    }

    return 0; //success for main
}

int findCharInString(char* stringArray, char searchChar, int& index)
{
    for(size_t i{0}; i < std::strlen(stringArray); ++i)
    {
        if (*(stringArray+i) == searchChar)
        {
            index = i;
            return 0; // successful run, no problems
        }
    }
    return -1; // there was a problem, index cannot be accurately used for further processing
}

std::optional<int> findCharInString2(char* stringArray, char searchChar)
{
    for(size_t i{0}; i < std::strlen(stringArray); ++i)
    {
        if (*(stringArray+i) == searchChar)
        {
            return i; // successful run, no problems
        }
    }
    return {std::nullopt}; // there was a problem, index cannot be accurately used for further processing
    //return {};     //this will do the same thing as std::nullopt
}

std::optional<int> findCharInString2WithDefault(char* stringArray, std::optional<char> searchChar)
{
    //char characterToFind = (searchChar.has_value())? searchChar.value() : 'X'; //if that searchChar value has no option provided its default is set to nullopt!
    
    //  2*) the above works but there is another cool std::optional trick!
    char characterToFind = searchChar.value_or('X');
    //  2*) shorterhand version of the ternary I wrote above!
    //  2*) in addition you can always modify functionality for cases where user does not supply value 
    //  2*) by performaing a conditional with (!searchChar.has_value()), wow niche case, but very fancy when it turns up

    for(size_t i{0}; i < std::strlen(stringArray); ++i)
    {
        if (*(stringArray+i) == characterToFind)
        {
            return i; // successful run, no problems
        }
    }
    return {std::nullopt}; // there was a problem, index cannot be accurately used for further processing
    //return {};     //this will do the same thing as std::nullopt
}
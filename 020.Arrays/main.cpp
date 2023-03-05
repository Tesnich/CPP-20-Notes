#include <iostream>
#include <iomanip>

//Arrays, a way to group values of the same type

int main(){
    
    int scores[10]; //creates an array of 10 ints, garbage data initialized

    //accessing a particular element in an array

    std::cout << "scores[0]" << scores[0] << std::endl; //under my compiler this was showing up with garbage but now its a 0? weird programming is weird

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    for(unsigned int i{0}; i < 10; ++i)
    {
        scores[i] = i*10;
        std::cout << "scores[" << i << "] = " << scores[i] << std::endl;
    }

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    double salaries[5] {12.7, 7.5, 13.2, 8.1, 9.3}; //braced initialization

    for(unsigned int i{0}; i < 5; ++i)
        std::cout << "salaries[" << i << "] = " << salaries[i] << std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    int scores2[10] {33, 44, 55}; // values not supplied will be default initalized

    for(unsigned int i{0}; i < 10; ++i)
        std::cout << "scores2[" << i << "] = " << scores2[i] << std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //range based for loop to display values (no iterator though!)
    for (auto value : scores2)
        std::cout << "range value = " << value << std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    unsigned int arrayOfValues[] {12, 13, 14}; //if no value is supplied for array initialization size compiler will deduce from the number of values supplied

    // arrays can also be made const!

    //below causes a compiler error
    //unsigned int arrayOfUndeteriminedValues []; 

    const unsigned int arrayOfConstantValues[] {12,13,14};

    //below causes an issue!
    //arrayOfConstantValues[0] = 10;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    //determining the size of an array at run time using C++ 17!
    std::cout << "The C++ 17 size(scores) is : " << std::size(scores) << std::endl;

    for(unsigned int i{0}; i < std::size(scores); ++i)
        std::cout << "scores[" << i << "] = " << scores[i] << std::endl;

    //old way of determining size of an array! Pre c++ 17
    //get the bytes size of the array then divide by the bite size of an element in the array
    
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    std::cout << "The PRE C++ 17 method of (sizeof(scores)/ sizeof(scores[0])) is : " << sizeof(scores)/sizeof(scores[0]) << std::endl;
    
    for(unsigned int i{0}; i < sizeof(scores)/sizeof(scores[0]); ++i)
        std::cout << "scores[" << i << "] = " << scores[i] << std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    //char arrays
    char message[5] {'H','E','L','L','O'}; // This is somewhat dangerous because c++ may not know when to stop reading (missing the '\0' termination character)
    char message2[6] {'H','E','L','L','O'}; // This will actually default initialize the final spot in the array as a '\0' termination character
    char message3[] {'H','E','L','L','O'}; // same issue as with message, [] auto deduces the statement to size 5, no termination character
    //char message[] {'H','E','L','L','O','\0'}; 

    std::cout << "message  : " << message << std::endl;
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "message3 : " << message3 << std::endl;

    std::cout << "Loop Print of Char Array :";
    for(char letter : message) std::cout << letter << "-"; //Since we are going by size of array null terminator is not needed to get the data we expect
    std::cout << std::endl;

    char message4[] {"Using a string literal format to populate char array!"}; // This will supply '\0' for us
    std::cout << "message4 : " << message4 << std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    //Generating Random NUmbers

    int randomNum = std::rand(); // generates a number between 0 and RAND_MAX
    std::cout << "randomNum is : " << randomNum << std::endl;
    std::cout << "RAND_MAX is : " << RAND_MAX << std::endl;

    //to get a number within a certain range make use of the modulus functionality!
    //AKA if you want a number between 1 and 10, randomNum % 11 gives you the remainder of anything that isnt divisible by 11. so, 0 to 10

    int randomNum0To100 = std::rand() % 101;
    std::cout << "randomNum0To100 is : " << randomNum0To100 << std::endl;

    for(size_t i{0}; i < 11; ++i) std::cout << "0 - 100 : " << std::rand() % 101 << std::endl;
    //random numbers with a lower bound? add to the result
    //between 90 and 100
    for(size_t i{0}; i < 11; ++i) std::cout << "90 - 100 : " << (std::rand()% 11) + 90<< std::endl;

    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    //std::time(0) // time since Jan 1st, 1970 at 0 AM                                -  ^
    //below needs #include <ctime>? mine seems to run just fine without it          (- )(- )
    //                                                                                   o
    std::srand(std::time(0)); //Change Seed to get different live random numbers based on when the program is run 
    for(size_t i{0}; i < 11; ++i) std::cout << "90 - 100 : " << (std::rand()% 11) + 90<< std::endl;


}
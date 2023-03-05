#include <iostream>
#include <string>

//arguments to the main function!!

//       ---------------------
int main(int argc, char **argv)
//       ---------------------
{
    //argc is the number of parameters that are passed to the program
    std::cout << std::endl << "We have " << argc << " arguments passed to the main function!" << std::endl;

    //argv, is a pointer to a pointer to a char (in other words a pointer to a bunch of c-style char arrays!)
    for(size_t i{0}; i < argc; ++i)
    {
        std::cout << std::string(i*3,' ') << argv[i] << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}
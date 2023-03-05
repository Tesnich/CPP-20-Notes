#include <iostream>

int main(int argc, char **argv){

    //calculator using input arguments as parameters
    if(argc < 4){
        std::cout << "Calculator requires 3 input arguments: ValueA, opperand char, and ValueB\a" << std::endl;
        return 1;
    }

    double valueA{std::stod(argv[1])}, valueB{std::stod(argv[3])}, result{};
    //double valueA{std::atof(argv[1])}, valueB{std::atof(argv[3])}, result{};
    //it looks like the approach I used here may not fit all needs, the instructor used std::atof
    //at first this appears to return a float (based on naming convention) but actually this returns a double

    //there are a few differences...
    //  1.) atof takes char* while stod takes a string
    //  2.) stod will also return an index of the first unconverted character if the pos parameter is not null
    //      (Think, further parsing of string in some unique use cases)
    //  3.) if value falls out of bounds of double atof returns an undefined value (yikes), stod throws exception
    //  4.) if no conversion can be performed atof returns 0.0, stod throws exception

    //Looking at this, stod is newer more modern fail safe of the two

    char opperand {};

    char * argv2Pointer{argv[2]}; //get the pointer to the c-string array in that is argument 2

    if(std::strlen(argv2Pointer) == 1) opperand = * argv2Pointer; //if the string is one char assign it to opperand for checking

    //for debugging 
    //std::cout << valueA << opperand << valueB << std::endl;

    switch(opperand)
    {
        case '+':
            result = valueA + valueB;
            break;              
        case '-':
            result = valueA - valueB;
            break;
        case 'x':
            result = valueA * valueB;
            break;
        case '/':
            result = valueA / valueB;
            break;
        default:
            std::cout << "Calculator only accepts +,-,x, and / as opperands. \a" <<std::endl;
            return 1;
    }

    std::cout << result << std::endl;

    return 0;
}
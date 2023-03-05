#include <iostream>
//#include <string>
//Is the above not needed?

/*
    std::cout -> print data from program to terminal
    std::cin -> read data from terminal to program
    std::cerr 
    std::clog
*/
int main(){
    int age {27};
    std::string fullName;
    std::cout << "The age is :" << age << std::endl;
    std::cerr << "Oh no, a problem!"<< std::endl;
    std::cout << "Please give your name :";
    //std::cin >> name;
    //The above would only grab the first name if seperated by spaces
    //The below can grab the whole line, OK!
    std::getline(std::cin,fullName);
    std::clog << fullName << " caused an error!" << std::endl;
    return 0;
}
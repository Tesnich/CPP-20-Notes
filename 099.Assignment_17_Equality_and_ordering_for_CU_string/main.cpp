#include <iostream>
#include "string.h"

int main(int argc, char **argv){
        CU::string a("Hello");
        CU::string b("World");
     
        std::cout << std::boolalpha;
        std::cout << std::endl;
        std::cout << "a > b : " << (a > b) << std::endl;
        std::cout << "a > b : " << (a > "World") << std::endl; // Implicit conversion from left
        std::cout << "a > b : " << ("Hello" > b) << std::endl; // Implicit conversion from right
     
        std::cout << std::endl;
        std::cout << "a < b : " << (a < b) << std::endl;
        std::cout << "a < b : " << (a < "World") << std::endl; // Implicit conversion from left
        std::cout << "a < b : " << ("Hello" < b) << std::endl; // Implicit conversion from right
     
        std::cout << std::endl;
        std::cout << "a >= b : " << (a >= b) << std::endl;
        std::cout << "a >= b : " << (a >= "World") << std::endl; // Implicit conversion from left
        std::cout << "a >= b : " << ("Hello" >= b) << std::endl; // Implicit conversion from right
     
        std::cout << std::endl;
        std::cout << "a <= b : " << (a <= b) << std::endl;
        std::cout << "a <= b : " << (a <= "World") << std::endl; // Implicit conversion from left
        std::cout << "a <= b : " << ("Hello" <= b) << std::endl; // Implicit conversion from right
     
        std::cout << std::endl;
        std::cout << "a == b : " << (a == b) << std::endl;
        std::cout << "a == b : " << (a == "World") << std::endl; // Implicit conversion from left
        std::cout << "a == b : " << ("Hello" == b) << std::endl; // Implicit conversion from right
     
        std::cout << std::endl;
        std::cout << "a != b : " << (a != b) << std::endl;
        std::cout << "a != b : " << (a != "World") << std::endl; // Implicit conversion from left
        std::cout << "a != b : " << ("Hello" != b) << std::endl; // Implicit conversion from right

    return 0;
}
#include <iostream>

int main(){
    std::cout << "Please enter a number :";
    int number;
    std::cin >> number;
    std::cout << ((number % 2) ? "Odd" : "Even") << std::endl;
    return 0;
}
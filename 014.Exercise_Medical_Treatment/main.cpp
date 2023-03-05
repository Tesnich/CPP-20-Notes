#include <iostream>

int main(){
    std::cout << "Please enter your age :";
    int age;
    std::cin >> age;
    std::cout << "This super experimental treatment ";
    std::cout << ((age >= 21 && age <= 39) ? "is right for you.": "would most likely kill you.") << std::endl;
    return 0;
}
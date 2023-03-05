#include <iostream>
#include <iomanip>

int main(){
    std::cout << "Welcome to box calculator. Please type in length, width, and height information :" << std::endl;
    int length, width, height;
    std::cout << std::left << std::setw(12) << "Length" << ":";
    std::cin >> length;
    std::cout << std::setw(12) << "Width" << ":";
    std::cin >> width;
    std::cout << std::setw(12) << "Height" << ":";
    std::cin >> height;
    std::cout << "The base area is : " << width * length << std::endl;
    std::cout << "The volume is : " << width * length * height << std::endl;

    return 0;
}
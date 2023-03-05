#include <iostream>

const int boxWidth {20};
const int boxHeight {10};

int main(){
    std::cout << "Please enter your x and y seperated by a space : ";
    int x,y;
    std::cin >> x >> y;
    if(abs(x)<boxWidth/2 && abs(y)<boxHeight/2) // You can't be surounded on an edge ;P
    {
        std::cout << "You are completely surrounded. Don't move!" <<std::endl;
    }
    else
    {
        std::cout << "You're out of reach!" << std::endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>

int main(){
    double celsiusValue;
    std::cout << "Please enter a degree value in Celsius : " << std::endl;
    std::cin >> celsiusValue;
    std::cout << celsiusValue << " Celsius is " << 9.0/5 * celsiusValue + 32 << " Fahrenheit" <<std::endl;
    return 0;
}
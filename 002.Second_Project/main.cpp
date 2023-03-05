#include <iostream>

//Errors and Warnings

//simple function
int AddNumbers(int first_number, int second_number)
{
    return first_number + second_number;
}

//simple exercise to create a function that multiplies two numbers
int MultiplyNumbers(int first_number, int second_number)
{
    return first_number * second_number;
}

int main(){
    //compile time error, no semi colon 
    //std::cout<< "Hello World!" << std::endl

    //Run time error, something designed does not have the intended result but may compile fine
    //int value = 7/0;

    //simple statements

    int firstNumber = 12;
    //can also be written as :
    int secondNumber {9};

    int sum = firstNumber + secondNumber;
    int sum2 = AddNumbers(firstNumber, secondNumber);
    std::cout << "The First Number is " << firstNumber << std::endl;
    std::cout << "The Second Number is " << secondNumber << std::endl;
    std::cout << "The Sum is " << sum << std::endl;
    std::cout << "The Sum (Function Version) is " << sum << std::endl;
    std::cout << "The Product (Function) is " << MultiplyNumbers(firstNumber,secondNumber) << std::endl;

    return 0;
}
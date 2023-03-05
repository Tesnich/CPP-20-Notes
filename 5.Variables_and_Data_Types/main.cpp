#include <iostream>
#include <iomanip>

int main(){
    int num1 = 15; //decimal
    int num2 = 017; //octal
    int num3 = 0x0f; //hexadecimal
    int num4 = 0b00001111; //binary - C++14 onwards

    //all numbers output as 15
    std::cout << num1 << " " << num2 << " " << num3 << " " << num4 << std::endl;

    int variableA; //may contain random garbage if compiler has no default initialization standard
    int variableB{}; //Initializes to 0
    int variableC{10}; //Initializing to 10
    int variableD{15};
    int variableCD{variableC + variableD};

    //int narrowing_conversion{2.7}; //Error or warning
    //Functional variable initialization
    int narrowing_conversion(2.7); //Truncated information lost, no alert to user. Might be prudant to initialize ints with {};
    //Assignment initialization
    int pizzasOrdered = 10;

    //Size of a type in memory (number of bytes)
    std::cout <<"sizeof int : " << sizeof(int) << std::endl;
    std::cout <<"sizeof pizzasOrdered : " << sizeof(pizzasOrdered) << std::endl;

    //initializing format
    //typename variableName {initializer_value};

    //Integer Modifiers--------------------------------------------------------------
    std::cout << "Integer Modifiers--------------------------------------------------------------" << std::endl;

    int value1 {10};
    int value2 {-10};

    std::cout << value1 << " " << value2 << std::endl;

    unsigned int value3{5};
    //unsigned int value4{-5}; //creates a compiler error

    //Fractional Numbers--------------------------------------------------------------
    //float, double, and long double

    double doubleNum {1.123456789};
    //control precision 
    std::cout << std::setprecision(5); //#include <iomanip>
    std::cout << "doubleNum is : " << doubleNum <<std::endl;
    //float floatNum {123456789123}; //issue because float cant handle size
    //scientific Notation
    double doubleNum2 {1.92400023e8};
    double doubleNum3 {1.92e-8};
    std::cout << "doubleNum2 " << doubleNum2 << std::endl;
    std::cout << "doubleNum3 " << doubleNum3 << std::endl;

    //characters and text--------------------------------------------------------------
    //ascii
    char letter {'B'};
    std::cout << letter << std::endl;
    letter = 65; // number for A
    std::cout << letter << std::endl;
    std::cout << static_cast<int>(letter) << std::endl; // cast char to its associated number
    //char letter2 {"B"}; //error
    
    //Auto keywork in c++---------------------------------------------------------------
    auto var1 {12}; // guess type and assign int
    auto var2 {13.0}; //deduce double
    auto var3 {14.0f}; //deduce float
    auto var4 {15.0l}; //deduce long
    auto var5 {'e'}; //deduce char
    auto var6 {123u}; //deduce unsigned
    auto var7 {123ul}; //deduce unsigned long
    auto var8 {123ll}; //deduce long long

    std::cout << "var1  has " << sizeof(var1) << " bytes" << std::endl;
    std::cout << "var2  has " << sizeof(var2) << " bytes" << std::endl;
    std::cout << "var3  has " << sizeof(var3) << " bytes" << std::endl;
    std::cout << "var4  has " << sizeof(var4) << " bytes" << std::endl;
    std::cout << "var5  has " << sizeof(var5) << " bytes" << std::endl;
    std::cout << "var6  has " << sizeof(var6) << " bytes" << std::endl;
    std::cout << "var7  has " << sizeof(var7) << " bytes" << std::endl;
    std::cout << "var8  has " << sizeof(var8) << " bytes" << std::endl;

    return 0;
}
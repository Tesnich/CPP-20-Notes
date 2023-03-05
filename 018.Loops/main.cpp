#include <iostream>
#include <iomanip>

//loops!

unsigned int SumUpTo99()
{
    unsigned int sum{};

    for (size_t i{0}; i < 100; ++i) sum += i;

    return sum;
}

void PrintUppercase()
{
    for(unsigned int i{65}; i < 90; ++i)
    {
        std::cout << static_cast<char>(i) << " ";
    }
    std::cout << std::endl;
    return;
}

int main(){
    
    //for ( initialized value; condition; increment value)
    for(unsigned int i{}; i<10; ++i)
    // {} body
    {
        std::cout << i << ". I love C++?" << std::endl;
    }

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //size_t is for iterators and a representation of unsigned int (8 bytes and positive numbers only)
    for(size_t i{}; i<10; ++i)
    {
        std::cout << i << ". I love C++?" << std::endl;
    }

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    std::cout << "The sizeof(size_t) is : " << sizeof(size_t) << std::endl;
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //for loop does not require an initializer for a loop variable
    //if the iterator value is required outside of the loop scope you can declare it before the loop

    size_t loopIterator{}; //Iterator defined outside
    for (; loopIterator < 10; ++loopIterator) // still need to supply semi colon to begining
    {
        std::cout << "The loop Iterator value : " << loopIterator << std::endl;;
    }
    std::cout << "The final value of the loop Iterator value was : " << loopIterator << std::endl;

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //Try not to hardcode values in expressions, makes things difficult to alter later
    const size_t count{10};
    for (size_t loopIterator2; loopIterator2 < count; ++loopIterator2) // still need to supply semi colon to begining
    {
        std::cout << "The loop Iterator 2 value : " << loopIterator2 << std::endl;;
    }

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    std::cout << "Sum to 99 is : " << SumUpTo99() << std::endl;
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    std::cout << std::left;
    //Multiple Declarations in a loop
    for (size_t i{}, x{5}, y{22}; y > 15; ++i, x+=5, y-=1) //Multiple variables declared, multiple value increments/decrements
    //INITIALIZED VARIABLES MUST BE OF THE SAME TYPE
    {
        std::cout << "i :" << std::setw(10) << i << "x :" << std::setw(10) << x << "y :" << std::setw(10) << y << std::endl;
    }
    std::cout << std::right;
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    PrintUppercase();
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //The comma Operator
    //Combines two or more expressions into a single expression,
    // where the value of the operation is the value of its right operand

    int increment {5};
    int number1 {10};
    int number2 {20};
    int number3 {25};
    // in a chain like this seperated by commas, the last expression is what is piped to the assignment of the left side
    int result = (number1 *= ++increment, number2 -= (++increment), number3 += ++increment);
    std ::cout << "number1 : " << number1 << std::endl;
    std ::cout << "number2 : " << number2 << std::endl;
    std ::cout << "number3 : " << number3 << std::endl;
    std ::cout << "result  : " << result << std::endl;

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //range based for loops (int thing : things) or (auto thing : things)
    int bagOfValues [] {1,2,3,4,5,6,7,8,9,10}; //creating a collection ie array
    for (int value : bagOfValues)
    {
        //value holds a copy of the current iteration in the whole bag
        std::cout << "Value " << value << std::endl;
    }

    std::cout << "sizeof(int) : " << sizeof(int) << std::endl;

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //auto type for compiler automatic deduction of type
    for (auto value : {1,2,3,4,5,6,7,8,9,10})
    {
        //value holds a copy of the current iteration in the whole bag
        std::cout << "Value " << value << std::endl;
        if(value == 10)
            std::cout << "sizeof(value) : " << sizeof(value) << std::endl;
    }

    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //While loops!

    const unsigned int limit{10};
    unsigned int whileIterator{0};

    while(whileIterator < limit)
    {
        std::cout << whileIterator << ". I love C++!" <<std::endl;
        ++whileIterator;
    }

    //NOTE!! std::cout is very slow! Including them in loops slows down your programs by factors in the thousands! 
    //If you are looking for speed do not use or lock behind debug token functionality!
        
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    //Do While Loops!
    const unsigned int COUNT{10}; //try to make constants and enums all caps, good naming convention
    unsigned int doWhileIterator {0};

    do
    {
        //runs the body of the loop THEN check condition for subsequent loops
        std::cout << doWhileIterator << ". Do While loop run!" << std::endl;
        ++doWhileIterator;
    } while (doWhileIterator < COUNT);
    
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    //Terminating Infinite Loops

    std::cout << "Never Ending Calculator Program ...." <<std::endl;
    bool end {false};
    char userSelection;
    double valueA, valueB;
    char opperand;

    do
    {
        std::cout << "Value A  :";
        std::cin >> valueA;
        std::cout << "Value B  :";
        std::cin >> valueB;
        std::cout << "Opperand :";
        std::cin >> opperand;

        double result{};
        switch(opperand)
        {
            case '+':
                result = valueA + valueB;
                break;
            case '-':
                result = valueA - valueB;
                break;
            case '*':
                result = valueA * valueB;
                break;
            case '/':
                result = valueA / valueB;
                break;
        }
        std::cout << "Result   :" << result << std::endl << std::endl;

        std::cout << "Continue? (Y/N) :";
        std::cin >> userSelection;
        end = (userSelection == 'N') ? true : false;

    } while (end == false);
    std::cout<< std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

}
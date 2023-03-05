#include <iostream>

enum Direction { //Legacy enums! This is what I was used to at work because of the older code base!
    Up = 1,
    Down,
    Left,
    Right
};

enum Color {
    Red=1,
    Green,
    Blue,
    Yellow
};

void printAngle(Direction heading);

int main(){
    
    //legacy enums!     try to avoid if possible!

    //legacy enums WILL implicitly convert to int
    //      with the legacy style YOU CAN PASS an enum into anything that accepted ints and it will work
    //      ie... cout, comparisons with other enums, etc...
    //      using this style of enums is not recommended though, as the enum class added in newer versions of c++
    //      allows for safer program flow, restricting programmers from passing it into something that accepts int
    //      without fully thinking through resulting functionality!

    Direction heading{Down};

    printAngle(heading); // testing 

    std::cout << "The int value of Direction heading is : " << heading << std::endl; //with the old enums we can print them just like an int

    Color color{Red};
    std::cout << "The int value of Color color is : " << color << std::endl; //with the old enums we can print them just like an int
    
    //problem area,
    //for safety we as programers only want it so that any conversions done EXPLICITLY, where we control the scenario
    //the old enums let you use them for whatever, ie.. the below
    //the idea of comparing values of different enums doesnt make sense
    std::cout << "color > heading :" << (color > heading) << std::endl; // will create a warning on compile! Deprecated functionality
                                                                        // bad behavior
    
    return 0;
}

void printAngle(Direction heading)
{
    switch(heading){
        case Up: //doesnt require class scope name, because it isnt a class ? Old version polutes namespace
            std::cout << "Your current heading in degrees is 90" << std::endl;
            break;
        case Direction::Down: //we can still use the scope operator though
            std::cout << "Your current heading in degrees is 270" << std::endl;
            break;
        case Left:
            std::cout << "Your current heading in degrees is 180" << std::endl;
            break;
        case Right:
            std::cout << "Your current heading in degrees is 0" << std::endl;
            break;
    };
};
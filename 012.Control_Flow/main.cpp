#include <iostream>
#include <iomanip>

//delicious re-usable formating values
const int cA{25};
const int cB{50};
const int cC{75};

int main(){
    
    //Flow Control!
    std::cout << std::setw(cC) << std::setfill('-') << "If Statements" << std::setfill(' ') << std::endl;
    int number1 {55};
    int number2 {60};

    bool result = (number1 < number2);

    if (result)
    {
        std::cout << number1 << " is less than "<< number2 << std::endl;
    }
    else
    {
        std::cout << number1 << " is --NOT-- less than "<< number2 << std::endl;
    }

    if (number1 < number2) //no need to break out conditional since it evaluates to a boolean already and isnt neccessarily complicated
    {
        std::cout << number1 << " is less than "<< number2 << std::endl;
    }
    else
    {
        std::cout << number1 << " is --NOT-- less than "<< number2 << std::endl;
    }

    bool valueCheck{false};
    //nested if statements
    if(valueCheck)
    {
        if (number1 < number2) //no need to break out conditional since it evaluates to a boolean already and isnt neccessarily complicated
        {
            std::cout << number1 << " is less than "<< number2 << std::endl;
        }
        else
        {
            std::cout << number1 << " is --NOT-- less than "<< number2 << std::endl;
        }
    }
    else
    {
        std::cout << "The values were not checked!" << std::endl;
    }

    //compound logic if statements
    if (valueCheck & (number1 < number2))
    {
        std::cout << number1 << " is less than "<< number2 << std::endl;
    }
    else if (valueCheck)
    {
        std::cout << number1 << " is --NOT-- less than "<< number2 << std::endl;
    }
    else
    {
        std::cout << "The values were not checked!" << std::endl;
    }

    //else if stuff
    std::cout << std::setw(cC) << std::setfill('-') << "Else If" << std::setfill(' ') << std::endl;
    const int Pen{10};
    const int Marker{20};
    const int Eraser{30};
    const int Rectangle{40};
    const int Circle{50};
    const int Other{60};

    int tool{Circle};

    if (tool == Pen)
    {
        std::cout << "Active tool is Pen" <<std::endl;
    }
    else if (tool == Marker)
    {
        std::cout << "Active tool is Marker" <<std::endl;
    }
    else if (tool == Eraser)
    {
        std::cout << "Active tool is Eraser" <<std::endl;
    }
    else if (tool == Rectangle)
    {
        std::cout << "Active tool is Rectangle" <<std::endl;
    }
    else if (tool == Circle)
    {
        std::cout << "Active tool is Circle" <<std::endl;
    }
    else if (tool == Other)
    {
        std::cout << "Active tool is Other" <<std::endl;
    }

    //Switch
    std::cout << std::setw(cC) << std::setfill('-') << "Switch Statements" << std::setfill(' ') << std::endl;

    //important! If break statements are left out all code under matching case WILL EXECUTE
    // This is regardless of whether or not the case matches the input. Could be used to execute dependant code blocks?

    //switch takes in integral types! Integers and kind, also Enums but they havent gotten there yet

    switch(tool) // starts switch block
    {
        case Pen:{ //case used for comparison
            std::cout << "Active tool is Pen" <<std::endl; //code excuted on true
        }
        break; // break goes after code block?, sends flow out of switch block

        case Marker:{
            std::cout << "Active tool is Marker" <<std::endl;
        }
        break;

        case Eraser:{
            std::cout << "Active tool is Eraser" <<std::endl;
        }
        break;

        case Rectangle:{
            std::cout << "Active tool is Rectangle" <<std::endl;
        }
        break;

        case Circle:{
            std::cout << "Active tool is Circle" <<std::endl;
        }
        break;

        case Other:{
            std::cout << "Active tool is Other" <<std::endl;
        }
        break;

        default:{ //default case is for when no matches are found
            std::cout<< "No match found!" << std::endl;
        }
        break;
    }

    //Short circuit evaluations, simply check the most important condition (efficient running/ bottle neck) first to prevent unnecessary conditional checking and code execution
    //if (car() && house() && job() && hobby())
    //if car fails then none of the others execute, saving processing time
    //inverse case if || is used

    //Integral Logic Conditions
    std::cout << std::setw(cC) << std::setfill('-') << "Integral Logic Conditions" << std::setfill(' ') << std::endl;

    //integers turning evaluating ints as booleans 
    // 0 is false
    // everything else is true, -n and +n 
    // ie. if(-3) evaluates to true
    if(10 - 10)
    {
        std::cout << "There is a value of some kind, condition success." << std::endl;
    }
    else
    {
        std::cout << "Dude there is no value, condition failure!" << std::endl;
    }

    if(10 - 15)
    {
        std::cout << "There is a value of some kind, condition success." << std::endl;
    }
    else
    {
        std::cout << "Dude there is no value, condition failure!" << std::endl;
    }

    //Ternary Operators
    std::cout << std::setw(cC) << std::setfill('-') << "Ternary Operators" << std::setfill(' ') << std::endl;
    //result = (condition) ? option1 : options2;
    int valA = 10;
    int valB = 20;
    int maxVal = (valA > valB) ? valA : valB; //ternary assignment
    //ofcourse types of option result should match type or be convertible to that of the variable we are assigning value to

    std::cout << "The maximum value is " << maxVal << std::endl;

    auto maxVal2 = (valA > valB)? valA : 22.5f; // in this case we actually see the compiler deduces the float as the resulting type, my guess based on byte hiearchy of possible resultants
    std::cout << "The maximum value 2 is " << maxVal2 << std::endl;
    auto maxVal3 = (valA < valB)? valA : 22.5f; // in this case we actually see the compiler deduces the float as the resulting type, my guess based on byte hiearchy of possible resultants
    std::cout << std::showpoint;
    std::cout << "The maximum value 3 is " << maxVal3 << std::endl;

    //can also be used to execute functions, void or otherwise
    // (valA > valB) ? methodA() : methodB(); //ternary execution

    //If Constexpr
    std::cout << std::setw(cC) << std::setfill('-') << "If Constexpr" << std::setfill(' ') << std::endl;

    constexpr bool condition {false};

    if constexpr (condition) // if this condition fails at compile time this condition will not exist in final program,
    //need some more info on this one... is it that the other track dissapears? Thats nifty
    {
        std::cout << "Constexpr condition is true" << std::endl;
    }
    else
    {
        std::cout << "Constexpr condition is false" << std::endl;
    }

    //If Initializer
    std::cout << std::setw(cC) << std::setfill('-') << "If Initializer" << std::setfill(' ') << std::endl;

    //This is pretty neat! Looks like in modern C++ you can initialize a variable in an if statement so it doesnt polute the outer scope

    int speed {10}; // have to declare speed out of if statement scope to use it in passing and failing condition blocks

    bool go {false};

    if (go){
        if (speed > 5)
        {
            std::cout << "Slow down!" << std::endl;
        } else {
            std::cout << "All good!" << std::endl;
        }
    }
    else 
    {
        std::cout << "speed : " << speed << std::endl;
        std::cout << "Stop!" << std::endl;
    }

    std::cout << std::setw(cA) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    /////////////////////////////VS///////////////////////////////////
    
    if ( int newSpeed{44};go){ //variable here MUST be initialized, if by function, variable, literal, or god
        if (newSpeed > 5)
        {
            std::cout << "Slow down!" << std::endl;
        } else {
            std::cout << "All good!" << std::endl;
        }
    }
    else 
    {
        std::cout << "speed : " << newSpeed << std::endl;
        std::cout << "Stop!" << std::endl;
    }

    //newSpeed int has a scope of the entire if condition, pretty nifty!
    // YOU CAN ONLY HAVE ONE INITIALIZER

    //Switch Initializer
    std::cout << std::setw(cC) << std::setfill('-') << "Switch Initializer" << std::setfill(' ') << std::endl;

    switch(int tool2{Circle}; tool2) // look at that! new initialized thing for a switch, if that isn't swell
    //This can also be completely unrelated to the switch condition
    //switch(double strength{24.74}; tool) // use it for whatever, very cool
    {
        case Pen:{ //case used for comparison
            std::cout << "Active tool is Pen" <<std::endl; //code excuted on true
        }
        break; // break goes after code block?, sends flow out of switch block

        case Marker:{
            std::cout << "Active tool is Marker" <<std::endl;
        }
        break;

        case Eraser:{
            std::cout << "Active tool is Eraser" <<std::endl;
        }
        break;

        case Rectangle:{
            std::cout << "Active tool is Rectangle" <<std::endl;
        }
        break;

        case Circle:{
            std::cout << "Active tool is Circle" <<std::endl;
        }
        break;

        case Other:{
            std::cout << "Active tool is Other" <<std::endl;
        }
        break;

        default:{ //default case is for when no matches are found
            std::cout<< "No match found!" << std::endl;
        }
        break;
    }

    //Note on switch scope, mentioned in lecture but seems wrong...
    /////////////////////////////////////////////////////////////////////////////
    // All cases in switch use the same scope?
    // HOWEVER, you can not initialize variables
    // This opens up the can of worms where some code could be executed that makes use of a variable that was never initialized
    /////////////////////////////////////////////////////////////////////////////
    //it looks like the compiler just stops you from using variables declared in other cases, mentioning undeclared, so the lecture is wrong? whatever, it seems sorta pointless anyway

    //Dude I dont even know anymore, looks like this could be compiler dependent...just dont mess with it
    return 0;
}
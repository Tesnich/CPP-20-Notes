#include <iostream>
#include "MonthEnums.h"

enum class Month {
    Jan, Feb, Mar, Apr,
    May, Jun, Jul, Aug,
    Sep, Oct, Nov, Dec
};

enum class MonthGood {
    Jan = 1, Feb, Mar, Apr, //manually assigning 1 sets starting position for following enums ie...
    May, Jun, Jul, Aug,     // {1,2,3,4...}
    Sep, Oct, Nov, Dec
};

// enum class MonthBetter {                 //In this case we will iterate by one until we get to 18, then increment by 1 based on the previous value
//     Jan = 1, Feb, Mar, Apr,              // so we get {1,2,3,4,5,6,18,19,20,21,22}
//     May, Jun, Jul, Aug = 18,             //            -           --
//     Sep, Oct, Nov, Dec
// };

enum class MonthBetter {
    Jan = 1, January =1, Feb=2, February=2, Mar, Apr, // multiple names can be associated to the same enum value ...
    May, Jun, Jul, Aug,                               // however, in the example given if we continued this pattern we would not be able to make use of auto incrementation
    Sep, Oct, Nov, Dec
};

enum class MonthBest {
    Jan = 1, January = Jan,  //by using the first shorter enum as a basis for the longer the auto numbering remains intact
    Feb, February = Feb,     //     and can even be changed throughout by changing the first very easily!
    Mar, March = Mar,
    Apr, April = Apr,
    May,
    Jun, June = Jun,
    Jul, July = Jul,
    Aug, August = Aug,
    Sep, September = Sep,
    Oct, October = Oct,
    Nov, November = Nov,
    Dec, December = Dec
};

enum class MonthChar : unsigned char { //manually change the type that is associated with the numbering to char instead of int
    Jan = 1, January = Jan,  
    Feb, February = Feb,
    Apr, April = Apr,
    May,
    Jun, June = Jun,
    Jul, July = Jul,
    Aug, August = Aug,
    Sep, September = Sep,
    Oct, October = Oct,
    Nov, November = Nov,
    Dec, December = Dec
};

void printMonth(MonthEnums monthEnum);

void printMonthCPP20(MonthEnums monthEnum); //function containing switch with C++ 20 line 'using enum MonthEnums;'

std::string_view getStringViewFromMonthEnums(MonthEnums monthEnum); //fun little way to return names, nothing new just a nice way to structure this

int main(){
    
    //Enumerated types (Enum Class)

    //Format is 'Class_name objectname(can be anything you choose) {Class_name::enum_name};
    Month month {Month::Jul}; //initialized to Jul

    //  Ilegal
    //std::cout << "month : " << month << std::endl;
    //  The enum is not printable in natural state, it is designed for internal use for ease of options programming

    std::cout << "month : " << static_cast<int>(month) << std::endl; // we can cast it to an int though, which is printable
    //each enum value is represented by an int by default
    //note that these enum values will start at 0, like an array!

    //this automatic numbering can be overriden though! Look at MonthGood -> MonthBest for different implementation methods

    std::cout << "The size of Month enum class type is : " << sizeof(Month) << std::endl;
    std::cout << "The size of Int type is              : " << sizeof(int) << std::endl;

    //while the default for an enum is an int, we can manually specify the type used for numbering!
    //CHECK OUT class MonthChar where we create an enum with the char type as the base

    std::cout << "The size of MonthChar enum class type is : " << sizeof(MonthChar) << std::endl;
    std::cout << "The size of char type is                 : " << sizeof(unsigned char) << std::endl;

    //enums, like we saw with function declarations, can be defined in header files!
    MonthEnums monthEnum {MonthEnums::December};
    std::cout << "monthEnum defined from MonthEnums header : " << static_cast<int>(monthEnum) << std::endl; // we can cast it to an int though, which is printable

    //Something interesting to take note of
    //There is no implict conversion to enums?
    printMonth(monthEnum); //This works!

    //Ilegal!
    //printMonth(12);

    int intMonth {6};
    //Ilegal!
    //printMonth(intMonth);

    printMonth(MonthEnums{intMonth}); //This works!

    //The method printMonth uses the format MonthEnums::Jan, MonthEnums::Feb ... over and over again
    //C++ 20 allows us to skip all that with one line! Observe the function printMonthCPP20()!

    //using enum MonthEnums;
    printMonthCPP20(monthEnum);

    //fun method to print out names from enum, busy but fun
    std::cout << "The month is : " << getStringViewFromMonthEnums(monthEnum) << std::endl;

    return 0;
}

void printMonth(MonthEnums monthEnum)
{
    switch(monthEnum){
        case MonthEnums::Jan:
            std::cout << "The month is Jan" << std::endl;
            break;
        case MonthEnums::Feb:
            std::cout << "The month is Feb" << std::endl;
            break;
        case MonthEnums::Mar:
            std::cout << "The month is Mar" << std::endl;
            break;
        case MonthEnums::Apr:
            std::cout << "The month is Apr" << std::endl;
            break;
        case MonthEnums::May:
            std::cout << "The month is May" << std::endl;
            break;
        case MonthEnums::Jun:
            std::cout << "The month is Jun" << std::endl;
            break;
        case MonthEnums::Jul:
            std::cout << "The month is Jul" << std::endl;
            break;
        case MonthEnums::Aug:
            std::cout << "The month is Aug" << std::endl;
            break;
        case MonthEnums::Sep:
            std::cout << "The month is Sep" << std::endl;
            break;
        case MonthEnums::Oct:
            std::cout << "The month is Oct" << std::endl;
            break;
        case MonthEnums::Nov:
            std::cout << "The month is Nov" << std::endl;
            break;
        case MonthEnums::Dec:
            std::cout << "The month is Dec" << std::endl;
            break;

        default:
            std::cout << "No valid month supplied!" << std::endl;
    }
}

void printMonthCPP20(MonthEnums monthEnum)
{
    switch(monthEnum){
        using enum MonthEnums; // <---WITH THIS LINE 
        case Jan:              // gone are the days of 'case MonthEnums::Jan:', we can now just use 'case Jan:' !!!
            std::cout << "The month is Jan" << std::endl;
            break;
        case Feb:
            std::cout << "The month is Feb" << std::endl;
            break;
        case Mar:
            std::cout << "The month is Mar" << std::endl;
            break;
        case Apr:
            std::cout << "The month is Apr" << std::endl;
            break;
        case May:
            std::cout << "The month is May" << std::endl;
            break;
        case Jun:
            std::cout << "The month is Jun" << std::endl;
            break;
        case Jul:
            std::cout << "The month is Jul" << std::endl;
            break;
        case Aug:
            std::cout << "The month is Aug" << std::endl;
            break;
        case Sep:
            std::cout << "The month is Sep" << std::endl;
            break;
        case Oct:
            std::cout << "The month is Oct" << std::endl;
            break;
        case Nov:
            std::cout << "The month is Nov" << std::endl;
            break;
        case Dec:
            std::cout << "The month is Dec" << std::endl;
            break;

        default:
            std::cout << "No valid month supplied!" << std::endl;
    }
}

std::string_view getStringViewFromMonthEnums(MonthEnums monthEnum)
{
    switch(monthEnum){
        using enum MonthEnums;
        case Jan:
            return "January";
            break;
        case Feb:
            return "February";
            break;
        case Mar:
            return "March";
            break;
        case Apr:
            return "April";
            break;
        case May:
            return "May";
            break;
        case Jun:
            return "June";
            break;
        case Jul:
            return "July";
            break;
        case Aug:
            return "August";
            break;
        case Sep:
            return "September";
            break;
        case Oct:
            return "October";
            break;
        case Nov:
            return "November";
            break;
        case Dec:
            return "December";
            break;
        default:
            return "Invalid";
    }
}
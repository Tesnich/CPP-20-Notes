#include <iostream>
#include <string>

std::string GetDayName(int selection)
{
    switch(selection)
    {
        case 1:
        return "Monday";

        case 2:
        return "Tuesday";

        case 3:
        return "Wednesday";

        case 4:
        return "Thursday";

        case 5:
        return "Friday";

        case 6:
        return "Saturday";

        case 7:
        return "Sunday";

        default:
        return "";
    }
}

int main(){
    std::cout << "Please select a day with an int between 1 and 7 :";
    int selection;
    std::cin >> selection;
    if (GetDayName(selection).empty())
    {
        std::cout << "You ruin everything" << std::endl;
        return;
    }
    std::cout<< "The day you chose was " << GetDayName(selection) <<std::endl;
    std::cout << "Please select an int for number of days to rewind :";
    int delta;
    std::cin >> delta;
    int deltaShort = delta %7;
    int pastDay = ((selection - deltaShort)> -1) ? (selection - deltaShort) : 7 + (selection - deltaShort);
    std::cout<< "The day in the past was " << GetDayName(pastDay) <<std::endl;

    return 0;
}
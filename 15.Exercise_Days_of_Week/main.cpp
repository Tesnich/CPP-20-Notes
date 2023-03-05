#include <iostream>
#include <string>

int main(){
    std::cout << "Please select a day with an int between 1 and 7 :";
    int selection;
    std::cin >> selection;
    std::string dayName;
    switch(selection)
    {
        case 1:
        {
            dayName = "Monday";
        }
        break;

        case 2:
        {
            dayName = "Tuesday";
        }
        break;

        case 3:
        {
            dayName = "Wednesday";
        }
        break;

        case 4:
        {
            dayName = "Thursday";
        }
        break;

        case 5:
        {
            dayName = "Friday";
        }
        break;

        case 6:
        {
            dayName = "Saturday";
        }
        break;

        case 7:
        {
            dayName = "Sunday";
        }
        break;

        default:
        {
            dayName = "INVALID";
        }
        break;
    }

    std::cout<< "The day you chose was " << dayName <<std::endl;

    return 0;
}
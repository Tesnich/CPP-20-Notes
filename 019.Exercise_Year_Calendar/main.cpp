#include <iostream>
#include <iomanip>
#include <string>

//Print out a calander for the user

std::string MonthNameFromNumber(unsigned int month)
{
    std::string monthName{"INVALID"};

    switch (month)
    {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
    }
    return monthName;
}

unsigned int GetDaysInMonth(unsigned int month, unsigned int year)
{
    int numberOfDays = 30;

    switch (month)
    {
        case 1:
            numberOfDays = 31;
            break;
        case 2:
            numberOfDays = (year %4) ? 28 : 29;
            break;
        case 3:
            numberOfDays = 31;
            break;
        case 4:
            numberOfDays = 30;
            break;
        case 5:
            numberOfDays = 31;
            break;
        case 6:
            numberOfDays = 30;
            break;
        case 7:
            numberOfDays = 31;
            break;
        case 8:
            numberOfDays = 31;
            break;
        case 9:
            numberOfDays = 30;
            break;
        case 10:
            numberOfDays = 31;
            break;
        case 11:
            numberOfDays = 30;
            break;
        case 12:
            numberOfDays = 31;
            break;
    }
    return numberOfDays;
}

void PrintDaysOfWeek()
{
    std::cout << std::setw(5) << "Mon";
    std::cout << std::setw(5) << "Tue";
    std::cout << std::setw(5) << "Wed";
    std::cout << std::setw(5) << "Thu";
    std::cout << std::setw(5) << "Fri";
    std::cout << std::setw(5) << "Sat";
    std::cout << std::setw(5) << "Sun" << std::endl;
}

int main(){
    std::cout << "Enter a year :";
    unsigned int year{};
    std::cin >> year;
    std::cout << "Enter the first day of the year [1: MOnday, ... 7:Sunday] :";
    unsigned int firstDay{};
    std::cin >> firstDay;

    std::cout << std::endl << "Calendar for " << year << std::endl;

    for(unsigned int month{1}; month < 13; ++month)
    {
        std::cout << "--" << MonthNameFromNumber(month) << " " << year << "--" << std::endl;
        PrintDaysOfWeek();
        unsigned int numberOfDaysInMonth = GetDaysInMonth(month, year);
        unsigned int currentDay{1};

        while(currentDay < numberOfDaysInMonth) //weeks in month (row loop)
        {
            for(unsigned int i{1}; i < 8; ++i) // days in week (column loop)
            {
                if(currentDay > numberOfDaysInMonth) //escape week if we pass number of days in month
                {
                    firstDay = i; //setting first day here in the event last day of month does not end on sunday, keeps padding on next month correct
                    // if it ended on sunday it was already set to 1 when first day was reached so its set up for next month
                    break;
                }
                
                if(i<firstDay) // pad week day spot with space if month hasn't start yet
                {
                    std::cout << std::setw(5) << " ";
                }
                else
                {
                    if(i == firstDay) //since first day is used in loop to determine starting point when printing weekdays, need to set to 1 after first day is reached for next week
                    {
                        firstDay = 1;
                    }
                    std::cout << std::setw(5) << currentDay++;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
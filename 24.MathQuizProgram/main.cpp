#include <iostream>
#include <iomanip>

int main(){
    bool programEnd = false;

    std::cout << "Welcome To Math Quiz Plus+ !" << std::endl;

    std::srand(std::time(0)); // randomize seed based on time

    unsigned int totalQuestions{0}, correctAnswers{0};

    do
    {
        if(totalQuestions)
        {
            std::cout << std::endl << "NEXT QUESTION (Y/N) : ";
            char response{};
            std::cin >> response;
            if(response != 'Y' && response != 'y' && response != 'N' && response != 'n' )
                continue;
            if(response == 'N' || response == 'n')
                break;
            std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
        }

        int valueA = std::rand()%200;
        int valueB = std::rand()%200;
        int result{};
        char opperator{};

        switch (std::rand()%3)
        {
            case 0:
            {
                result = valueA + valueB;
                opperator = '+';
                break;
            }
            case 1:
            {
                result = valueA - valueB;
                opperator = '-';
                break;
            }
            case 2:
            {
                result = valueA * valueB;
                opperator = '*';
                break;
            }
        };

        std::cout << "What's the result of " << valueA << " " << opperator << " " << valueB << " : ";
        int userInput{};
        std::cin >> userInput;
        if(userInput == result)
        {
            std::cout << "Congratulations! You got the result " << result << " right!";
            ++correctAnswers;
        }
        else
        {
            std::cout << "Naah! The correct result is " << result << "!";
        }
        ++totalQuestions;

        std::cout << std::endl << std::endl << std::setw(50) << std::setfill('-') << "STATS" << std::setfill(' ') << std::endl;
        std::cout << "Correct Answers " << correctAnswers <<"/"<< totalQuestions << " Total Questions" << std::endl;
        std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

    } while (!programEnd);

    std::cout << std::endl << "Goodbye!" << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;

}
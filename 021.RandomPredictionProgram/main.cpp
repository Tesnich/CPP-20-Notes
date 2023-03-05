#include <iostream>

const char prediction0[]{ "a lot of kinds running in the backyard!'" };
const char prediction1[]{ "a lot of empty beer bootles on your work table.'" };
const char prediction2[]{ "you Partying too much with kids wearing weird clothes.'" };
const char prediction3[]{ "you running away from something really scary'" };
const char prediction4[]{ "clouds gathering in the sky and an army standing ready for war'" };
const char prediction5[]{ "dogs running around in a deserted empty city'" };
const char prediction6[]{ "a lot of cars stuck in a terrible traffic jam'" };
const char prediction7[]{ "you sitting in the dark typing lots of lines of code on your dirty computer'" };
const char prediction8[]{ "you yelling at your boss. And oh no! You get fired!'" };
const char prediction9[]{ "you laughing your lungs out. I've never seen this before.'" };

int main(){
    std::cout << std::endl << "A dark and langly figure emerges from the fog infront of you..." << std::endl << std::endl;

    std::cout << "'What is your name traveler?' : ";
    
    const int maxLength{15};
    char name [maxLength]{}; //you need to use a constant value to construct the size of an array, thus max_length must be const

    //the below std library function getline works with c++ style strings!, can't use it to store value in a char[] i dont think
    //std::string stringName;
    //std::getline(std::cin, stringName);

    std::cin.getline(name, maxLength);

    bool endOfProgram = false;

    std::cout <<std::endl << "'Would you like to know your future, " << name << "?'" <<std::endl << std::endl;

    std::srand(std::time(0)); // randomize seed

    while(!endOfProgram)
    {
        char input{};
        std::cout << "Tempt fate? (Y/N) :";
        std::cin >> input;
        if(input != 'Y' && input != 'N') continue;
        if ((endOfProgram = (input == 'N') ? true : false)) continue;

        std::cout <<std::endl << "'Oh dear " << name << ", I see ";

        switch(std::rand()%10)
        {
            case 0:
                std::cout << prediction0 << std::endl << std::endl;
                break;
            case 1:
                std::cout << prediction1 << std::endl << std::endl;
                break;
            case 2:
                std::cout << prediction2 << std::endl << std::endl;
                break;
            case 3:
                std::cout << prediction3 << std::endl << std::endl;
                break;
            case 4:
                std::cout << prediction4 << std::endl << std::endl;
                break;
            case 5:
                std::cout << prediction5 << std::endl << std::endl;
                break;
            case 6:
                std::cout << prediction6 << std::endl << std::endl;
                break;
            case 7:
                std::cout << prediction7 << std::endl << std::endl;
                break;
            case 8:
                std::cout << prediction8 << std::endl << std::endl;
                break;
            case 9:
                std::cout << prediction9 << std::endl << std::endl;
                break;
            default:
                std::cout << "nothing right now. The fog is thick tonight...'" << std::endl << std::endl;
        }
    }

    std::cout << std::endl << "The figure nods and starts moving again. As it passes you feel a chill on your spine. The outline of the visitor dissapates into the fog behind you." << std::endl << std::endl;

    std::cout << "You feel as though your mind has been numbed. You struggle to remember what had happened." << std::endl << std::endl;

    return 0;
}
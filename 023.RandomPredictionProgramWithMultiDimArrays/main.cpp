#include <iostream>

const char predictions[][100] //changed to be multi dimensional
{
    { "a lot of kinds running in the backyard!'" },
    { "a lot of empty beer bootles on your work table.'" },
    { "you Partying too much with kids wearing weird clothes.'" },
    { "you running away from something really scary'" },
    { "clouds gathering in the sky and an army standing ready for war'" },
    { "dogs running around in a deserted empty city'" },
    { "a lot of cars stuck in a terrible traffic jam'" },
    { "you sitting in the dark typing lots of lines of code on your dirty computer'" },
    { "you yelling at your boss. And oh no! You get fired!'" },
    { "you laughing your lungs out. I've never seen this before.'" }
};


int main(){
    std::cout << std::endl << "A dark and langly figure emerges from the fog infront of you..." << std::endl << std::endl;

    std::cout << "'What is your name traveler?' : ";
    
    const int maxLength{15};
    char name [maxLength]{};

    std::cin.getline(name, maxLength);

    bool endOfProgram = false;

    std::cout <<std::endl << "'Would you like to know your future, " << name << "?'" <<std::endl << std::endl;

    std::srand(std::time(0));

    while(!endOfProgram)
    {
        char input{};
        std::cout << "Tempt fate? (Y/N) :";
        std::cin >> input;
        if(input != 'Y' && input != 'N') continue;
        if ((endOfProgram = (input == 'N') ? true : false)) continue;

        std::cout <<std::endl << "'Oh dear " << name << ", I see ";

        std::cout<< predictions[std::rand()%std::size(predictions)] << std::endl << std::endl; // changed to use random number to access multidimensional array
    }

    std::cout << std::endl << "The figure nods and starts moving again. As it passes you feel a chill on your spine. The outline of the visitor dissapates into the fog behind you." << std::endl << std::endl;

    std::cout << "You feel as though your mind has been numbed. You struggle to remember what had happened." << std::endl << std::endl;

    return 0;
}
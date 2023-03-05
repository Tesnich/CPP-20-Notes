#ifndef LEVEL_1_H
#define LEVEL_1_H
#include <iostream>

class Level1
{
    private:
        /* data */
    public:
        Level1() {
            std::cout << "Level1() - Constructor Called!\n";
        }
        ~Level1() = default;
};

#endif
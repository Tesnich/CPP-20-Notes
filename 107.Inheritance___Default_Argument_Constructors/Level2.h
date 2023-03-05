#ifndef LEVEL_2_H
#define LEVEL_2_H
#include <iostream>
#include "Level1.h"

class Level2 : public Level1
{
    private:
        /* data */
    public:
        Level2() {
            std::cout << "Level2() - Constructor Called!\n";
        }
        ~Level2() = default;
};

#endif
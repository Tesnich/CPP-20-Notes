#ifndef LEVEL_3_H
#define LEVEL_3_H
#include <iostream>
#include "Level2.h"

class Level3 : public Level2
{
    private:
        /* data */
    public:
        Level3() {
            std::cout << "Level3() - Constructor Called!\n";
        }
        ~Level3() = default;
};

#endif
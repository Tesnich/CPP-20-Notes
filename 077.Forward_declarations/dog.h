#ifndef DOG_H
#define DOG_H

#include <string>
#include <string_view>

class Dog{
    private :
        std::string color_;
    public :
        Dog();
        Dog(std::string_view color);

        friend class Farm;
};

#endif
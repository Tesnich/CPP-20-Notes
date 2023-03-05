#ifndef OBJECT_LIFE_WATCH_H
#define OBJECT_LIFE_WATCH_H
#include <iostream>

class ObjectLifeWatch
{
    private:
        inline static unsigned int instances{};
        unsigned int instanceId_{};
    public:
        ObjectLifeWatch()
            :instanceId_{++instances} {
            std::cout << "ObjectLifeWatch (" << instanceId_ << ") Constructed !\n";
        }

        ~ObjectLifeWatch(){
            std::cout << "ObjectLifeWatch (" << instanceId_ << ") Destructed !\n";
        }
};
#endif
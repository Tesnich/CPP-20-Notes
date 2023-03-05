#ifndef DESTRUCTOR_WATCH_H
#define DESTRUCTOR_WATCH_H
#include <iostream>

class DestructorWatch
{
    protected:
        inline static unsigned int newInstanceCount{0};
        unsigned int instanceId_{};
    public:
        DestructorWatch()
            :instanceId_{++newInstanceCount} {}
        virtual ~DestructorWatch() {
            std::cout << "DestructorWatch("<< instanceId_ <<") Begining Destructor\n";
            throw 5.0; // <--- g++ is smart enough to realize this will always terminate the program, raises warning
            std::cout << "DestructorWatch("<< instanceId_ <<") Destructor Finished\n";
        }
};


#endif
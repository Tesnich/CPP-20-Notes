#ifndef DESTRUCTOR_WATCH_2_H
#define DESTRUCTOR_WATCH_2_H
#include <iostream>

class DestructorWatch2
{
    protected:
        inline static unsigned int newInstanceCount{0};
        unsigned int instanceId_{};
    public:
        DestructorWatch2()
            :instanceId_{++newInstanceCount} {}
//                                                  the noexcept identifier with 'false' as an argument overrides
//                                  _______________ the default noexcept nature of destructors
        virtual ~DestructorWatch2() noexcept(false) {
//                                  ^^^^^^^^^^^^^^^
            std::cout << "DestructorWatch("<< instanceId_ <<") Begining Destructor\n";
            throw 5.0; // <--- will not cause program termination now
            std::cout << "DestructorWatch("<< instanceId_ <<") Destructor Finished\n";
        }
};


#endif
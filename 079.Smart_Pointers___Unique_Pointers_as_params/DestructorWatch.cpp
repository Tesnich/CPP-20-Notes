#include "DestructorWatch.h"
#include <iostream>

unsigned int DestructorWatch::count{0};

DestructorWatch::DestructorWatch()
    :identifier_{count++}
    {
        std::cout << "DestructorWatch("<<identifier_<<") Constructed" << std::endl;
    }

DestructorWatch::~DestructorWatch(){
    std::cout << "DestructorWatch("<<identifier_<<") Destructed" << std::endl;
}
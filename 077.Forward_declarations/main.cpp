#include <iostream>

#include "farm.h"
#include "dog.h"

int main(int argc, char **argv){

    //Forward Declarations

    //Sometimes you may write some classes that make use of another class, but dont need
    //  that other classes, definition to work. Forward declarations allow you to bring in just
    //  those names to limit the amount of included code. 

    //examine farm.h

    Farm mcDonalds{};
    Dog defaultDog{};
    Dog customDog{"Blue"};

    mcDonalds.UseDog(defaultDog);
    mcDonalds.UseDog(customDog);

    return 0;
}
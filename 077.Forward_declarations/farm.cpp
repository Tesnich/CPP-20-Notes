#include <iostream>
#include "farm.h"
#include "dog.h"

void Farm::UseDog(const Dog& dogParam){
    std::cout << dogParam.color_ << std::endl; //we are able to get away with using the forward declaration
}                                              //in the header, but here we are required to bring in the full class
                                               //to make use of its memebers.

//To solve, include dog.h here. If we included dog.h in the header of farm, this would resolve because
//we include the header of farm here, but then we are back with the inefficiency during changes of dog
//and anything that included farm.h having to be recompiled.
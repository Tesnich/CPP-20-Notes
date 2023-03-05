#include <iostream>
#include "Map.h"

int main(int argc, char **argv){

    //Assignment 22

    //compilation should pass
    Map<int, std::string> m1(11222,std::string{"Steve Murphy"}); // Works
    Map<long int,std::string> m2(22333,"Ahmed Malik"); // Works 

    //compilation should fail
    Map<double,unsigned int> m3(22.1,44555);

    return 0;
}
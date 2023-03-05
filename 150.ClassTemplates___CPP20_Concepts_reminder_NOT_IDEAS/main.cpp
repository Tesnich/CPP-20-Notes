#include <iostream>
#include "Point.h"

int main(int argc, char **argv){

    //Class templates and C++ 20 'Concepts'
    //reminder, #include <concepts> https://en.cppreference.com/w/cpp/concepts

    //passing
    Point point{1,2};

    //failing
    std::string pizza{"Pizza"};
    Point<std::string> strPoint{pizza};

    //NOTE!!! I have a constructor for the Point class that takes in an initializer_list
    //this was because I wanted it to be easy to declare dimension and valuetype on initialization
    //with just {1,2,3...}

    //Unfortunately this fucks with c++ template concepts error in the build output
    //I was not able to get that nice clear violation of the requires clause unless I manually
    //put in the type above. My guess is because pizza alone as an argument was seen as an intializer list

    //Remember this when writing classes that may take in lists of strings...

    return 0;
}
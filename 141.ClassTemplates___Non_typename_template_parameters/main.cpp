#include <iostream>
#include "Maximum.h"

int main(int argc, char **argv){

    //Non type template parameters (sorta c++ 20)
    //Before c++ 20 only ints were supported as non type template parameters, now anything goes

    //In addition to specifying a typename in 'template<...>' you can also specify a type for value input

    //Look at class Maximum... it has 'typename T' and 'T max' as its template params

    Maximum<int, 10> maximum{5};
    std::cout << maximum.Status() << "\n";
    Maximum<int, 10> maximum2{20};
    std::cout << maximum2.Status() << "\n";

    //non type template parameters are const objects baked into a class

    //in my opinion not having this as a const object initialized by constructor arguments is the wrong move
    //not only do we enforce strange syntax, but FOR EACH value of the non type template parameter
    //A CLASS IS CREATED. If you pass in a wide range of values your program is going to grow substantially on
    //compilation. This also precludes the use of any kind of staticly shared variables between all these instances,
    //because static vars are shared per class. Each one of these will have their own static vars.

    return 0;
}
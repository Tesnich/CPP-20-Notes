#include <iostream>
#include "Level3.h"

int main(int argc, char **argv){

    //Default arg constructors and inheritance!

    /*
        On construction of the below classes, the following is the call order of constructors...

        Class Person {...};     | Class Engineer : public Person {...};     | Class CivilEng : public Engineer {...};
        ---------------------------------------------------------------------------------------------------------
        1.) Person{};           | 1.) Person{};                             | 1.) Person{};
                                | 2.) Engineer{};                           | 2.) Engineer{};
                                                                            | 3.) CivilEng{};

        A derived class will construct its base class first. If that base class is actually derived
        itself, then it will construct its base before calling its own constructor.

        You end up with the earliest building block having its constructor called first, leading a cascade
        of subsequent constructor calls.

        Knowing this it's very important to give your classes constructors (even defaulted) so you know
        exactly what is being called as a result of an "Inheritance Hierarchy".
    */

    //In this example Level2 is derived from Level1, and Level3 is derived from Level2
    //Observe...
    Level3 level3{};

    return 0;
}
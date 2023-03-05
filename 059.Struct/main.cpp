#include <iostream>

struct Cat{
    double x;
    double y;
};
//can do everything a class does, including using public: and private:

int main(int argc, char **argv){

    //struct 

    //structures are exactly the same as classes EXCEPT all members are PUBLIC be default

    //should really be used for structures where you dont mind the user touching everything, think data structures more 
    //than a means to store functionality and data structures (although you can use it however you want)

    return 0;
}


//note : typically the size of an object is the size of all its member variables (sometimes pointers for strings). Sometimes this isnt the case because
//       of boundary alignment. This is the compiler's method of trying to align objects in data within groups of 4.
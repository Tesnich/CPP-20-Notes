#include <iostream>
#include "Item.h"

int main(int argc, char **argv){

    //Overloading the spaceship operator on a class whose member variables dont support the spaceship opperator

    Item itemA(1,1,1), itemB(1,1,1);

    std::cout << ((itemA <=> itemB) == 0) <<"\n";
    //the above line doesnt build because the <=> overload setup in the Item.h file doesn't build
    //If you comment out the statement 'Integer d_{};' in the Item class, however, it will build!

    //Now uncoment d_
    //as well as the overloads created on the Integer class for < and ==

    //if we try to build again we still wont succeed, but an error in respect to our <=> overload says
    //that the auto we are using precludes the use of < and == and we need to give it a type

    //swap it for the line under with std::strong_ordering

    //despite some error highlighting because visual studio has no idea whats going on...
    //because we are telling the compiler we would like a specific three way operator as result of our <=> overload,
    //our compiler is successful in synthesizing a Integer <=> overload using Integer's < and == overloads!

    //I can follow the beats here, but I'm just not sure why the compiler needs a return type over auto here.
    //It could be that a custom <=> could be written to return whatever we want, bool, double, etc...
    //So it can't take the next step in parsing Integer unless we are explicit in our intent of what we want?

    //Just gotta know that using auto as a return type will skip over some of this clever compiler
    //<=> resolution
    return 0;
}
#include <iostream>
#include "Square.h"

bool isALargerThanB(Square A, Square B){
    return A.ComputeSurfaceArea() > B.ComputeSurfaceArea();
}

bool isALargerThanB(ExplicitSquare A, ExplicitSquare B){
    return A.ComputeSurfaceArea() > B.ComputeSurfaceArea();
}

int main(int argc, char **argv){

    //explicit constructors

    //Take for example the simple square class header and source...
    //      It has two constructors, a default and one with a single double input argument
    //      Alongside that is a method to return the surface area of the square (length^2)

    Square sqrA(5);
    std::cout << "The Square sqrA(5) surface size : " << sqrA.ComputeSurfaceArea() << std::endl;

    Square sqrB(2);
    std::cout << "The Square sqrB(2) surface size : " << sqrB.ComputeSurfaceArea() << std::endl;

    //now examine isALargerThanB() at the top of this file. A basic function determining if one square is larger than the other.

    std::cout << "isALargerThanB(sqrA, sqrB) result : " << isALargerThanB(sqrA, sqrB) << std::endl;

    //here is where things get interesting... 

    std::cout << "isALargerThanB(sqrA, 15.0) result : " << isALargerThanB(sqrA, 15) << std::endl;

    //The above call to isALargerThanB() expected 2 Square objects, and as such implicitly converted our literal 15.0 to a square!
    //  This was possible due to the fact Square has a constructor that takes in one input argument that the literal could easily be converted to!
    //  That is implicit initialization of a class object! This would also occur if the constructor had subsequent parameters that had default values.

    //Unfortunately this could be confusing to another programmer if they didnt know how my code worked. 
    //  ie. They think A's surface area is being compared to the double provided. After all, the compiler let them provide a double!

    //This can be prevented through use of the 'explicit' keyword in the constructor declaration. Examine the ExplicitSquare class.

    ExplicitSquare sqrC(3);
    std::cout << "The ExplicitSquare sqrC(3) surface size : " << sqrA.ComputeSurfaceArea() << std::endl;

    //This is now illegal! literal 15 is prevented from being used to initialize ExplicitSquare!
    //std::cout << "isALargerThanB(sqrC, 15.0) result : " << isALargerThanB(sqrC, 15) << std::endl;

    //in a word the explicit keyword on a constructor forces programers to explicitly create a class

    return 0;
}
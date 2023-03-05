#include <iostream>
#include "Point.h"
#include "Line.h"

double multiply(double x, double y){
    return x * y;
}

namespace No_Offset {
    double add(double x, double y){
        return x+y;
    }
}

namespace Offset {
    double add(double x, double y){
        return x+y - 10;
    }

    double multiply(double x, double y){
        //example of calling something in the global namespace if there is a function in
        //current namespace with same signature
        return ::multiply(x,y) - 10;
    }
}

namespace { //anonymous namespace
    void lonely(){
        std::cout << "So alone. Only main.cpp can call me..." << std::endl;
    }
}

namespace Level1{
    namespace Level2{
        namespace Level3{
            double centerOfTootsiePop{9};
        }
    }
}

namespace deepestLevel = Level1::Level2::Level3;

int main(int argc, char **argv){

    //  namespaces

    //  A facility in the c++ to avoid name conflicts between functions with the same signature 
    //  (preventing redefinition)

    //  look above for methods to declare namespaces for functions
    //  the two add functions have the same signature but will not cause a compiler error due to different namespaces

    //to call either function we need to supply the namespace before the call with the scope :: opperator
    std::cout << "No_Offset::add(5,6) : " << No_Offset::add(5,6) << std::endl;
    std::cout << "   Offset::add(5,6) : " << Offset::add(5,6) << std::endl;

    //Namespaces across multiple files

    //refer to Point, Line, and Cylinder headers and sources

    Geom::Point pointA(0,0), pointB(5,5);
    std::cout << "Point A : " << &pointA <<std::endl;
    std::cout << "Point B : " << &pointB <<std::endl;

    Geom::Line lineA(pointA, pointB);

    lineA.PrintInfo();

    //Default Global Namespace
    //functions and variables outside a declared namespace is said to sit in here

    //If you find yourself within a namespace that has a function with the same signature as something
    //in the default global namespace, you can use the :: scope resolution opperator with not left
    //hand argument to reference it.

    //Look at the functions multiply(), one which lives in the DGN and one which lives in the offset namespace
    //the offset multiply() calls the DGN version using '::multiply(...)'

    std::cout << "        multiply(10,2) : " << multiply(10,2) << std::endl;
    std::cout << "Offset::multiply(10,2) : " << Offset::multiply(10,2) << std::endl;


    //Built in namespaces

    //you know that std:: you add before anything remotely interesting in c++? 
    //  surprise, its a namespace named std for the standard library. Duh doy.

    //Using declarations

    //If you feel like you find yourself typing a namespace scope resolution way too much, you can use
    //the keyword 'using' to declare certains names (or all of them) active in your current document

    using Geom::Point; //this right here allows us to use the point class we made in the
    //                   the namespace Geom without writing 'Geom::' first (from this point on)

    Point pointC(40,55); //beautiful

    //if we want all of the names in a namespace available to use we can say 'using namespace XXXX;'

    using namespace Geom; 

    //now we can use anything else in there like line

    Line lineB(pointB,pointC); //easy to use, but now the names Point and Line clutter our namespace
    //if we wrote something else here with those names, or included another header that had a Line
    //and added using for its namespace, we would be in trouble making pretty ambiguous calls

    //for instance, namespace Math, has an add() which would conflict with
    //  our own definition of add above!

    //anonymous namespaces

    //so with anonymous namespaces we essentially declare a namespace but dont give it a name
    //in doing so its like locking up the functionality and throwing away the key.
    //The compiler will auto assign some name during compilation, but there is no way for us
    //to know what it is. The file we declare it in, we can call the functionality as if it wasnt
    //in any namespace.
    //But as far as other translation units, there is no way for us to use the functionality because
    //we dont have the namespace name to use with the scope resolution opperator.

    //look at method lonely() above for how to create an anonymous namespace...
    lonely();

    //nested namespaces
    
    //you can understand this. Just think in terms of scopes within scopes and use the scope resolution opperator.

    std::cout << "Nested namespaces value at center : " << Level1::Level2::Level3::centerOfTootsiePop << std::endl;

    //Namespace aliases

    //a way to declare a certain hard to reach namespace with a shortcut name, look at deepestLevel namespace
    std::cout << "Nested namespaces value at center : " << deepestLevel::centerOfTootsiePop << std::endl;

    return 0;
}
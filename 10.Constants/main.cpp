#include <iostream>
#include <iomanip>

const int val1 {33};
constexpr int val2{34};
int val3 {35}; //runtime value

constinit int ager = 88; //This is initialized at compile time
const constinit int ager1 {val1}; //const and constinit can be combined
constinit int ager2 {ager1}; // initialization with ager would lead to an error because constinit requests a const varable/ literal for initialization. Constinit does not imply const. The type can't use itself alone. It can use const constinit though.

//constinit int ager3{val3}; // Error: trying to use runtime value for initialization

int main(){
    //When should you use const?
    //Everywhere you can! Prevents you from altering data that you intend never to change.

    //The below is an issue because you can't create a const variable without initializing it.
    //const int age;
    const int age {34};
    const float height {1.67f};

    //The below creates a compiler error, cant modify a read only variable
    //age = 55;
    //height = 1.8f;

    int years {3*age}; //you can use constants as opperands in statements without a problem

    std::cout << "age : " << age << std::endl;
    std::cout << "height : " << height << std::endl;
    std::cout << "years : " << years << std::endl <<std::endl;

    //Constant Expressions!
    //constant expressions are resolved during compile time, the value is then used from binary
    //constexpr - constant that may be evaluated at compile time or runtime
    //compile time programming, introduced in c++ 11
    std::cout << std::setw(50) << std::setfill('-') << std::left << "Constant Expressions!" << std::endl;

    constexpr int eye_count {2}; //created at compile time and denoted const so it wont change

    int leg_count {2}; // Non constexpr
    //The below is a compiler error because the const expression arm count cant be deduced during compilation because
    //the leg count is not also created at compile time. It comes in during normal program flow.
    //constexpr int arm_count{leg_count}; 
    constexpr int arm_count{eye_count};

    //You can also use constant variables to initialize constexpr variables
    const int plates = 4;
    constexpr int placemats{plates};

    //checks that will through a compiler error if false
    static_assert(eye_count == 2); // maybe a library version is not included? Will need to see where I can use this
    //the above can only be used on const variables, because this check is done during compile time

    //Constinit!
    std::cout << std::setw(50) << std::endl << "Constinit!" << std::endl << std::endl;
    //Constinit is in place in part to help in avoiding problems with the order of initialization of glaobal variables outside the main function
    //constinit does not imply that the variable is const, unlike constexpr. It just implies that the compiler enforces
    //initialization at compile time

    //look above main
    //below is a compilation error
    //constinit int test = 44;

    ager = 99; // you can alter constinits during runtime

    //essentially constinit was designed to solve problems before runtime, no reason being created during main 

    return 0;
}
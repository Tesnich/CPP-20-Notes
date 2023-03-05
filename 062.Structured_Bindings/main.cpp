#include <iostream>

struct Point{ //reminder, everything in a struct is public by default
    double x, y;
};

int main(int argc, char **argv){

    //structured bindings (light introduction)

    Point point1 {4.4,5.9};

    auto [a,b] = point1; // <- A structured bind between the names a and b, and point1's members x and y (based on order)
                         // Structured binding only works with auto, can't specify type 
                         
    //on binding we can get COPIES of the member variables we can use without having to specify their scope to point1
    //essentially we are doing "double a = point1.x;"
    //ie...

    std::cout << "Binding copy a = " << a << std::endl;
    std::cout << "point1.x = " << point1.x << std::endl;
    std::cout << "Binding copy b = " << b << std::endl;
    std::cout << "point1.y = " << point1.y << std::endl;
    std::cout << ">> Changing x to 9.9 <<" <<std::endl;
    point1.x = 9.9;
    std::cout << "Binding copy a = " << a << std::endl;
    std::cout << "point1.x = " << point1.x << std::endl;

    //currently no way to make references using public bindings

    //not really new, but these binding copies could be put into a capture list for a lambda func

    auto func = [a]() {
        std::cout << "a from lambda : " << a << std::endl;
    };

    //NOTE!!!! Above is another instance where clang wont compile something that works fine in gcc on godbolt... >:/

    func();

    return 0;
}
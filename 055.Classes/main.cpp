#include <iostream>
#include <cmath>
#include <numbers> //used for a bunch of math constant values

//a simple cylinder class
class Cylinder {

    //publicly accessible structures
    public :
        //methods -> name for functions in a class
        double volume(){
            return std::numbers::pi * base_radius * base_radius * height;
        }

        void setHeight(double hVal){
            height = hVal;
        }

        void setRadius(double rVal){
            base_radius = rVal;
        }
    
    //structures only accessible by class methods (wont be able to call or modify directly from outside)
    private :
        //member variables -> data types in a class
        double base_radius {1.0}, height {1.0};

}; //classes are statements, need ; at the end

//if private or public distinguishers are not implemnted, members of a function are PRIVATE by default


int main(int argc, char **argv){

    //Classes! They are whats happening!

    //class objects
    Cylinder cylinder1;
    std::cout << "volume c1 : " << cylinder1.volume() << std::endl;

    //Illegal!
    //cylinder1.height = 10;// <- height is a private class! We can not modify it directly.

    //we also can not view private members!
    //Illegal!
    // std::cout <<"Private member base_radius : " << cylinder1.base_radius << std::endl;
    // std::cout <<"Private member height      : " << cylinder1.base_radius << std::endl;

    //use public methods to modify private members
    cylinder1.setHeight(10);
    std::cout << ">> cylinder1.setHeight(10); << " << std::endl;

    std::cout << "volume c1 : " << cylinder1.volume() << std::endl;

    cylinder1.setRadius(2);
    std::cout << ">> cylinder1.setRadius(2); << " << std::endl;

    std::cout << "volume c1 : " << cylinder1.volume() << std::endl;

    return 0;
}
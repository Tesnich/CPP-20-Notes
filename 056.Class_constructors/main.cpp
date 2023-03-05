#include <iostream>
#include <numbers>

class Cylinder {
    private :
        double m_base_radius {1.0}, m_height {1.0}; //as we have written the constructors below, these values are never used

    public :
        //default constructor (object initialized with no parameters)
        Cylinder(){
            m_base_radius = 2.0;
            m_height = 2.0;
        }

        //overload of constructor, called when the matching types are passed as arguments
        Cylinder(double rVal, double hVal){
            m_base_radius = rVal;
            m_height = hVal;
        }

        double volume(){
            return std::numbers::pi * m_base_radius * m_base_radius * m_height;
        }

        //when members are private you can use public methods in the below to allow programmers to access them.
        //  This allows you to implement control logic, adding limits or conditions to how they can be set!

        void setHeight(double hVal){
            m_height = hVal;
        }
        double getHeight() {
            return m_height;
        }

        void setRadius(double rVal){
            m_base_radius = rVal;
        }
        double getRadius() {
            return m_base_radius;
        }
}; 

//WARNING!!!
//When you add a custom constructor to a class, the class WILL NOT create a default constructor
//If you try to call the default constructor without implementing one you will get a compiler error.

//modern c++ has a method for creation of a bare bones default constructor as below...

class Box{
    private :
        double m_width{5.0}, m_length{5.0}, m_height{5.0};

    public :
        Box() = default; //bare bones default constructor if you dont want to specify one

        Box(double wVal, double lVal, double hVal){
            m_width = wVal;
            m_length = lVal;
            m_height = hVal;
        }

        double Volume(){
            return m_width * m_length * m_height;
        }
};

//if no default constructor is defined, a default empty constructor is created that can be called ...
//      Cylinder () {};

int main(int argc, char **argv){

    //Class constructors

    //Constructors are a special method called when an instance of a class is created
    //      They have no return type
    //      They have the same name as the class
    //      They can have input parameters. They can also have no input parameters.
    //      Usually used to initialize meber variables of a class

    Cylinder cylA; //default initialized
    std::cout << "Cylinder cylA; volume : " << cylA.volume() << std::endl;
    //default constructor code setting radius and height to 2 used!

    Cylinder cylB(10,4); //calling overload of constructor we wrote
    std::cout << "Cylinder cylB(10,4); volume : " << cylB.volume() << std::endl;

    //using the Box() = default; constructor

    Box boxA;
    std::cout << "Volume of default constructed box is : " << boxA.Volume() << std::endl;

    return 0;
}

//Personal note, I was wondering what the difference between =default; and {} could be when writing a default constructor.
//      Looks like overall there isnt much difference unless you are in the weeds with things like trivial and pod classes.
//      I dont really understand right now what that means but leaving the stack overflow here to reference later.

//https://stackoverflow.com/questions/21164641/difference-between-default-and-empty-constructor-with-no-arguments
#include <iostream>
#include <cassert> //for asserts during runtime (different from static_assert we have seen)

struct PointStruct{
    double x_, y_;

    // vvvv initializer list constructor format vvvv
    PointStruct(std::initializer_list<double> list) //this is not exclusive to structures, can be done for classes too!!!
    //                                  ^- Type of items in initializer list argument
    {
        //we can use iterators to navigate the list
        // .begin() is a pointer to the first element in a list
        // .end() is a pointer to one past the last element in a list
        for (auto i = list.begin(); i != list.end(); ++i){
            std::cout << "list[" << i << "] :" << *i << std::endl; //printing
        }

        x_ = *(list.begin()+1); //not safe way to do this if we cant be sure 2 elements are always passed
        y_ = *(list.begin()); 
    }

    void PrintInfo(){
        std::cout<< "x : " << x_ << "\ny : " << y_ << std::endl;
    }
};

class AverageInitializerListAnyLength
{
    private:
        double average_{0};
    public:
        AverageInitializerListAnyLength() = delete; //disable default
        AverageInitializerListAnyLength(const AverageInitializerListAnyLength& object) = delete; //cant initialize from another instance
        AverageInitializerListAnyLength(AverageInitializerListAnyLength& object) = delete; //cant initialize from another instance
        AverageInitializerListAnyLength(std::initializer_list<double> list) //where the action is at
        {
            assert(list.size() <= 20); //If the size of list is greater than 20, throw a runtime assertion
            //assertions are opposite of if conditional, assertion thrown if condition NOT met
            //initializer list code
            unsigned int count{0};
            for(size_t i{0}; i < list.size(); ++i) //you can use .size() with lists, access value through dereferenceing iterator
            {
                std::cout << "list[" << i << "] :" << *(list.begin()+i) << std::endl; //printing
                average_ += *(list.begin()+i);
                ++count;
            }
            if (count!=0)
                average_/=count;
        }
        double average(){
            return average_;
        }
};

struct PointStruct3D{
    double x_{},y_{},z_{};
};

class PointStruct3DClass{
    double x_{},y_{},z_{};
};

class PointStruct3DClassPublic{
    public :
        double x_{},y_{},z_{};
};

int main(int argc, char **argv){

    //Initializaer list constructors

    //Method to initialize and aggregate (container of things...)

    //These agregates share the unified syntax '{1,2,3,4,...}'
    //  This is pretty familiar to me at this point

    //So far in the course we know that both arrays and structs fall under the umbrella of aggregates that accept this input

    PointStruct pointA{1.1,2.2}; //in the background the compiler auto generates a list initializer method that will accept these and initialize the vars in order

    //sometimes these wont work quite the way you want them to, for such cases you can define your own method

    //At this point I implement the initializer constructor on line 6 to swap x and y pos

    pointA.PrintInfo();
    //see they are now reversed!

    //wrote an initializer list constructor for a class average any number of arguments (doubles)
    AverageInitializerListAnyLength averageObj{1,2,3,4,5,6,7,8,9,10}; //with this initializer list method written, averageObj can take in any number of arguments
    std::cout << "averageObj.average()" << averageObj.average() << std::endl;
    
    //Probably the better way to do design this would be to write a class with a public method that takes in an initializer_list? Is that the right object? Is there just a simple list template?

    //demonstration of assert to yell during runtime if n greater than 20

    //Will throw a compile time error
    //AverageInitializerListAnyLength averageObj2{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};


    //AGREGATE INITIALIZATION ^- basically lecture about the above {...} syntax to initialize a struct and arrays 
    //                           something we already know


    //DESIGNATED INITIALIZERS ^- C++ 20 concept to specify which member variables to initialize with list initializer
    //                           new! check out PointStruct3D!

    PointStruct3D pointObject{.x_=1,.y_=2,.z_=3}; //with this you can skip elements or leave out elements
                                                  //HOWEVER! Just like writing initializer list for a class constructor,
                                                  //YOU CAN NOT REORDER THE VARS, MUST BE INITIALIZED IN CLASS ORDER!!!!

    //illegal!!!
    //PointStruct3D pointObject2{.z_=1,.x_=2,.y_=3};
    //  error: designator order for field 'PointStruct3D::x_' does not match declaration order in 'PointStruct3D'
    
    //UNIFORM INITIALIZATION FOR AGGREGATES ^-The concept that you can initialize any object through () or {}
    //  In a nutshel, () allows narrowing conversion, {} does not. 
    
    PointStruct3D pointObject2(1,2,3); //works fine with struct even without a special constructor

    //does not work well with classes because members are private!
    //PointStruct3DClass pointObject3{1,2,3}; //does not work with class, members private by default?
    //PointStruct3DClass pointObject3(1,2,3);

    PointStruct3DClassPublic pointObject3{1,2,3}; //list initialization works fine if the members are public!
    PointStruct3DClassPublic pointObject4(1,2,3); // () works too!

    //Sorta feels somewhat ambiguous...just gotta keep an eye on what is what
    
    return 0;
}
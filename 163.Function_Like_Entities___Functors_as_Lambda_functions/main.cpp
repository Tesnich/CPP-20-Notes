#include <iostream>

double MultiplyByThreeAndAdd(const double x, const double y){
    return x*3 + y*3;
}

template<typename FunctorOrFuncPointer>
double DoSomethingWithXAndY(const double x, const double y, FunctorOrFuncPointer functionality){
    return functionality(x,y);
}

double DoSomethingWithXAndY_CallBack(const double x, const double y, double (*functionality)(double x, double y)){
    return functionality(x,y);
}


int main(int argc, char **argv){

    //Functors as Lambda functions

    //so quick reminder, lambda function syntax and formating is :
    //  auto result = [] (int x, int y) {return x+y;} (7,3)

    //where the brackets are the capture list, followed by input parameters, followed by body, and optionally the
    //arguments to instantly execute said lamda function. If note executed, result is auto deduced to a function name
    //for the aforementioned lamda function.

    //side note the below is the above but with a return type specified with a trailing return type
    //                                  ______
    //  auto result = [] (int x, int y) -> int {return x+y;} (7,3)
    //                                  ^^^^^^

    //Apparently, lambda functions actually create function objects(a functor), where () is overloaded
    //with the lamda function setup. This is regardless of whether or not the lamda function is instantly
    //executed. So thats neat.

    //Knowing this extends our capabilities. In a nut shell, we should be able to provide a lambda function as
    //template arguments just as we do functors BECAUSE THEY ARE ONE IN THE SAME.

    //Using the same code as before...

    //standard library functor...
    std::plus<double> plusFunctor;
    std::cout << "DoSomethingWithXAndY(1,1,plusFunctor) : "<< DoSomethingWithXAndY(1,1,plusFunctor) << "\n";

    //function pointer ...
    std::cout << "DoSomethingWithXAndY(1,1,MultiplyByThreeAndAdd) : "<< DoSomethingWithXAndY(1,1,MultiplyByThreeAndAdd) << "\n";

    //inline lambda function...
    std::cout << "DoSomethingWithXAndY(1,1,MultiplyByThreeAndAdd) : "<< DoSomethingWithXAndY(1,1,[](double x, double y) {return x*4 + y*4;} ) << "\n";

    //Very classy! Why write an entire class functor for a peice of simple functionality when an inline lambda function works just fine
    //(well for one, you don't need to write it over and again wherever you want similar functionality)

    //You can also write lambda functions inline where a callback is manually defined

    //inline lambda function...
    std::cout << "DoSomethingWithXAndY_CallBack(1,1,MultiplyByThreeAndAdd) : "<< DoSomethingWithXAndY_CallBack(1,1,[](double x, double y) {return x*4 + y*4;} ) << "\n";

    //If keanu reaves were here he would proclaim "NICE!"

    //it may be important to note that these lamda functions can just be declared on the line above with auto, then plugged in
    //if it ends up getting a little two messy. This is really just a personal preference type thing. Sometimes
    //a long function call looks impressive I guess? lol


    //How does capturing by value work under the hood in these lamda function objects?

    double x{5}, y{10};
    //when a lambda function captures by values the above...
    //      [x,y]

    //Copies of those variables are list initialized as member variables of the function object!
    //Imagine the constructor for this lambda object does something similar to the below
    //      :x_(x), y_(y) {}

    //these captures values are CONST by default, they will not be editable

    //however, if we mark the lamda function as mutable, they can can be! 
    //      [x,y] () mutable {...}
    //(mutable identifier makes x_ and y_ member variables non-const, or mutable

    //HOWEVER THIS IS ILL ADVISED, since most people will assume that any lambda function's captured values will be persistant across runs...


    
    //Now, by no stretch of imagination we can figure out how capturing by reference works
    //similarly
    //      [&x,&y] () {...}
    //just initializes reference member variables or pointers...
    //      :x_(x), y_(y) {}
    //the above is most likely the same, but x_ and y_ are refs to double (ie. double &x_;)
    //ofcourse, these are mutable by default :P


    return 0;
}
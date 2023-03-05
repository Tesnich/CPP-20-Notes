#include <iostream>

//auto template
auto autoMax (auto a, auto b) //way simpler in its design over templates
{                             //actually generates a function template behind the scenes
    return (a>b)? a : b;      //NOTE: a and b need to be same type here, essentially doing '<typename T> T autoMax(T a, T b){...}'
}

int main(int argc, char **argv){

    //Auto function templates... for the modern person who hates code readability on the go!

    auto result = autoMax(1,9); //what are types, never heard of them

    std::cout << "Result of autoMax is : " << result << std::endl;

    //This can be combined with our lecture about lambda functions

    //below is the creation of a lamba template

    auto func = [](auto a, auto b){
        return a + b;
    };

    std::cout << "result of lambda func(10,5) is : "<< func(10,5) << std::endl;

    //this being said, we can actually create lambda functions with normal templates too, albeit slightly different syntax
    //wow...

    auto func2 = []<typename T, typename P> (T a, P b){ //return type isn't given here? I guess it is using return type deduction?
        return a + b;
    };

    std::cout << "result of lambda func2(10,5) is : "<< func2(10,5) << std::endl;

    auto func3 = []<typename T, typename P> (T a, P b)-> double { //lets see if I can define return type
        return a + b;                                             //remember that this has to be done with trailing return type when writing lambda functions
    };

    std::cout << "result of lambda func3(10,5) is : "<< func3(11.5,5) << std::endl; //yes I can


    return 0;
}
#include <iostream>

//Defining your own concept
template <typename T>
concept MyIntegral = std::is_integral_v<T>; //need to use type traits for this!
//      ^^^^^^^^^^ concept name

//Defining a concept that supports multiplication between multiple types
template <typename T>
concept Multipliable = requires (T a, T b){
    a * b; //as long as the statement here is buildable between types a and b the template should succeed!
};         //I think this would have given an error in a template taking these parameters and trying the same opperation though...

//Defining a concept that ensures T is incrementable
template <typename T>
concept Incrementable = requires (T a){
    a+=1;
    ++a;        //as long as these opperations are acceptable for the data type passes in, compilation will be accepted!
    a++;
};

//using the concepts we built above in a template
template <typename T>
requires Incrementable<T>
T addValue(T a) {
    return a + a;
}

template <typename T, typename P>
//requires (Multipliable<T> && Multipliable<P>)
decltype(auto) multiplyValues(T a, P b){
    return a * b;
}

int main(int argc, char **argv){

    std::cout << "addValue(10) : " << addValue(10) << std::endl;

    std::cout << "addValue(10.1) : " << addValue(10.1) << std::endl;

    bool test = true;
    //std::cout << "addValue(true) : " << addValue(std::string{"Hello"}) << std::endl; //this doesnt fail... X   X
    std::cout << "addValue(true) : " << addValue(test) << std::endl; //this doesnt fail... X   X

    //NOTES!!!!!!! So, this method above should not be able to pass in a bool thanks to the incrementing code I put int the concept the template requires.
    //               (++a). When I pass in the commented out string above instead, the compiler WILL fail and cite the concept's incrementing
    //               as the reason, even though the addValue body could easily handle strings. Works as should that way!
    //
    //               Sooooooooo.... I decided to play with godbolt. At the time of writing I am compiling my projects with apple clang 13.something
    //               I put this code in godbolt and ran with latest compiler for clang, 15. It builds there too. using -std=c++20
    //
    //               BUT, if I select the latest GCC build instead. Blmao! It fails and cites reason as failure for bool not being incrementable.
    //
    //               In conclusion, not my fault. Someone needs to fix clang. :P

    return 0;
}
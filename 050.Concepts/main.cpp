#include <iostream>

//using static assert to limit types provided to template
template <typename T>
T maximum(T a, T b)
{
    static_assert(std::is_integral_v<T>, "The type passed into maximum was not integral!");
    return (a > b)? a : b;
}

//using c++ 20 'concepts' to limit types provided to templates
template <typename T>
requires std::integral<T> //Concepts clause syntax
//requires std::is_integral_v<T>  // <--  You may also use the older type traits format with the requires keyword
T maximumConcepts(T a, T b)       //      as seen here
{
    return (a > b)? a : b;
}

//2nd syntax to enforce type directly in template type parameters block
template <std::integral T>      //  instead of listing T as typename you can specify the type directly
T maximumConcepts2(T a, T b)
{
    return (a > b)? a : b;
}

//3rd syntax to use concepts with the simpler auto version of templates
auto maximumConcepts3(std::integral auto a, std::integral auto b){
    return (a > b)? a : b;
}

//4th syntax (really just the 1st shuffled around to set type after method input parameters)
template <typename T>
T maximumConcepts4(T a, T b) requires std::integral<T>
{
    return (a > b)? a : b;
}

//if you need to make sure that two or more concept types are allowed as input use OR
//ie....
template <typename T>
requires (std::integral<T> || std::floating_point<T>) //this is valid syntax
//by using the below you would also get all fundamental types (integrals, floats, doubles...etc)!
//requires std::convertible_to<T,double>    //explore all concepts to see different use cases!
T maximumConcepts5(T a, T b)                //https://en.cppreference.com/w/cpp/concepts 
{
    return (a > b)? a : b;
}

int main(int argc, char **argv){

    //Concepts ... mechanism in c++ 20 to place constraints on function template types!

    //There are concepts included in the standard c++ library (below), but you can also create your own!

    //  same_as
    //  derived_from,
    //  convertible_to,
    //  common_reference_with,
    //  common_with,
    //  integral,
    //  signed_integral,
    //  unsigned_integral,
    //  floating_point ................plus more online

    //OLD Method for Limiting Types In Templates ////////////////////////////////////////////////////////////////

    //maximum is designed to only take integers with a static assert that will kill compilation

    //Fails with double
    //maximum(10.1,12.0);

    //Passes with int
    maximum(10,12);

    //NEW Concepts Method ////////////////////////////////////////////////////////////////

    //ide can actually tell you this will fail before moving onto the compiling phase
    //maximumConcepts(10.1, 12.0);

    //Works with int!
    maximumConcepts(10, 12);

    //different syntax for concepts setup

    //maximumConcepts2(10.1, 12.0);
    maximumConcepts2(10, 12);

    //maximumConcepts3(10.1, 12.0);
    maximumConcepts3(10, 12);

    //maximumConcepts4(10.1, 12.0);
    maximumConcepts4(10, 12);

    maximumConcepts5(10.1, 12.0);
    maximumConcepts5(10, 12);

    return 0;
}
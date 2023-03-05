#ifndef FUNCTIONS
#define FUNCTIONS

//which type to use for return argument when types dont match??
//                                  V
//template <typename T, typename P> P problematic_maximum (T a, P b)

//placing in either T or P will mean that the return type for this method will be based on the order the arguments are passed in
//the compiler will create two definitions if the template is called both ways!

//called with int and double it will return double! called with double and int it will return int!

//we can solve this by defintion of another typename just for the returning type (in this case called ReturnType)

template <typename ReturnType, typename T, typename P> ReturnType problematicMaximum (T a, P b)
{ //        ^^^ unlike in CPP variable declaration this needs 'typename' before each name
    return (a > b) ? a : b;
} //DOES NOT return based on which type is larger here

// what type is used for the return type is determined when the function is called! Look in main.cpp for example!

template <typename T> T divideNums (T a, T b)
{
    return a/b;
}

//You can also have a template where auto is used as a return type in a template, sorta like a function.
//In these cases auto will use the largest type from those provided. That is gross and super hard to read, don't do it unless you want to hate yourself and co-workers.

template <typename A, typename B> auto confusingDivideNums (A a, B b) //THIS IS GROSS
{
    return a/b; //programmer implementing call will need to deduce whatever the return type is based on what they pass
}               //they wont even be able to manually specify the return type like in the above templates...dont do this

#endif
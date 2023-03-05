#include<iostream>
#include<string>

int main(int argc, char **argv){

    //COMPILES
    for (size_t i = 0; i < argc; ++i){
        std::cout << std::string(i, 'X') << std::endl;
    }

    //DOES NOT COMPILE
    for (size_t i = 0; i < argc; ++i){
        std::cout << std::string{i, 'X'} << std::endl;
    }

    //So there is a little more below the hood with {} vs () initialization 

    //This link from kevin sums it up well, https://discord.com/channels/@me/294987715554836480/1050903378781290567

    //  I thought all that using {} curly braces over () meant was that the input type would be
    //  checked against what it was going into, and fail the compile if there was data loss. ie..
    //  fractional into int. However, it looks like {} will prefer constructors with list initilzers
    //  as an input! This is bassically pushing me into (8) under c++ 11 on this page...
    //  https://cplusplus.com/reference/string/string/string/ 

    //  Some good rules boil down to as follows...

    //  if the arguments you pass in can be strictly construed as what will be stored in the "container" you make, aka string
    //  use the {} curly
    //  but if it has some strange syntax that does not illustrate what you would see in that container
    //  ie... (5,'-')
    //  then use standard function call()

    return 0;
}
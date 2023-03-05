#include <iostream>
#include <iomanip>

//using 'new name' = 'type to create an alias to'
using HugeInt = unsigned long long int; //new modern 'using' type alias method

typedef unsigned long long int HugeInt2; //old 'typedef' type alias method

void acceptReal(unsigned long long int input);
void acceptUsing(HugeInt input);
void acceptTypedef(HugeInt2 input);

int main(){

    //Type aliases!!

    unsigned long long int hugeNum{18'446'744'073'709'551ull};
    //The above is super long to type! Do we really want to keep writing that behemoth everywhere? ISNT THERE A BETTER WAY?!

    //Billy Maze here with the the brand new type alias construct!

    //line #5
    HugeInt hugeInt {18'446'744'073'709'551ull};
    //^^^^^ Wow, so short!

    //old c++ also had a way of doing this....
    //line #7
    HugeInt2 hugeInt2{18'446'744'073'709'551ull}; //basically does the same thing.

    //Use the new version because it is modern c++, but expect to see the typdef version used in the field

    //THE GAUNTLET OF COMPATIBILITY
    std::cout << std::endl << std::setw(50) << std::setfill('-') << "real" << std::setfill(' ') << std::endl;
    acceptReal(hugeNum);
    acceptUsing(hugeNum);
    acceptTypedef(hugeNum);

    std::cout << std::endl << std::setw(50) << std::setfill('-') << "using" << std::setfill(' ') << std::endl;
    acceptReal(hugeInt);
    acceptUsing(hugeInt);
    acceptTypedef(hugeInt);

    std::cout << std::endl << std::setw(50) << std::setfill('-') << "typedef" << std::setfill(' ') << std::endl;
    acceptReal(hugeInt2);
    acceptUsing(hugeInt2);
    acceptTypedef(hugeInt2);

    //So yeah with a type alias there come no restriction on input with variables also using that same type alias

    //if under the hood it all comes back to the same type, 'unsigned long long int' here, it will be accepted

    return 0;
}

void acceptReal(unsigned long long int input)
{
    std::cout << "acceptReal() ran!" << std::endl;
}

void acceptUsing(HugeInt input)
{
    std::cout << "acceptUsing() ran!" << std::endl;
}

void acceptTypedef(HugeInt2 input)
{
    std::cout << "acceptTypedef() ran!" << std::endl;

}
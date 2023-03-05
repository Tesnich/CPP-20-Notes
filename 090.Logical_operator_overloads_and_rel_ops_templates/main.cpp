#include <iostream>
#include "Wrapper.h"
#include "WrapperBetter.h"
#include <utility> //needed for rel_ops

int main(int argc, char **argv){

    //Logical Operator Overloads ( old and c++ 20 versions) and the C++ 20 Three Way Comparison

    // ==, !=, >, >=, <, <=, ==, !=


    //Overloading all logical operators (old method we've seen before)
    //check out the wrapper class

    Wrapper<int> intWrapper(5);
    std::cout << "intWrapper    " << &intWrapper <<" : " << intWrapper << "\n" ;
    std::cout << "intWrapper +5 : " << intWrapper + 5 << "\n";
    std::cout << "intWrapper    " << &intWrapper <<" : " << intWrapper << "\n" ;
    (intWrapper += 5) += 2;
    std::cout << ">> (intWrapper += 5) += 2; <<\n";
    std::cout << "intWrapper    " << &intWrapper <<" : " << intWrapper << "\n" ;

    Wrapper<int> intWrapper2(12);
    std::cout << "intWrapper2   " << &intWrapper2 <<" : " << intWrapper2 << "\n" ;
    std::cout << "(intWrapper < intWrapper2)  : " << (intWrapper < intWrapper2) << "\n";
    std::cout << "(intWrapper <= intWrapper2) : " << (intWrapper <= intWrapper2) << "\n";
    std::cout << "1 < 2 :" << (1 < 2) << "\n"; //parenthesis needed here, otherwise this is << action on int which can't be parsed

    //non-member == overload 

    std::cout << "(intWrapper == intWrapper2) : " << (intWrapper == intWrapper2) << "\n";
    std::cout << "(intWrapper == Wrapper<int>(1)) : " << (intWrapper == Wrapper<int>(1)) << "\n";

    //another method <<std::rel_ops namespace>>
    //NOTE:: while nice, this method deprecated in favor of of C++ 20's <=> opperator

    //in need of all logical operators for your data type? With rel ops there is a method that
    //requires you to only overload 2 of them (< and ==) and let the compiler derive implementations of the rest!

    //  more info...
    //  https://en.cppreference.com/w/cpp/utility/rel_ops/operator_cmp

    //look at WrapperBetter, it is the same as Wrapper but only implements the < and == operator overloads
    //the other overloads appear just by adding the below line
    using namespace std::rel_ops;
    
    //rel_ops has template function overloads for !=, <=, >, and >=
    //When we call !=, for instance, the compiler checks for an implementation we have written first.
    //If none exist, it tries to find a match among these templates. The templates build correctly
    //if they are able to call overloads we have written for < and == on the class types being compared
    //Each template for the above opperators gets its result from clever negation of the < and ==
    //overloads we wrote.

    //Reading the documentation, it looks like rel ops is only good for generation of overloads on
    //comparisons between two classes of the same type

    //ie... the template shares T between the first and second opperand
    //
    //      template< class T >
    //      bool operator!=( const T& lhs, const T& rhs );
    //

    //in calling != below for WrapperBetter, we are really calling on that template in the rel_ops namespace

    WrapperBetter<int> wrapperBetterA(3), wrapperBetterB(4);

    std::cout <<"(wrapperBetterA > wrapperBetterB) "<< (wrapperBetterA > wrapperBetterB) << "\n";
    std::cout <<"(wrapperBetterB > wrapperBetterA) "<< (wrapperBetterB > wrapperBetterA) << "\n";
    std::cout <<"(wrapperBetterA != wrapperBetterB) "<< (wrapperBetterA != wrapperBetterB) << "\n";

    //there is another lecture right after this on implicit conversions into these operators
    //if you want that, then you need to implement these logical operators as free standing
    //non member functions and also provide conversions from data types into wrapper type
    //(constructor works fine)-> I find this troublesome, let the user explicity construct the objects
    //might go as far as to make constructor explicit so as to not allow implicit construction

    //look back at maybe dir 86 if you want to know more

    return 0;
}
#include <iostream>
#include "Number.h"
#include "Point.h"

//demonstration of implicit conversion prevented because of explicit keyword
void InputDouble(double dblVar){
    std::cout<< "Double is :" << dblVar << std::endl;
}

int main(int argc, char **argv){

    //Custom type conversions

    //say you have an int and provide it a double
    //  int intVar(dblVar); 
    //in this situation an implict conversion takes place to turn the double into a value that can
    //be stored in the int data class.

    //These conversions can be written for custom class objects using overloads

    //check out Number.h and Number.cpp which defines the Number class as a simple wrapper for an int
    Number numA(32);
    double dblA(numA); //from the terminal you can see our conversion was called!

    //Illegal
    //InputDouble(numA); //implicit conversion prevented

    //to get the above to work all you would need to do is drop the 'explicit' keyword in the
    //conversion overload declaration.

    //or ofcourse make use of the explicit conversion we just defined
    InputDouble(static_cast<double>(numA));
    //from the terminal you can see our conversion was called!


    //issues with member function implementation of conversions

    //watching this lecture, the thought process is a little weird
    //they have something similar to the below...
    //
    //std::cout << "5.0 + numA : " << (5.0 + numA) <<std::endl;
    //
    //and complain that it doesnt compile, and that they expect 5.0 to be converted to a Number
    //and then have a overloaded opperator+ for the Number class kick in

    //That seems...like not a problem to me? So I removed the explict keyword for Numbers conversion
    //to double

    //when ran, this works EXACTLY as I expect it to. The numA is converted to the double type.
    //Who on earth is going to look at that statement and expect 5.0 to be converted to a Number object
    //Thats like total nonsense to me and flys in the face of what you'd expect when trying to read
    //someone else' code. 

    //      Retroactive note,  I read that as a general rule lhs opperands are never implicitly
    //      Revisited concept  converted (either by construction or conversion overload) if the opperator
    //      the next day...    used (think operator+) is implemented as a member function.
    //                         Below the left hand opperand is an int, however, final result is a double.
    //      May be some        This must mean that operator+ is implemented something like...
    //      rehashing here...       double opperator+ (const double& a, const double& b); ?
    //                         In doing so, the compiler is able to identify that when adding a double,
    //                         either on the left or right, to any other class that can be implicitly
    //                         converted to a double, it should be converted.
            auto result = int{22} + double{0.5};
            std::cout << "result : " << result << std::endl;
            std::cout << "int{22} + double{0.5} " << int{22} + double{0.5} << std::endl;
    //                         This isn't SUPER clear to me, but I think I have the gist of the sitch
    //                         now. It also means that by implementing my binary operator+ in point.h
    //                         I can add an int then instance of Number class, int gets converted to
    //                         Number through implict construction, and they are both added to create
    //                         a point class. 
            auto object2 = int{1} + Number(2);
    //                         The bit that confuses me is why this now doesnt happen if you add two
    //                         ints...
            auto object3 = int{3} + int{4};
    //                          My best guess is that inorder to call a binary opperator overload,
    //                          written like I have in point.h, AT LEAST ONE ARGUMENT MUST MATCH
    //                          ONE OF THE PARAMETERS. A good question would be what would happen
    //                          if there was another binary opperator overload written with the other
    //                          type. (ie (const int& a, const int& b)). Ambiguity?

    //I would probably go as far as to label the constructor for the Number class explict if it took
    //a double as an argument so this WOULDN'T happen.

    //This being said, they actually create a series of binary input overloads for the - operator to
    //do exactly this...

    //declared in Number.h
    //
    //  friend Number operator-(const Number& left_operand, const Number& right_operand);
    //
    //This...to me...feels bonkers. For some reason, this turns calling the above (with -) into
    //a monstrosity. This new non-member function has precidence over turning the number into a
    //double.

    //In my mind its a little difficult to imediately find where the line is drawn. What if I add
    //two doubles, yeah? Because technically that fits the bill right? Implicitly convert both
    //LHS and RHS into Numbers? Maybe there is something I am missing...
    //It could be that the compiler doesnt even look for binary overloading operators unless at least one
    //argument, either left or right, meets the criteria? 

    //Still, this is totally gross. You'd have to be extrememly aware of the fact that if you used
    //any operator between a particular custom class and a standard type it would result in the
    //implicit construction of a whole new Number object. 

    //This leaves me wondering...what if I crafted a new class, called point, then implemented
    //a custom operator+ completely outside of number, that when two numbers are added together
    //creates and returns a new point object. Looking at the code of number you would not
    //expect them to be addable at all, let alone create a new class all together.

    //I gotta try this.

    auto object = Number(5) + Number(10);

    //ok, so on including my new Point header I start getting ambiguous calls
    //first being the addition between '5.0 + numA'. It is fighting between my new
    //+ overload and implict conversion to double then addition. 

    //Changing conversion in number back to explicit
    //in doing so i have to change my Point.h + overload to explicitly convert to double
    //and comment out << for the '5.0 + numA' line since I have not overloaded the output stream opperator for point

    //and it works...wow

    //this is so dirty...

    //I suppose there isn't a really big risk to impact in functionality because the instant you
    //include that header file for Point.h and try to compile you would get an ambiguous call
    //error wherever the user was previously trying to add two Numbers classes

    //which they totally could be doing already if they were banking on an implicit conversion to double to kick in
    //but what if a different compiler doesnt catch that and just picks one. Can that happen?

    //if so, and it chooses the new point one, you'd get a compiler error the instant you tried to use
    //the result of the addition as a double. 

    //However if you were just putting it in an output stream, and I had written an << overload for point, 
    //theoretically it would just work...changing functionality for an area in code simply by including
    //a new header file

    //wacky

    //I think this really comes down to placement... if this is placed in the Numbers.h file at least
    //programmers can see its possible

    //The fact that numbers.h nor the associated .cpp have to include the +overload is the tripping point.

    return 0;
}
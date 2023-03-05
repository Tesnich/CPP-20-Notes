#include <iostream>
#include "Circle.h"

int main(int argc, char **argv){

    //Overriding, overloading, and function hiding


    //First what is overriding? That's what we have been doing the past few lectures by
    //labeling base class methods 'virtual' and re-implementing those functions on child
    //classes.

    //'override' specification - use of the override keyword severs as a que to the compiler
    //that a method we have implemented in our derived class is supposed to override a virtual
    //function in the base class.

    //      void someFunc(...) override; <- derived declaration
    //      void someFunc(...) override {...} <- definition only

    //Without this, if you create a typo in your dervied class when trying to implement a virtual
    //function you will end up with something that never gets called from the base class. 

    //ie... Draw() vs draw(). There wont be a compiler error because there is no mandate to implement
    //any virtual functions in a child class, thus your expectations when working with the idea of
    //polymorphism in mind will not be met.

    //This has no functional application other than preventing you from making this mistake. It is
    //recommended to do this any time you wish to override a virtual function

    //check out Oval and Circle for implementation...



    //overloading and function hiding,

    //if a base class implements multiple virtual overloads of the same function, all of those
    //functions are by default callable from derived classes. However, if a derived class overrides
    //even one of these functions the rest are hidden. 

    //Look in Shape.h . I have added an overload for DrawShape with a string_view input. Does, nothing
    //but calls DrawShape prime. But since Circle and oval implement an override of the DrawShape(),
    //DrawShape(string_view is now hidden).
    Shape shape{};
    shape.DrawShape();
    shape.DrawShape("nonsense");

    Oval oval(5, 10);
    oval.DrawShape();
    //oval.DrawShape("nonsense");
    //  error: no matching function for call to 'Circle::DrawShape(const char [9])'

    //If you want to override one virtual function and use its overloads as well, you must override them all.
    //This is carried over to subsequent child classes. If circle had no override of DrawShape(), it would
    //only be able to see oval's DrawShape();

    //NOTE!!! The eclipsing of base overrides ocurr EVEN WHEN IT ISNT A VIRTUAL FUNCTION!! If you override
    //non virtual inherited functions, all of the overloads on the base class dissapear from the perspective of
    //the derived class and outside scope. No way to access them without a pointer to the base class or
    //by use of scope resolution opperator to specify Shape::

//      TANGENT!
//      Weird happenings with below actually... I have this set up in such a way that the overload with sv
//      is calling the overload without input arguments. In doing this, it actually ends up calling the
//      ovrriden version in oval. That is bonkers at first, but in terms of the big picture makes sense.
//      The object does have a valid override for the method in the wings... 

//      We can get by this however by cutting out polymorphism and calling out the base class components
//      of our objects.

    oval.Shape::DrawShape("jdslkfjlsd"); //This works, but the point of polymorphism is to execute
    //code overriden by derived classes. If this is what you intend on doing, this should simply
    //be a public non virtual method....
        
//      This should really be kept in mind if you intend to call any virtual functions within your own
//      class as they may return something incredibly different based on derived overloads. If you want
//      to avoid that then maybe you can specify scope using 'Base::' in the call. I'm going to try...

//      Yes! This is exactly the case. Based on how you want to re-use functionality you could write it
//      using Base:: or leave it out to call override. This is an incredibly versatile mechanic!

    //Note: Don't confuse the above for a need to override all virtual functions. This is only for
    //overloads... ie functions with the same name.




    //Heritance & polymorphism can work in trees

    /*
    
    Animal - Virtual Func Breath()
     |
     |--------------------------------------|
     |                                      |
    Bird - Virtual Func Fly()               Feline - Virtual Func Claw()
     |                                      |
     |----------|                           |-----------|
     Piegon     Sparrow                     Cat         Couger

     ^
     Multiple branches of polymorphism can be supported.

     All the animals can breath, but only children of birds can fly. Only felines can claw.
    
    */

    return 0;
}
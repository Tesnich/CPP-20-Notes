#include <iostream>
#include "ConstructorWatch.h"
#include "Utilites.h"

// template<typename ValueType>
// ConstructorWatch<ValueType> GenerateConstructorWatch(unsigned int i);

int main(int argc, char **argv){

    //Move Semantics

    //Moving the data associated with a temporary object to another (returned) in order to
    //avoid an uneccessary copy of said object

    //A good example given is that in our BoxContainer class the overloaded + operator would
    //create a temporary object for which boxes A and B would be +='ed into.
    //This temporary object would then be returned, and if the compiler isn't clever enough,
    //would make our newly created object in the outer scope using a copy constructor with
    //the temporary object as input.

    //By declaring this last step a move, however, we can tell the compiler that we want our
    //new object to gain control of all the temp's internals instead of crafting a new one
    //using a copt constructor.

    //Lvalues and Rvalues

    //Lvalues - are things that you can grab an address for and de-reference later and use.
    //          ie z int 'int z{x+y};'

    //Rvalues - are transient or temporary objects that only exist for a short time. These
    //          are quickly destroyed by the system when no longer needed.
    //          ie result of x+y in 'int z{x+y};'

    //If you try to get the address of Rvalues you will get a compiler error.

    int x{5}, y{6};
    //compiler error... error: lvalue required as unary '&' operand
    //int * ptr1 {&(x+y)};

    //literals are also considered rValues

    //compiler error... error: lvalue required as unary '&' operand
    //int * ptr2{&45};

    //same goes if we try to store in const, the idea is the literal will expire in short order
    //compiler error...
    //const int * ptr2{&45};

    //When += is used however, the address of the original object is returned
    //since that is an Lvalue we have no issues capturing it!

    int * addressX{&(x+=y)};
    std::cout << * addressX << "\n";

    //rValue references

    //When an rValue reference is bound to an rValue, the life of the rValue is extended
    //Essentially the rValue is given the scope and lifetime of the reference we create to capture it

//     __
    int&& rValRef = x+y;
//     ^^

    //With the above syntax we have created an rValue reference to the int type. rValRef is not
    //a copy constructed int from the rValue result x+y. It IS the result of x+y, given permanence
    //through alias 'rValRef'.

    //IMPORTANT, although the type is 'int&&' rValue reference, for all subsequent uses of this
    //'rValRef' variable, the system will see it as an lValue. Methods that take in int&&, will
    //actually see this as a normal int and hence the method wont be called. (need std::move() on top
    //to call methods of rValue reference)
    
    //If we remember correctly, writing custom std::move constructors before was done through
    //constructor with &&... now we get to see why this is the case. In situations where we need
    //to steal objects from a temporary variable is is absolutely necessary to extend their life
    //while doing so.

    //You see down below in an example where '= std::move(...);' is used. The move call
    //returns us an rValue reference! With that as an argument to the = operator, it makes
    //perfect sense how we overload the = operator for a rValue reference of the class!
    //
    //And with the rValue reference to the temporary object, the temp object now exists as a 
    //fully interactable lValue. Stealing its data becomes the trivial process of simply
    //accessing the object.

    //IMPORTANT TAKE AWAY : std::move() returns an rValue reference, but it doesnt actualy MOVE anything.

    //examine ConstructorWatch.h
    
    Util::PrintTitleLine("Initial Array Creation");
    ConstructorWatch<int> constructorWatchArray[5]{};

    //example highlighting waste of copying values in stored ValueType's
    Util::PrintTitleLine("Wastefull copy assignment of ValueType to ValueType", 2);
    for(size_t i{}; i < std::size(constructorWatchArray); ++i){
        constructorWatchArray[i] = ConstructorWatch<int>(i);
    }

    //example highlighting how move can steal the pointer to the temp objects ValueType
    //instead of creating a copy
    Util::PrintTitleLine("Proper movement of temporary objects ptr to values", 2);
    for(size_t i{}; i < std::size(constructorWatchArray); ++i){
        constructorWatchArray[i] = std::move(ConstructorWatch<int>(i));
    }
    Util::PrintEndLine();

    return 0;
}

//note: move only types are just classes with the copy and assignment constructors deleted
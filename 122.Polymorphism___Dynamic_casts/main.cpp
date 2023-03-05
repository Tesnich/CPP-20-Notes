#include <iostream>
#include "Derived.h"

int main(int argc, char **argv){

    //Dynamic Casts

    //Dynamic casting refers to transforming from base class pointer or reference to derived class pointer or reference
    //in cases where polymorphism is implemented.

    //This makes it possible to call non polymorphic methods on derived objects
    //(calls in perspective of most derived class not implemented in base)

    //Before, when wanted to explicity convert from on type to another, we would use static casts
    //  static_cast<double>(intVar);
    //Static casts are for classes that do not implement polymorphic pointers to derived classes
    //(what putting virtual on a method does)

    //We can use the 'dynamic_cast' function template to convert these objects for us instead!
    //This is most useful when trying to get to a further derived class in an object, as a simple
    //scope resolution operator is sufficient if you need to reach base classes.

    //Observe...

    Derived derived{};
    derived.DerivedOnlyFunction();

    Base* ptrBase{&derived};
    //Inaccessible call from base
    //ptrBase->DerivedOnlyFunction();

    //convert back

    Derived* ptrDerived{dynamic_cast<Derived*>(ptrBase)}; //to use this, at least one member of your class
                                                          //must support polymorphism, meaning one member is labeled
                                                          //virtual! In our case it is ~Base(); Otherwise we could
                                                          //use static cast.

    //This cast can fail if there is no associated Derived ptr, so check for nullptr
    if(ptrDerived){
        ptrDerived->DerivedOnlyFunction();
    } else {
        std::cout << "Cast Failed!\n";
    }

    //the same dynamic cast can be performed on references...
    Base& baseRef{derived};
    //Inaccessible call from base
    //baseRef.DerivedOnlyFunction();

    Derived& derivedRef{dynamic_cast<Derived&>(baseRef)};
    //there is no check that can be performed for ref like pointers,
    //if you want to check cast it to a pointer first
    ptrDerived = nullptr;
    ptrDerived = dynamic_cast<Derived*>(&derivedRef);
    if(ptrDerived){
        derivedRef.DerivedOnlyFunction();
    } else {
        std::cout << "Cast Failed!\n";
    }


    //FYI, using "down casting" as the above is called, is a symptom of bad design. If you find yourself calling
    //a lot of these it could be a hint that you should probably implement said method and make it polymorphic 
    //from the base class.

    return 0;
}
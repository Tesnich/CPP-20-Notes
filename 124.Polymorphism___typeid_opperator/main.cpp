#include <iostream>
#include <memory>
#include "Derived.h"
#include "NonPolyDerived.h"

int main(int argc, char **argv){

    //The typeid() opperator

    //This is an opperator we can use on a Base* or Base& to query what the most derived object it is pointing to
    //We can only use this on base classes that implement polymorphism (aka use virtual at least once)
    //If it is used on a on a non-polymorphic type it is just going to return the base class which you already know

    std::unique_ptr<Base> ptrBase{std::make_unique<Derived>()};
    std::cout<<std::boolalpha;
    //                                                             ________Working with pointers, don't forget to de-reference! Otherwise you are comparing the types of
    std::cout<<"(typeid(ptrBase) == typeid(Derived)) : "<< (typeid(*ptrBase) == typeid(Derived) ) <<"\n"; // a smart pointer and Derived
    //comes back true!

    std::unique_ptr<NonPolyBase> ptrNonPolyBase{std::make_unique<NonPolyDerived>()};
    //                                                                           _______________Working with pointers, don't forget to de-reference!
    std::cout<<"(typeid(ptrNonPolyBase) == typeid(NonPolyDerived)) : "<< (typeid(*ptrNonPolyBase) == typeid(NonPolyDerived) ) <<"\n";
    //returns false because typeid() can't traverse up a non-polymorphic class like NonPolyBase
    //that does not have a hidden pointer to the derived class after it...
    //thus the answer is wrong, make sure you use typeid with polymorphic classes only

    //We can also use typeid() to return the name of the type in question using the member function 'name()'
    std::cout<<"typeid(*ptrBase).name() : " << typeid(*ptrBase).name() << "\n";
    std::cout<<"typeid(*ptrNonPolyBase).name() : " << typeid(*ptrNonPolyBase).name() << "\n";
    //The above seems to dump some strange numbers infront of the class name... not sure why.

    //The typeid also works with references
    Base& refBase{*ptrBase};
    std::cout << "typeid(refBase).name() : " << typeid(refBase).name() << "\n";

    return 0;
}
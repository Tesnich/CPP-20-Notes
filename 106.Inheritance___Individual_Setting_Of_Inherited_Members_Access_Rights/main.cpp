#include <iostream>
#include "DerivedPrivate.h"
#include "DerivedPublic.h"

int main(int argc, char **argv){

    //Individual declaration of inherited members' access rights

    //NOTE: BELOW WORKS FOR ANY MEMBERS (variables AND methods)

    //C++ allows you the ability to declare individual base class members with the access rights
    //you want. All you have to do is declare you are 'using' the member variable of that class
    //within the access rights block of your choosing.
    //
    //      using Base::basePublicInt_;
    //
    //It is important to note though, that you can never give a base member variable more access
    //than that it had in the base class. AKA, if it was originally a private member variable,
    //it will forever be a private member variable.

    //Declaring that you are using a base member (variable or method) with certain rights will supersede
    //base class specifier setting. 

    //Please examine the changes in DerivedPrivate.h to see how it uses private inheritance
    //but make basePublicInt_ still accessible publicly...

    DerivedPrivate derivedPrivate{};
    std::cout << "derivedPrivate.basePublicInt_ : " << derivedPrivate.basePublicInt_ << "\n";
    //^^^^^^ We were able to access basePublicInt_ as if it were a public member var
    //       of derivedPrivate despite derivedPrivate using private inheritance!

    //Just so this is clear, this reclasification process applies to members of any type, including 
    //methods! 'using Base::SimpleBaseClassFunction();

    derivedPrivate.SimpleBaseClassFunction();

    //My guess is that this can also be applied to hide a base member var. Examine derivedPublic.h ...
    
    DerivedPublic derivedPublic{};
    //std::cout << "derivedPublic.basePublicInt_ : " << derivedPublic.basePublicInt_ << "\n";
    //^^^^^^^^^^^^^^^^^^^^^^^^COMPILATION ERROR^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    //Correct! I was able to successfuly make the basePublicInt_ a private member of derivedPublic
    //even though it implements public inheritance.

    //This could be useful if you wish to create a more restrictive implementation of a class
    //by not allowing others to access all of its features. This in combination with re-writing
    //public functions (derived class' functions have precedence over base's) could work extremely 
    //well!

    return 0;
}
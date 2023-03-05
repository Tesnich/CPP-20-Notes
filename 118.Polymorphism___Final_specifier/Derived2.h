#ifndef DERIVED_2_H
#define DERIVED_2_H
#include "Derived.h"

//    final MUST go after class definition, does not work in any other order
//    use of the final specifier here says that Derived2 is a final class, no other can inherit from it
//    ______________
class Derived2 final : public Derived
//    ______________
{
    public:
        Derived2() = default;

//      Because of the use of final in the override of this method in Derived.h, the derived2 class
//      inheriting from it is unable to create its own override (use of override does not play a part in this error)
//        void PrintSomething() override {...}

        void PrintAnotherThing() override { //not marking this final, because of final in class definition there is no point
            std::cout<< "Derived2::PrintAnotherThing()\n";
        }
};


//below is an attempt to derive from Derived2...

// class Derived3 : public Derived2{
// };

//  ERROR: a 'final' class type cannot be used as a base class

#endif
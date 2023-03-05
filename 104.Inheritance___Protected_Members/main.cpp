#include <iostream>
#include "Engineer.h"

int main(int argc, char **argv){

    //Protected Members

    //  Previously, we saw that when a class publicly inherts from another with private members,
    //  the new class has no direct access to the those members.

    //  However, there is a solution! If we declare these members within a 'protected :' clause instead
    //  of 'private :', any publicly inherited class WILL have access to them!

    //  Protected members work just like private members. They can only be accessed by the same class or
    //  friends of said class. The big difference is that if a class is publicly inherits from a class
    //  with protected members, that new class can access the private members.

    //  examine UcGradute.h (accessors have been removed and members were moved under 'protected :')
    //  examine Engineer.h (protected members are being accessed directly)
    Engineer engineerA("BestEngineerIdEva005");
    std::cout << "engineerA : " << engineerA << "\n";
    //  ... but since we dont have accessors I now have nothing setting these values...
    //  ... eh, I'll make another constructor that takes in 3 arguments.

    Engineer engineerB("BestEngineerIdEva006", "James", "Hillman");
    std::cout << "engineerB : " << engineerB << "\n";

    //  NOTE: In doing this I noticed something peculiar. I am not able to list initialize
    //  the protected member vars that I inherited. This would indicate that perhaps it wasn't the code
    //  that was copied, but that an instance of UcGraduate is created and associated with every 
    //  instance of my derived class?

    //  I'm going to put a print line in the constructor to test this theory...

    //  THIS IS EXACTLY WHAT IS HAPPENING. UcGradute constructor is called for both instances of
    //  the Engineer class. Trippy and not at all what I was expecting. It now makes sense 
    //  why I was unable to read or write to the private members. It was essentially like Engineer
    //  had an instance of UcGraduate inside of it. If I were to initialize UcGraduate in any normal
    //  class as a member I would have to go through its public accessors to interact with it.

    //  The differences I see in publicly inheriting from a class as opposed to having one as a
    //  member are that I get to call its public methods without having to specify an instance,
    //  and if said class has protected members the publicly derived class has access to those
    //  where as if it simply owned an instance it would not.

    //  Let me check quick to make sure protected doesn't just open up access to whatever scope is
    //  holding it...

    UcGraduate ucGraduateA("Bob","Dylan");
    //std::cout << "ucGraduateA.firstName_" << ucGraduateA.firstName_ << "\n";

    //  Nope! Compilation fails because the member is inaccessible.
    //  It looks like protected works like private EXCEPT in context of inheritance.


    //  So here is a good one... If you inherit a protected member var from a base class, can you access it like a public
    //  method from outside the scope of the Derived class? Let's try to access firstName_ from Engineer.

    //  Illegal!
    //std::cout << "engineerB.firstName_;" << engineerB.firstName_ << "\n;"

    //  So not you can not. However, what about public methods? Lets give it a go...

    engineerB.PublicUcGraduateFunc();

    //  PublicUcGraduateFunc is a public member of UcGraduate. Through public inheritance our derived
    //  class inherits its public calls and makes them accessable to its outside scope, just like its
    //  own public members.


    return 0;
}
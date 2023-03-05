#include <iostream>
#include "Utilites.h"
#include "DerivedPrivate.h"
#include "DerivedProtected.h"
#include "DerivedPublic.h"

int main(int argc, char **argv){

    //  Base class accessor deep dive..

    //  A 'Derived" class inherits from a 'Base class
    //
    //  If we were literal in our class names it would look like :
    //      'class Derived : public Base {...}'

    //    The keyword 'public' is used here as a "Base Class Access Specifier".
    //    There are three acceptable specifiers: public, protected, and private
    //                
    //       base class member state -> |   public  |  protected  |  private  | <- From
    //         -------------------------------v------------v------------v------
    //      'public' inherts members as |   public  |  protected  |  private  |  <-.
    //   'protected' inherts members as | protected |  protected  |  private  |     }- To
    //     'private' inherts members as |  private  |   private   |  private  |  <-'
    //
    //    *** Edited to reflect findings below **
    //
    //    The base class specifier works more or less like a modifier, changing how
    //    inherited members have their access labeled in the derived class.
    // 
    //    THIS HAS NO IMPACT ON THE READABILITY OF THESE MEMBERS FROM WITHIN THE DERIVED CLASS. 
    //
    //    What this actually does is impact how these imported members are accessible from
    //    -OUTSIDE- the derived class. The derived class will ALWAYS have direct access to the
    //    protected and public members of its base class, but through these options we can change
    //    not only how main scope accesses the public member of base, but also influence how classes
    //    that inherit from derived are able to access the public and protected members of base.
    //    (layers upon layers sort of thing...)
    //
    //    By applying protected or private as a specifier you reduce visiblity of outer scope of the 
    //    members. 'protected' inherits public members as protected, and 'private' inherits
    //    public and protected members as private. This can be seen in the chart I created above...


    //  I have created Base class for which three members exist...
    //      basePrivateInt_, baseProtectedInt_, and basePublicInt_
    //  These live in the private, protected, and public clauses respectively.

    //  Additionaly I have created the classes DerivedPrivate, DerivedProtected, and DerivedPublic
    //  to implement all three base class specifiers and inherit from Base.

    Base base{};
    base.DisplayDirectlyAccessibleData();

    DerivedPublic derivedPublic{};
    derivedPublic.DisplayDirectlyAccessibleData();

    DerivedProtected derivedProtected{};
    derivedProtected.DisplayDirectlyAccessibleData();

    DerivedPrivate derivedPrivate{};
    derivedPrivate.DisplayDirectlyAccessibleData();

    //  Ok, so this didn't quite work the way that I expected...
    
    //  All derived classes were unable to access Base's private member, which makes sense.
    //  However, DerivedPrivate was still able to access the public and protected members
    //  of Base, which I thought should have been inherited as private members...

    //  I think the way that a derived class always has access to the protected and public members
    //  of its base class regardless of specifier setting. Instead, this specifer influences
    //  how others outside of this class can use these members.
    //
    //  Essentially it changes how the inherited public and protected members have access as
    //  a member of the derived class!

    //  Lets check!

    std::cout<< "derivedPublic.basePublicInt_() : " << derivedPublic.basePublicInt_ << "\n";
    //std::cout<< "\nderivedProtected.basePublicInt_() : " << derivedProtected.basePublicInt_ << "\n";
    std::cout<< "derivedProtected.basePublicInt_() : " << "inaccessible" << "\n";
    //just as I thought, the basePublicInt_ acts as a protected member of derivedProtected and is inaccessible
    //from outer scope
    //This should mean that if another class inherited from derivedProtected (despite specifier) it
    //would have access to the public and protected members of base, which are actually just protected
    //members of derivedProtected from its perspective.

    //This sort of thing requires some careful planning of data structures. My guess is that public
    //and private will be incredibly useful in preventing outer object scope from messing around
    //with the internals of the base obj, which the derived obj is dependant on. 

    //ie, if Base has a public method Clear(), we probably don't want that to be callable from outside
    //of derived while it is still using the Base obj. In that case we'd probably make it private so
    //that it could only be called by the destructor of Derived, unless ofcourse we plan on designing
    //a class that inherits from Derived that needs to pull that plug...

    //Yeah, planning is critical here.

    return 0;
}
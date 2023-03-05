#include <iostream>
#include "dog.h"

void dogOnHeap(){
    //classes, like variables, can be created on the heap
    Dog * pDog = new Dog("Fluffy", "Three Headed Dog", 300);
    //dont forget though, when leaving scope of a pointer to memory on stack we need to release that memory!
    delete pDog;
    //delete pDog here will delete that spot in memory, in addition to calling the destructor for that class
    //      So there is a cascade of deleting that can occur. Here pDog will also release the pointer in memory to m_age (300)
}


int main(int argc, char **argv){

    //class destructors  -> examine dog.h and dog.cpp

    {
        Dog dogA ("Spot", "Beagle", 5);
    }
    //when the dog object goes out of scope the destructor is called!
    //calls in destructor definiton, to delete memory allocated on heap, are executed
    //no memory leaks!

    //you can also call destructor manually by deleting an object
    dogOnHeap();

    //An interesting note for the way this class is currently set up.
    //      The member variable m_age is a pointer. We also dont have any manually written copy constructors yet (you will learn later)
    //      As such, if I created a dog object and sent it through a function by value, all of the values for the existing
    //      member functions would be copied into a copy of that class' member functions. 
    //              INCLUDING THE ADDRESS TO THE INT MEMORY FOR M_AGE ON THE STACK
    //      As soon as that function ends and the pass by value copy of dog dies, its destructor will be called.
    //      !! This will delete the memory for our heap int even though the original dog still has a pointer to it!
    //      If we do anything with that data, or the original dog itself goes out of scope and delete is called again,
    //      RIP, program crash.

    //We will learn how to avoid this later...


    //A small interesting aspect on the construction destruction calls.
    //These instances of dog die right after they are created because we dont store them. Their destructors are called in opposite order.

    Dog("AAAA", "AAAA", 1);
    Dog("BBBB", "BBBB", 1);
    Dog("CCCC", "CCCC", 1); //Qatch the destructor cout in terminal...and clang dissapoints!

    //On some compilers (not mine :/ ) these objects are destructed in reverse order.
    //The earliest objects could have later ones depending on them. Not in this case obviously, but in more complicated ones.
    //This order of deletion, removing newest objects first, mitigates the chance of deleting an object while others still rely on it.

    //Not terribly important now, but some behind the compiler functionality to be aware of.

    //////  //  //  //  //////
      //    //  //  //  //
      //    //////  //  //////
      //    //  //  //      //
      //    //  //  //  //////

    // Each class member function contains a hidden pointer called this.

    //This contains the address of the current object, for which the method is being executed. This also applies to 
    //constructors and destructors. It can be used as a method of calling on other methods in the class.

    //  >> constructors updated with method to use this display address of object in memory <<
    
    // Think of this simply like any other pointer to an object. You can dereference it or use the -> opperater to use it.

    {
        Dog thisDog("Bob", "Another Dog Breed", 5);
        thisDog.SetName("California");     // Examine method SetName to see how this is used to distinquish between similarly named arguments
    }

    //you could re-write the setter calls for this class to return this... (changed here)
    //if you do that you could chain arguments to set multiple items, because each call gives you back a pointer to the object!

    {
        Dog * pDog = new Dog();
        //        Returns this
        //          |       Returns this
        //          |          |                 Returns this
        //          V          V                    V
        pDog->SetAge(50)->SetBreed("Laser Dog")->SetName("Scott");
        delete pDog; //remember to delete objects before their pointer hits end of scope
    }

    //The setters could even be rewritten again (not going to) to have the return type Dog&.
    //Then we could 'return *this;' to return the dereferenced version of this, the object, to the Dog& return type.
    //We could then chain the setters through use of the . opperator multiple times.

    return 0;
}
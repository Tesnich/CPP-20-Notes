#include <iostream>
#include "CriticalError.h"
#include "WarningError.h"

void ThrowAnError(){

    //cool little bit of code, __func__ is a standard macro to input function name
    //ptr to array of const char subbed in durring compilation
    if (rand()%2){
        throw CriticalError(std::string{__func__}+="()");
    } else {
        throw WarningError(std::string{__func__}+="()");
    }
}

int main(int argc, char **argv){


    //We can use polymorphism to create some cleverly implemented exception objects
    //Critical error and warning error inherit from abstract class ErrorObject

    std::srand(time(0));

    try{
        ThrowAnError();
    //reminder: if we don't intend on modifying a parameter make it const ref!
    }catch(const ErrorObject& errorObject){ //this is a reference to the base class object of CriticalError and CriticalWarning
        std::cout << errorObject.What();
    }

    //Doesn't polymorphism just make you all warm inside? :)


    //On this note, we should also mention that order of catch clauses matters a lot when checking for different
    //levels of polymorphism

    //Unlike function overloads that will take the best fit for a passed in argument, handoff to catch classes are
    //deduced in order, like if else or switch statements

    try{
        ThrowAnError();
    }catch(const ErrorObject& errorObject){
        std::cout << errorObject.What();
    }catch(const CriticalError& criticalError){ //<- g++ is actually smart enough to recognize this path is cut off! NICE
        std::cout << "OMFG SHIP IS CRASHING ALERT THE CREW!\n";
        std::cout << criticalError.What();
    }

    //In the above case if our ThrowAnError() function throws a critical error, the base error object is going
    //to fullfil the catch roll even though we created a clause for criticalError... the crew wont get the alert
    //due to poor programming...

    //In reality you'd probably check the severity within one catch and go from there. I can't think of a reason
    //to have multiple catches unless you have multiple objects being thrown that don't descend from the same
    //base class. (poor program planning)

    //Othewise, order your catch blocks by most derived arguments to least derived...



    //Note, in a quiz for this section the following example was given (changed to better fit my code)

    /*
    
        try{
            throw CriticalError("OMG");
        }catch(const ErrorObject errorObject){
            std::cout << errorObject.What();
        }

    */

   //The key point being that the catch didn't use a reference. In my code this wouldn't even build because
   //my error object is an abstract class. HOWEVER, if it was not, the point of this setup was to show you
   //that you'd be making a copy of the base object of the CriticalError object thrown, slicing off the critical
   //bit. You wouldn't be using polymorphism at all. The result of what would be whatever base implementation the
   //ErrorObject class had implemented.

   //Another good reason to get in the habbit of using references in catch parameters (in addition to reducing copy
   //operations discussed in 129... or was it 128... idk its one of them go look)

    return 0;
}
#include <iostream>
#include <memory>
#include "Utilites.h"
#include "ObjectLifeWatch.h"
#include "DeletedCopyConstructor.h"

void recursiveCall(unsigned int i){
    std::cout <<"recursiveCall() depth ("<< i <<") START\n";
    if (i > 5)
        throw std::string{"recursiveCall() depth "+ std::to_string(i)};
    recursiveCall(i+1);
    std::cout <<"recursiveCall() depth : ("<< i <<") FINISHED!\n";
}

void MultipleCatchBlocks(bool doubleThrow){
    try{
        if (doubleThrow){
            throw 9.0;
        } else {
            throw std::string{"STRINGTHROW"};
        }
    }catch(double ex){
        std::cout << "Exception DOUBLE : " << ex << "\n";
    }catch(std::string ex){
        std::cout << "Exception string : " << ex << "\n";
    }
}

int main(int argc, char **argv){

    //Exception Handling - Try and Catch

    //Try and catch blocks allow you to calling problematic code and recover opperation if it fails

    Util::PrintTitleLine("Simple Try Catch");
    //the keyword 'try' here denotes the problem area we want to recover from...
    try{
        std::cout << "Try Block - BEFORE the throw!\n";

        int intVar{0};

        //we can craft conditionals inside try blocks to check code status
        //in the event we know that we cannot process some data correctly given an indicator
        if (intVar == 0)
            throw 0; //we can throw an object of any type (literal used here but real variable could be provided)

        // vvvv WILL NOT RUN AFTER THROW vvvv
        std::cout << "Try Block - AFTER the throw!\n";
        //upon a throw call, program processing imediately leaves the try block and enters the catch

    }catch(int ex){ //the parameter of the catch block must match the thrown type (or be implictly convertible)
        std::cout <<"Something went wrong. Exception thrown : " << ex << "\n";
        //from here we can do whatever we want with the input argument from the throw call
    }

    Util::PrintEndLine();
    //MEMORY LEAKS
    Util::PrintTitleLine("Memory Leaks");

    //It is important to realize that if an exception is thrown, your code flow is interupted
    //This means that something like the below will create memory leaks
    try{
        ObjectLifeWatch* ptrOLW{new ObjectLifeWatch{}}; //<------|ObjectLifeWatch created on heap
        throw std::string{"FAILURE"}; //<------------------------|
        delete ptrOLW;//<----------------------------------------|Exception thrown above means delete never runs!
    } catch (std::string ex){
        std::cout<<"Something went wrong. Exception thrown : " << ex << "\n";
    }

    //Watch the output to see how the object is never destructed
    Util::PrintEndLine();

    Util::PrintTitleLine("Smart Pointers Avoid Leaks");
    //By utilizing smart pointers, however, we can ensure that the objects we create on the heap are properly
    //cleaned when the smart pointers are destroyed... observe!

    try{
        std::unique_ptr<ObjectLifeWatch> unPtrOLW{std::make_unique<ObjectLifeWatch>()};
        throw std::string{"FAILURE"};
        //unPtrOLW will clear heap memory when it leaves scope. This happens regardless of whether a function
        //terminates pre-maturely due to an exception throw.
    } catch (std::string ex){
        std::cout<<"Something went wrong. Exception thrown : " << ex << "\n";
    }
    Util::PrintEndLine();


    //NOTE:: Tried to use a string_view or string initialized from a literal in throw. Doesn't work unless
    //a tempory object of a std::string{"FAILURE"} is created.

    //Any object can be used as input for an exception call AS LONG AS IT SUPPORTS A COPY CONSTRUCTOR.

    //Since the objects created in the try block will go out of scope imediately after a throw, references
    //or pointers to these objects will be useless (unless we are talking about heap memory).
    //As such, the compiler enforces that whatever object is thrown and caught must have a copy constructor.
    //There is no point in making the input argument for catch a reference, as it will either not build
    //or crash when run.
    
    //The below will not compile...
    /*
            try{
                DeletedCopyConstructor ex{};
                throw ex;
            }catch(DeletedCopyConstructor ex){
                std::cout << "CATCH RUN!\n";
            }
    */
    Util::PrintTitleLine("Compiler Opt Sidesteps Copy Constructor");
   
    //Fun little aspect, because of compiler optimization, the throw construction of DeletedCopyConstructor
    //below actually creates a DeletedCopyConstructor at the spot in memory where ex is created in the catch.
    //No copy constructor is called so its legal and will build!

    try{
        throw DeletedCopyConstructor{};// <------|Compiler optimization,
    }catch(DeletedCopyConstructor ex){// <-------|no copy constructor called! (builds despite VSCode anger)
        std::cout << "CATCH RUN!\n";
    }
    
    Util::PrintEndLine();
    Util::PrintTitleLine("Throws From Functions Inside Try");

    //THE THROW CALL WORKS IF CALLED WITHIN NESTED SCOPES!

    //Exceptions can be throw in functions called by the try block! The throw call will
    //go up level by level (terminating functions) until a try catch clause it found,
    //then execute said catch clause.

    //observe recursiveCall which throws an error at the 6th level of recursion
    try{
        recursiveCall(0);
    } catch (std::string ex) {
        std::cout << "Exception : " << ex << "\n";
    }

    //It doesn't matter how far down the rabbit hole an exception is throw, alice will find her way back

    //It is important to note that all levels of the recurrisve call DID NOT FINISH.
    //If this function created an object on the heap at its start and cleaned it at the end,
    //every object would leak.

    //Now imagine this isnt a recurrsive call, but instead 5 or 6 different methods calling one another
    //all with their own heap objects. <--- This is why it is important to use smart pointers in all aspects
    //of modern c++ programs. It helps us clean up situations like these!

    //Propbably most important of all is to make sure we implement exception handling as close as possible to
    //the spots we know can fail. If we do that, all other functions in between the failure spot on the next
    //catch block won't lose their program flow.

    Util::PrintEndLine();
    Util::PrintTitleLine("Multiple Catch Blocks");

    //Multiple Catch Blocks

    //observe the function MultipleCatchBlocks()
    //This function has a bool as an input argument that will either throw a double or an string
    //Additionally it has two catch blocks, one taking a double and the other a string.
    //The compiler will hand the exception off to the catch that matches the exception object type.

    MultipleCatchBlocks(true); //throw double
    MultipleCatchBlocks(false); //throw string

    //NOTE!! Testing has revealed that implicit conversion from int to double does not occur!
    //       Its probably best to catch the object type you know will be thrown and doing any conversion
    //       neccessary in the catch body.

    Util::PrintEndLine();

    return 0;
}
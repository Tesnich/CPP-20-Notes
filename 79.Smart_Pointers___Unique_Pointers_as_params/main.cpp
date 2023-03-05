#include <iostream>
#include <memory>
#include "DestructorWatch.h"
#include "DesWatHolder.h"

std::unique_ptr<DestructorWatch> returnUniquePtrDesWat(){
    std::unique_ptr<DestructorWatch> tempUniquePtr{std::make_unique<DestructorWatch>()};
    return tempUniquePtr; //My first thought here would have been that this will fail compilation
                          //However, it will succeed. The compiler is smart enought to realize that
                          //when returning a unique pointer copy constructing wont fly. Instead,
                          //this line is probably actually compiled as...
                          //    return std::move(tempUniquePtr);
                          //or even just created where we assign this value.

                          //looking at the terminal print out for this method call cinches it, 
                          //no destructor is called during this method call, or even during assignment in main
}

int main(int argc, char **argv){

    //Unique pointers as input parameters

    //  when passing unique_ptrs as input parameters, it is important to keep track of who has
    //  ownership of the pointer, because as stated before, its troublesome to have two unique_ptrs
    //  share the same address.

    //Take for example the class, DesWatHolder...
    std::unique_ptr<DestructorWatch> ptrDesWatA{std::make_unique<DestructorWatch>()}, ptrDesWatB{std::make_unique<DestructorWatch>()};
    std::cout << " >> Before desWatHolder scope << " << std::endl;
    {
        DesWatHolder desWatHolder(std::move(ptrDesWatA), std::move(ptrDesWatB));
    }   //because we used std::move() for the DestructorWatch pointers we know that desWatHolder owns them
        //and they will be deleted when the scope holding desWatHolder ends here
    std::cout << " >> After desWatHolder scope << " << std::endl;

    //additionaly, the returned value of std::make_unique<DestructorWatch>() is not considered the same type as std::unique_ptr<DestructorWatch>
    //auto for its output will deduce to a unique_ptr, but in reality what we recieve is an address on the stack for a new DestructorWatch
    //as such, the below is legal!
    {
        DesWatHolder desWatHolder2(std::make_unique<DestructorWatch>(), std::make_unique<DestructorWatch>());
        //two DestructorWatches are created on the heap and used to directly initialize the unique_ptr input arguments
        std::cout << " >> After desWatHolder2 make_unique argument construction << " << std::endl;
    }
    std::cout << " >> After desWatHolder2 scope << " << std::endl;

    //something else interesting about returning unique_ptrs... examine the call returnUniquePtrDesWat() above;
    {
        ptrDesWatA = returnUniquePtrDesWat(); //read comments written in method
        std::cout << " >> After returnUniquePtrDesWat() call << " << std::endl;
    }


    //What if we want to pass a unique pointer but dont want to transfer ownership?
    //Well since we can't pass by value, we are left with passing by ref and const ref!

    //                                                    _____                     _
    //If you dont intend on changing anything simply use (const std::unique_ptr<...>& constRefTempName) as the input argument, just like normal
    //                                                    ^^^^^                     ^

    return 0;
}
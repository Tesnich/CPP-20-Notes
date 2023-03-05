#include <iostream>
#include <memory>
#include "DestructorWatch.h"

std::unique_ptr<DestructorWatch> returnUniquePointer(){
//
//   auto deduces type std::unique_ptr<DestructorWatch> from initializer value       
//   |
//   V
    auto tempUniquePointer {std::make_unique<DestructorWatch>()};

    return tempUniquePointer;
    //above implicitly changed to
    //  return std::move(tempUniquePointer);
}

//with shared pointers simple pass by value will work fine!
void readValuesOfArray(std::shared_ptr<int[]> tempArray, unsigned int size){
    std::cout<< "---- readValuesOfArray body ----" << std::endl;
    for(size_t i{0}; i < size; ++i)
        std::cout << tempArray[(size-1)-i] << " ";
    std::cout << std::endl;
    std::cout<< "---- body end ----" << std::endl;
}

int main(int argc, char **argv){

    //Shared pointers

    //Shared pointers are like unique pointers in that they delete the object they refer to,
    //inorder to prevent data leaks.

    //The big differences, however, are ...
    //      1.) Multiple shared_ptrs can point to the same data
    //      2.) Copy constructors are not deleted
    //      3.) The heap object does not get deleted until ALL shared_ptrs pointing to it die
    //      4.) shared_ptrs have additional member methods (use_count())

    //Instead of using std::make_unique to get a new heap location, we use std::make_shared
    std::shared_ptr<DestructorWatch> shPtrDesWat1{std::make_shared<DestructorWatch>()};
    std::shared_ptr<DestructorWatch> shPtrDesWat2 = shPtrDesWat1;
    std::shared_ptr<DestructorWatch> shPtrDesWat3{shPtrDesWat1};
    auto shPtrDesWat4{shPtrDesWat1};
    std::cout << "Number of pointers to object shPtrDesWat1 points to : " << shPtrDesWat1.use_count() << std::endl;
    //we can also see this number go down with use of the reset on one of these...
    shPtrDesWat4.reset();
    std::cout<< ">> shPtrDesWat4.reset(); <<" << std::endl;
    std::cout << "Number of pointers to object shPtrDesWat1 points to : " << shPtrDesWat1.use_count() << std::endl;

    //The below causes a memory_allocation issue...
    //std::shared_ptr<DestructorWatch> shPtrDesWat2A{shPtrDesWat1.get()};

    //It looks like, similar to unique_ptrs, its a bad idea to construct a smart pointer using
    //a raw address using get() from another smart pointer. My guess is that assignment and copy
    //constructor implementations have something to do with tracking instances pointing to the same data.

    //That is a little dissapointing...

    //The above being said, you can change a normal pointer into a smart pointer by using it to
    //initalize a shared pointer. Just make sure to use that shared pointer as the initializer for any
    //subsequent shared pointers.

    DestructorWatch* ptrDesWat1{new DestructorWatch()};
    std::shared_ptr<DestructorWatch> shPtrDesWatB1{ptrDesWat1};
    //doing this does not clear the traditional pointer, plus it doesn't show up in count!
    std::cout<<"Count for shPtrDesWatB1 constructed from traditional pointer : " << shPtrDesWatB1.use_count() << std::endl; 
    //dont forget to set original traditional pointer to nullptr!
    ptrDesWat1 = nullptr;

    //ofcourse, just like normal pointers, you can go through any of them to change the object. Changes
    //can be observed through all of them.


    //changing from a unique pointer to a shared pointer...

    //say you have a unique pointer to an object created using the below statement
    std::unique_ptr<DestructorWatch> aUniquePointer{std::make_unique<DestructorWatch>()};
    //we can't use a unique_ptr initialize a shared_ptr, compiler error
    //std::shared_ptr<DestructorWatch> aSharedPointer{aUniquePointer};
    //however, if we want to change an object on the stack to use a shared_ptr INSTEAD of a unique_ptr
    //we can initialize or assign a shared pointer to the std::move() of the unique_ptr
    std::shared_ptr<DestructorWatch> aSharedPointer{std::move(aUniquePointer)};
    //in doing so, aUniquePointer is changed to nullptr and the shared pointer gets ownership of the object on the heap
    //Easy!

    //On a counter note, there is no way to turn a shared_ptr into a unique_ptr
    //These cause compiler errors for safety

    std::cout<<"-----UniqueReturnTypeToShared-----"<<std::endl;
    //Now, take the above information and re-vist an idea discussed in the previous lecture.
    //When you return a smart pointer in a function, the compiler is smart enough to change
    //      return tempUniquePtr;
    //implicitly to
    //      return std::move(tempUniquePtr);
    //This means that you could feasilbly write a function that creates a unique pointer,
    //and returns it into a shared pointer with no issues. Observe...
    std::shared_ptr<DestructorWatch> aSharedPtrFromUniqueReturnType{returnUniquePointer()};

    // -- TIP -- Knowing this, it is a good idea to write functions return unique_ptrs if they ever need
    //to return a smart pointer. That way the caller can easily turn it into a unique_ptr or
    //shared_ptr as they wish. If you return a shared_ptr they will have no way of turning it
    //into a unique_ptr if needed! More options for the caller the other way!


    //Shared pointers with arrays...

    //Disclaimers :
    //      Support for shared pointers to arrays was added in c++ 17
    //      std::make_shared is not formally supported for arrays (most compilers don't support)
    
    //For the most part they work just like unique pointers and arrays.
    std::shared_ptr<int[]> shPtrIntArray{new int[10]{0,11,22,33,44,55,66,77,88,99}};

    for(size_t i{0}; i < 10; ++i)
        std::cout << shPtrIntArray[9-i] << " ";
    std::cout << std::endl;


    // shared pointers as input arguments

    //similar to unique_ptrs but
    //because shared_ptrs do not have disabled copy or assignment constructors, 
    //pass by value is possible! No need for use of std::move() like with unique_ptr arguments
    readValuesOfArray(shPtrIntArray, 10);
    //ofcourse, some times it just makes sense to use ref and const ref...

    //Lecture mentions that it is problematic to return a reference to a shared_ptr, didn't explain
    //perhaps it steps on the toes of compiler optimization which sorta does that anyway?

    return 0;
}
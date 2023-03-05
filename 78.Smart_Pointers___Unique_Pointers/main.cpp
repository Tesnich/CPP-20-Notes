#include <iostream>
#include <memory>
#include <string>
#include <iostream>

#include "DestructorWatch.h"

int main(int argc, char **argv){

    //Smart Pointers

    //Smart pointers are a c++ 11 and newer feature to intelligently manage memory and prevent leaks

    //Essentially smart pointers are a wrapper for pointers and the delete opperator. 

    //this uses the c++ library <memory>

    //Traditional Pointers refresh...
    {
        int* ptrHeapInt {new int{30}};

        //must rememeber to delete memory on leaving...
        delete ptrHeapInt;
    }

    //Unique Pointers .... one of the smart pointer types, object written to assume they (one unqiue_ptr)
    //                     are the only ones pointing to a spot in memory. No other unique_ptr should
    //                     ever be sharing the same address on the heap.

    //This is the most basic of smart pointers, essentially just handling auto deletion of objects in respect to one unique_ptr

    {
        //The unique pointer is a class template, meaning we must specify the type we wish to use with it
        std::unique_ptr<int> uniquePtrHeapInt {new int{99}};
        //               ^
        //               |
        //              This can be any object, including ones you have written

        //these unique pointers can be used just like any other
        std::cout << *uniquePtrHeapInt << std::endl;
        *uniquePtrHeapInt = 11;
        std::cout << *uniquePtrHeapInt << std::endl;

        std::cout <<"uniquePtrHeapInt       : " << uniquePtrHeapInt << std::endl;
        //the above seems to show the address where the unique ptr is pointing to (address for int on heap)
        //but if there is any confusion, we can use the unique_ptr member function get()
        //to retrieve the address we are managing
        std::cout <<"uniquePtrHeapInt.get() : " << uniquePtrHeapInt.get() << std::endl;

        //C++ 14 and newer --> With this library also comes functionality to handle calling the new opperator for you
        //use the template member function make_unique<>() to do so!
        std::unique_ptr<std::string> uniquePtrHeapString = std::make_unique<std::string>("Hello");
        std::cout <<"uniquePtrHeapString    : " << *uniquePtrHeapString << std::endl;
    }

    //showing that when leaving scope, the objects on heap are automatically deleted
    //look at the class in DestructorWatch.h

    {
        //old method, no manual delete implemented by user (memory leak)
        DestructorWatch* ptrDesWat {new DestructorWatch};
        DestructorWatch* ptrDesWat2 {new DestructorWatch};
    }

    {
        //modern method, delete auto called when scope ends
        std::unique_ptr<DestructorWatch> UniquePtrDesWat = std::make_unique<DestructorWatch>();
        std::unique_ptr<DestructorWatch> UniquePtrDesWat2 = std::make_unique<DestructorWatch>();
    }

    //with the unique pointer we prevent other unique pointers from refering to the same space in memory
    {
        std::unique_ptr<int> UniquePtrHeapInt = std::make_unique<int>(10);

        //  !!!! compiler error, defintion for this assignment constructor is deleted
        //std::unique_ptr<int> UniquePtrHeapInt1 = UniquePtrHeapInt; 

        //  !!!! compiler error as definition for copy constructor deleted
        //std::unique_ptr<int> UniquePtrHeapInt2 {UniquePtrHeapInt2};

        //it looks like the below builds :/ does this cause problems? Yes it does... (malloc error, pointer being freed was not allocated)

            //  std::unique_ptr<int> UniquePtrHeapInt3 {UniquePtrHeapInt.get()}; //because now two unique pointers match?
            //  
            //  if(UniquePtrHeapInt == UniquePtrHeapInt3)
            //      std::cout << "!! Unique pointers match !!" << std::endl;
 
        //the unique pointer UniquePtrHeapInt auto deletes that spot in heap memory
        //UniquePtrHeapInt3 tries to do the same and we get an error.

        //one unqiue_ptr can't enforce that it is unique from other unique_ptrs. It ASSUMES it
        //is unique. To a certain extent it prevents programmers from breaking this construct by deleting
        //assignment and copy constructors from the same type. But as shown above, given a raw address to
        //the heap, it will assume you know what you are doing and that it is not the address from another
        //unique pointer. 

        //Breaking this assumption will lead to disaster, creating memory allocation problems like in the above snippet.
    }

    {
        std::cout << ">> std::move() used with unique ptr" << std::endl;
        //The proper way to move one unique pointer to another is to use std::move (my guess special move constructor written)
        //  This takes care of transfering holding rights and empties the source unique_ptr
        std::unique_ptr<DestructorWatch> uniquePtrDesWat = std::make_unique<DestructorWatch>();
        std::unique_ptr<DestructorWatch> uniquePtrDesWat2 {std::move(uniquePtrDesWat)};
        std::cout << "uniquePtrDesWat.get() after move  : " << uniquePtrDesWat.get() << std::endl; //source is set to nullptr in std::move opperation
        std::cout << "uniquePtrDesWat2.get() after move : " << uniquePtrDesWat2.get() << std::endl;
        //viewing log you can see that only one DestructorWatch, (4), is constructed and deleted in this block
    }

    {
        //we can also clear a unique_ptr object with use of the reset() member function
        //reset() will set the unique_ptr to null and delete the memory associated with its address
        std::cout << "------ Start of Scope ------" << std::endl;
        std::unique_ptr<DestructorWatch> uniquePtrDesWat = std::make_unique<DestructorWatch>();
        uniquePtrDesWat.reset();
        std::cout << "uniquePtrDesWat.get() after reset : " << uniquePtrDesWat.get() << std::endl; //set to 0, nullptr
        if(uniquePtrDesWat == nullptr)
            std::cout << "uniquePtrDesWat set to nullptr" << std::endl;
        std::cout << "------- End of Scope -------" << std::endl;
    }

    //was left wondering why you'd use make_unique over new, research online seems to indicate that
    //  it is a better way to kick the habbit of old code new/delete. More practically it looks like
    //  use of the make_unique() call indicates the return type of a unique_pointer<> ie... you can
    //  intelligently use auto with it. Lastly, make_unique is written to leverage modern exception
    //  infrastructure.

    

    return 0;
}
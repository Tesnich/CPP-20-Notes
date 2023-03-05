#include <iostream>
#include <memory>
#include "DestructorWatch.h"

int main(int argc, char **argv){

    //unique_ptr to an array?

    //With a normal pointer...
    {
        int* array{new int[5]{1,2,3,4,5}}; //array exists on the heap...

        for(unsigned int i{0}; i<5; ++i)
            std::cout << array[i] << " ";
        std::cout << std::endl;

        delete[] array; //clears array from heap memory
        array = nullptr;
    }

    //With a smart pointer
    {
        //can't figure out how to use make_unique for int array with list initialization on the heap
        // std::unique_ptr<int> array = std::make_unique<int[5]>({6,7,8,9,10});

        /* Found the below that straightens things out

        https://stackoverflow.com/questions/49723917/custom-initialize-array-with-stdmake-unique

        There are 3 overloads for std::make_unique:

        template< class T, class... Args >
        unique_ptr<T> make_unique( Args&&... args );     // (1) for non-array type

        template< class T >
        unique_ptr<T> make_unique( std::size_t size );   // (2) for array type with unknown bounds

        template< class T, class... Args >
            make_unique( Args&&... args ) = delete; // (3) for array type with known bounds.
        
        */

       //so in a nutshell, the constructor that would have allowed me to do this is deleted, I could
       //use the second one if I really wanted to use make_unique to to create an array, but I'd have to populate it later

       //we can create a unique_ptr without make_unique though...

        //                  _---Brackets needed here so that the unique_ptr can properly delete the whole array
        //                 |    Sorta like doing 'delete[] ptrHeapArray;' with traditional pointers
        //                 V
        std::unique_ptr<int[]> array2{new int[5]{6,7,8,9,10}};

        for(unsigned int i{0}; i<5; ++i)
            std::cout << array2[i] << " ";
        std::cout << std::endl;

        //lecture goes into the second constructor of make_unique that I just figured out...

        //                                                 _---constructor for array creation is specifying array in template
        //                                                |    then as in input argument specify the size for the array
        //                                                V
        std::unique_ptr<int[]> array3{std::make_unique<int[]>(10)};

        //with the above you then have to go through and add the values after
        for(unsigned int i{0}; i<10; ++i)
            array3[i] = i*10;
        
        for(unsigned int i{0}; i<10; ++i)
            std::cout << array3[i] << " ";
        std::cout << std::endl;
    }

    {
        //we can also make use of auto to limit the amount of typing we do if we use make_unique
        auto array4{std::make_unique<int[]>(5)}; //easy! but I think it might be best to include the type for understanding and readability
    }

    //showing the difference between leaving out[] in the template of a unique_ptr
    {
        std::cout<< ">> Using <DestructorWatch[]> in unique_ptr template <<" << std::endl;
        std::unique_ptr<DestructorWatch[]> arrayOfDW{new DestructorWatch[3]()};
    }

    //below is bad code and causes memoery allocation error...
    //  program(1416,0x101378580) malloc: *** error for object 0x127606898: pointer being freed was not allocated
    {
        std::cout<< ">> Using <DestructorWatch> in unique_ptr template <<" << std::endl;
        std::unique_ptr<DestructorWatch> arrayOfDW{new DestructorWatch[3]()};
    }
    std::cout<< "END OF PROGRAM" << std::endl;
    //I am not sure why this is the case. I thought that the unique_ptr would just delete one,
    //which seems to happen, then the others would be a memory leak. Could be a tough one to
    //debug if you had no idea where the problem was, thats for sure... 
    
    //Because "END OF BLOCK" fails to print, it's safe to assume there are some safegaurds in place
    //with unique pointers when it appears that they dont delete everything. Just gotta keep an eye
    //out for these kind of things.

    return 0;
}
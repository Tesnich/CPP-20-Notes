#include <iostream>

int* getPointerToOdd(int array[], size_t arraySize, bool pointerArithmetic);

int main(int argc, char **argv){

    //so there are interesting ways to use the pointer return type to get pointers to elements in an array

    int array[] {2,2,2,1,2,2};

    int* ponterToInt1 {getPointerToOdd(array, std::size(array), false)};
    std::cout << "*PointerToInt1 : " << *ponterToInt1 <<std::endl;

    //pointer arithmetic version of call
    int* ponterToInt2 {getPointerToOdd(array, std::size(array), true)};
    std::cout << "*PointerToInt2 : " << *ponterToInt2 <<std::endl;

    return 0;
}

int* getPointerToOdd(int array[], size_t arraySize, bool pointerArithmetic)
{
    if(pointerArithmetic) //two ways to do this using either pointer math or array syntax
    {
        for(size_t i{0}; i < arraySize; ++i)
        {
            if(*(array+i) % 2 ) return (array +i);
        }
    }
    else
    {
        for(size_t i{0}; i < arraySize; ++i)
        {
            if(array[i] % 2 ) return &array[i];
        }
    }

    return nullptr;
}
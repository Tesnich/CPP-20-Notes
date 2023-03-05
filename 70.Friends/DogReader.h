#ifndef DOG_READER_H
#define DOG_READER_H

#include "Dog.h"

//class DogReader declared as friend in Dog class
class DogReader{
    private :
        Dog * ptrDog_{nullptr};
    public :
        DogReader() = delete; //disable default constructor
        DogReader(Dog* ptrDog)
            :ptrDog_(ptrDog) {}
        void Read(); //DogReader class is declared as a friend of Dog, allowing access to private class members
};

#endif
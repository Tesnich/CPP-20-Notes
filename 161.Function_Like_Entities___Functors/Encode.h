#ifndef ENCODE_H
#define ENCODE_H

//In the begining I set out to create a functor interface below, from which Encrypt and Decrypt will inherit
//and be forced to implement an encode() function. However, I added the overload of the () operator which
//means that this isnt an interface? Anyway Encode is an abstract class because of the pure virtual function
//encodeChar.

class Encode{
    private:
        virtual char encodeChar(const char input) = 0;
    public:
        char operator() (const char input){
            return encodeChar(input);
        }
};

//With this structure other classes and functions can take in a pointer or ref to this abstract class and
//through polymorphism we can call child functionality.

#endif
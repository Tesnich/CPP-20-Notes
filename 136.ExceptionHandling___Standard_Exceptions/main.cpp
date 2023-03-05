#include <iostream>
#include "Derived.h"
#include "IntHolder.h"

int main(int argc, char **argv){

    //C++ has a variety of standard exceptions that can be thrown and caught

    //https://en.cppreference.com/w/cpp/error/exception

    Base base{};

    try{
        Derived derived{dynamic_cast<Derived&>(base)}; //the issue here is that when trying to dynamic cast from base
                                                       //to a ref of its associated derived class, an exception occurs
                                                       //if there is none.
                                                       //If you are casting to a pointer of a derived it simply returns
                                                       //nullptr in such cases.
                                                       //The difference being that references must be initialized when
                                                       //created, if that is not possible exception!
    } catch (std::exception& ex){
        std::cout<< "Exception Caught : " << ex.what() << "\n";
        //standard exceptions inherit from a base exception class. Through polymorphism
        //all exception types will implement a what() method. If we wanted more info on any
        //particular exception we could catch the more specialized class (derived)
    }


    //in addition to catching standard errors, we have full range to use them to define exceptions in our own objects
    //check out IntHolder. The int holder class creates an array of ints on the head based on number of ints provided
    //to the constructor using an initializer_list. 

    //You can then fetch them using an unsigned int and the At() class method. If you excceed the number put in, however,
    //you get an exception.

    IntHolder intHolder{0,11,22,33,44};
    try{
        intHolder.At(5);
    }catch(std::exception& ex){
        std::cout << "Exception Caught : " << ex.what() << "\n";
    }

    std::cout<<"Program Ended Successfully!\n";
    return 0;
}
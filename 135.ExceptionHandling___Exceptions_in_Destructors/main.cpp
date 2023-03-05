#include <iostream>
#include "DestructorWatch.h"
#include "DestructorWatch2.h"

int main(int argc, char **argv){

    //Class destructors are noexcept by default in c++ 11 forward!

    //If an exception is thrown in a destructor that can not be handled by the destructor, your program will
    //terminate

    //Examine DestructorWatch, which throws an exception in its destructor
    //Also Examine DestructorWatch2, which overrides this default behavior of noexcept

    //launch program with 'true' argument to use DestructorWatch2 with noexcept(false) destructor

    bool useDestructorWatch2{false};

    if(argc > 1){
        std::string programInput{argv[1]};
        useDestructorWatch2 = (programInput == "true")? true : false;
    }

    {
        try{
            if(useDestructorWatch2){
                DestructorWatch2 destructorWatch2{}; //destructor set noexcept(false) throwing exception
            } else {
                DestructorWatch destructorWatch{}; //default destructor throwing exception
            }
        }catch(double ex){
            std::cout<<"An exception of " << ex << " has been caught!\n";
        }
    }

    std::cout<< "Program ended successfully!\n";

    return 0;
}
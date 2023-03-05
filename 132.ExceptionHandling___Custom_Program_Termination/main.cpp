#include <iostream>

void customTerminatate(){
    std::cout << "Well crap, an exception went unhandled. Killing the program.\n";
    std::abort(); //<- make sure to call abort() otherwise os will call it for you
                  //   its just good design to do it ourselves
}

int main(int argc, char **argv){

    //Custom Program Termination

    //As we have seen, when a program throws an error but does not handle it (catch it), the program crashes.

    //There is slightly more to the process...

    //If an exception is not handled anywhere int he application the function std::terminate() located in the 
    //<exception> library is called. terminate() in turn calls std::abort() in <cstdlib> and the program is killed.

    //We can write our own termination function! Look above at customTerminatate(); 
    //This can be named anything we want.

    //To use this function as a replacement for std::terminate(), use the below call.

    std::set_terminate(&customTerminatate);
    //                 ^------- This use of & is actually giving us the address of our terminate function
    //
    //set_terminate uses the address we provide to call the function in the event std::terminate() is called.
    //My guess is right at the begining if a special pointer like ptrAlternateTerminate is not nullptr it
    //will call that function.

    //Lets give it a go!

    throw 0;

    /*
        jameshillman@Jamess-MBP 132.ExceptionHandling___Custom_Program_Termination % ./program
        Well crap, an exception went unhandled. Killing the program.
        zsh: abort      ./program
    */

    //you could also pass in a lambda function if you wanted...thats definitely something I need to review...

    return 0;
}
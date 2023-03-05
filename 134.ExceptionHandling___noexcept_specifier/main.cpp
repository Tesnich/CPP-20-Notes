#include <iostream>

void noexceptFunction(bool throwException = false) noexcept{
    try{
        if (throwException){
            throw 5.0;
        }
    }catch(...){
        throw;  //rethrow of thrown argument (example could also have just been a throw)
                //G++ is actually smart enought to tell us this call will always terminate the function!
    }
}

int main(int argc, char **argv){

    //  No-except specifier

    //  the format is placing the identifier 'noexcept' after the elipsies of a function...
    //
    //  void noexceptFunction() noexcept {...}
    //

    //  Placing this specifer means exceptions are not allowed to be thrown from within the inside 
    //  of a function's scope to the outside of the function's scope. Essentially you are telling the compiler
    //  to terminate the program if such an error ever occurs...

    //called with the default argument 'false' noexcept does not throw an exception
    //calling the program with the input argument 'true' will call noexceptFunction with true, throwing an error

    bool throwException{false};

    if(argc > 1){
        std::string programInput{argv[1]};
        throwException = (programInput == "true")? true : false;
    }

    noexceptFunction(throwException);

    std::cout << "PROGRAM FINISHED SUCCESSFULLY!\n";
    //if noexcept throws an error to outer scope this statement will not print
    //call program with input argument 'true'

    return 0;
}
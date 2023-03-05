#include <iostream>


int main(int argc, char **argv){

    //Ellipsis catch all block 
    //      'catch(...)' <---those dots are literally the syntax

    //This is a catch block that captures any throw of any type, it can also rethrow aswell

    try{
        throw std::string{"an error has occured!"};
    }catch(...){ //<---- catch all exception block
        std::cout << "catch(...) caught some kind of error.\n";
        //throw;
        //could uncomment the above to rethrow the error despite not knowing what it originally was
    }

    return 0;
}
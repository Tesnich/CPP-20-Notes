#include <iostream>


int main(int argc, char **argv){

    //Nested Try & Catch blocks

    //Here we can see that try and catch blocks can be nested within one another, 
    //either in the same scope or in a function call, and unhandled exceptions for the
    //more specialized block will propogate up the the next level

    try{
        std::cout << "Outter Try Block Start\n";
        try{
            std::cout << "Inner Try Block Start\n";
            throw "CONST CHAR LITERAL"; //<- This throws a pointer to a const char array
            std::cout << "Inner Try Block End\n";
        }catch(char ex){ //<-This catches a single char, not pointers to a char array, thus wont be used on above throw
            std::cout << "Inner Catch Block : " << ex << " Thrown\n";
        }
        std::cout << "Outter Try Block End\n";
    }catch(const char* ex){
        std::cout<< "Outer Catch Block : " << ex << " Thrown\n";
    }

    return 0;
}
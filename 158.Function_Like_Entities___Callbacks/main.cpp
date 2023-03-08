#include <iostream>

//I probably wouldnt design the functions below
//to take in const values and return copies. Instead I would make them void
//and have them take in a reference to a char and just change it.
char encrypt(const char input);
char decrypt(const char input);
char uppercasify(const char input);
//Trying to think why lecture version would be an advantage...

//The below function declaration specifies a pointer to a function as an input argument, a callback function
//                                                 ______________________________
std::string& modifyString(std::string& inputString, char (*modifier) (const char));
//                                                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//This argument is defined the exact same way we create ptrs to functions on their own
//a declaration of the function with the return type, (* NAME), followed by input arguments for function

//This means that only pointers to functions matching this signature can be used as input

int main(int argc, char **argv){

    //Callback functions

    //These are pointers to functions that we pass back as arguments that will be called in functions

    //In this program I have designed a few different functions that can be passed in
    //to the modifyString function. modifyString simply iterates through the string data, replacing the
    //char with the result of the callback function.

    std::string message{"Some secret message to send."};
    std::cout << "message before modification : " << message << "\n";
    modifyString(message, encrypt);
    std::cout << "message after encryption : " << message << "\n";
    modifyString(message, decrypt);
    std::cout << "message after decryption : " << message << "\n";

    //using callbacks makes it trivial to add new functionality!
    modifyString(message, uppercasify);
    std::cout << "message after using uppercasify : " << message << "\n";

    return 0;
}

char encrypt(const char input){
    return input + 3;
}

char decrypt(const char input){
    return input -3;
}

char uppercasify(const char input){
    return toupper(input);
}

std::string& modifyString(std::string& inputString, char (*modifier) (const char)){
    for (char& character : inputString)
        character = modifier(character); //function pointer can be used just like a normal function.
    return inputString;
}
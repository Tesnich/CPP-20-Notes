#include <iostream>

//Type alias setup....
//                         _____________________ We do not give the function pointer a name here...
using StringModifierFunc = char (*) (const char);
//                         ^^^^^^^^^^^^^^^^^^^^^ We are simply defining a shortcut to the type


char encrypt(const char input);
char decrypt(const char input);
char uppercasify(const char input);

//                                                 ______________________________ we give the function pointer a name here!
std::string& modifyString(std::string& inputString, StringModifierFunc modifier);
//                                                 ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ If we want, this is just the declaration after all

int main(int argc, char **argv){

    //Callback functions with type aliases

    //Having to do almost all the work of re-declaring a function anytime we want to pass a pointer
    //to it can be quite tiresome. Instead we can set up a type alias once then use that everywhere!

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

//                                                  ___________________________
std::string& modifyString(std::string& inputString, StringModifierFunc modifier){
//                                                  ^^^^^^^^^^^^^^^^^^^^^^^^^^^
    for (char& character : inputString)
        character = modifier(character); //function pointer can be used just like a normal function.
    return inputString;
}
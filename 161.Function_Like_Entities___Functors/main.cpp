#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"

void alterMessage(std::string& message, Encode& encoder);

//the below setup requires no polymorphism, simply that functors passed in pass compilation in place of typename Encoder
template <typename Encoder>
void alterMessageTemplate(std::string& message, Encoder& encoder) {
    for(char& letter : message){
        letter = encoder(letter);
    }
}
//I thought there would be a slight problem with the above, where each call to the templated functions
//would create copies of the functors. This does not appear to be the case, however, as adding cout notifications
//in functor constructors did not highlight repeated construction of these objects.
//Could this mean that the compiler is smart enough to know that if a non self modifying object is passed in to
//a template to make it a reference?

//NOPE!!! I'm just dumb, ofcourse the constructor I've rigged isn't going to get hit multiple times. Rather,
//the default copy constructor would which I had not implemented a cout tripwire on. Anyways I know how this works
//so instead of doing what the lecture does I will just add a '&' to where the typename Encoder is used in
//alterMessageTemplate. (Don't want to got to the effort of implementing custom copy functionality... just for testing)

int main(int argc, char **argv){

    //Functors

    //Functors, also refered to as Function Objects, are objects that can be called like ordinary functions
    //This is done through overloading the () operator. 
    
    //If you remember, we have done this before when setting up classes so we could use () or [] to access
    //array data at a certain index. This leverages that same sort of concept.

    //This boils down to obejectifying functionality. The reason why you would create this structure instead of
    //using a function alone escapes me for the moment. Either way I think we can set up classes and function to 
    //use these "functors" very similarly to how we used templates in the previous lecture for smaller and larger
    //using polymorphism.

    //NOTE: I figured out why you might want to create functors instead of using normal callbacks. I can store data
    //in these class functors I've created. AKA the unsigned int by which encrypt or decrypt encodes data with.

    //Examine the headers for the Encrypt and Decrypt classes that inherit from the Encode class.
    unsigned int key = (argc > 1)? std::stoi(argv[1]) : 5;
    std::cout << "Key is : " << key << "\n";
    std::string message{"ABCDEFG"};
    
    Encrypt encrypt(key);
    Decrypt decrypt(key);
    
    std::cout << "Original Message : " << message <<  "\n";
    alterMessage(message, encrypt);
    std::cout << "Encrypted Message : " << message <<  "\n";
    alterMessage(message, decrypt);
    std::cout << "Decrypted Message : " << message <<  "\n";

    //ofcourse below is what makes encode (and by inheritance) encrypt/decrypt a functor. The ability to call these
    //object's functionality with ().

    std::cout << "encrypt('A') : " << encrypt('A') <<"\n";

    //the lecture went about the above use of functors in a different way. Where as I decided to leverage
    //polymorphism of a base functor named encode, instead Daniels decided to make two completely seperate
    //functors Encrypt and Decrypt which were passed into a template function where there encoder was templated.

    //The template succeeds with any functor passed in as long as the line that uses the functor compiles (ie () call
    //succeeds and return type fits in context) Somewhat easier than making every functor inherit from a base functor.

    std::cout << "Original Message : " << message <<  "\n";
    alterMessageTemplate(message, encrypt);
    std::cout << "Encrypted Message : " << message <<  "\n";
    alterMessageTemplate(message, decrypt);
    std::cout << "Decrypted Message : " << message <<  "\n";

    return 0;
}

void alterMessage(std::string& message, Encode& encoder){
    for(char& letter : message){
        letter = encoder(letter); //functor setup with ()
    }
}
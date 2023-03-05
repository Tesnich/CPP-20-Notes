#ifndef INLINE_SOURCE_CODE_H //this only protects a single TU from including the same header more than one
#define INLINE_SOURCE_CODE_H

#include <iostream>

inline int inlineVar{10};
//Below will cause re-definition error because included in Utility1.cpp and Utility2.cpp
//int standarVar{10};

inline void inlineFunction(){
    std::cout << "InlineFunctionCalled()" << std::endl;
}

//Below will cause re-definition error because included in Utility1.cpp and Utility2.cpp
// void standardFunction(){
//    std::cout << "standardFunctionCalled()" << std::endl;
// }

//  NOTE!! I came back to this upon writing code that DIDN'T fail compilation when I wrote a header file
//  whose functions didn't use inline. This is because the files I was including it in were main.cpp,
//  and three other header files that I wrote complete definition for classes in (no .cpps). 

//  It worked because I was really only creating 1 translation unit, for the main.cpp file!
//  Through #includes in that file all the code was consolidated into one object and there were no
//  linking errors because the compiler was able to consolidate all #includes. Just an FYI if I lose track
//  of this in the future! Use inline to future proof your code!

#endif
#include <iostream>
#include "utility1.h"
#include "InlineSourceCode.h"

inline int age{12};
inline int age2{0};

inline void some_function(){
    std::cout<<"age : " << age << std::endl;
    std::cout<<"&age : " << &age << std::endl;
    std::cout<<"age2 : " << age2 << std::endl;
    std::cout<<"&age2 : " << &age2 << std::endl;
    inlineFunction();
    //standardFunction();
}

void Utility1::CallSomeFunc(){
    some_function();
}


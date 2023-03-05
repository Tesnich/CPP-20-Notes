#ifndef FARM_H
#define FARM_H

//normally to build this header file we need the below line
//#include "dog.h"

//This would include all the info from dog, and require the farm.h/anything that includes it
//  to be recompiled if dog changes. Since the header file here is just refering to the name
//  dog, and doesn't actually need to know anything about it, we can use Forward Declaration
//  to bring that name in.

//Forward Declaration of dog
class Dog;

//The above class is simply a declaration of the class dog, that will be resolved during linking!

class Farm {
    public:
        Farm() = default;
        void UseDog(const Dog& dogParam); //doesn't require the definition
};

//Something important to note, is that this wont allow you to use any dog member function
//  Say you were writing a template or decided to write the defintion of UseDog here as

//  void UseDog(const Dog& dogParam)
//  {
//      std::cout << dogParam.color_ << std::endl;
//  }

//  the build will fail during compilation because this file will have no idea what the members
//  of the dog class are. For that you will need the defintion of dog (ie. #include "dog.h")

#endif
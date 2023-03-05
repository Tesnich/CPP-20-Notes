#ifndef DOG_H
#define DOG_H

#include <string>
#include <string_view>

class Dog{
    private :
        std::string dogName_;
        int dogAge_;
    public :
        Dog(std::string_view dogName, int dogAge);

        //declaration of friend functions (can be in the private or public sections)
        friend void debug_dog_info(const Dog& dog);
        friend void debug_dog_info();
        //Any above functions with the signatures above will be allowed to access memeber variables

        //You may not declare a friend function that does not exist!
        //Illegal!!!! Will not compile!
        friend void thisFunctionDoesNotExist(); //at least that is what the lecture said, this seems to build fine...

        //Declaring different classes as friends (again can be in private or public code block)
        friend class DogReader; //does not require include because we are essentially just approving the signature of a class
                                //ie. a class named "DogReader"
};

#endif
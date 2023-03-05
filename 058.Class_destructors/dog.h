#ifndef DOG_H
#define DOG_H

#include <string>

class Dog{
    private :
        std::string m_name{}, m_breed{};
        unsigned int * m_age {nullptr};
        
        void DisplayObjectAddress();
        
    public :
        //This is not a default cosntructor, this is a declaration;
        Dog();

        Dog(std::string_view name, std::string_view breed, unsigned int age);

        //changed mutators to return pointer to the object for chaining statements
        Dog * SetName(std::string_view m_name);
        Dog * SetBreed(std::string_view breed);
        Dog * SetAge(unsigned int age);
        //destructor declaration (will never have any input parameters)
        ~Dog();
};

#endif
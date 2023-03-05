#include <string_view>
#include "dog.h"
#include <iostream>

Dog::Dog(){
    m_name = "None";
    m_breed = "None";
    m_age = new unsigned int{0};
    DisplayObjectAddress();
}

Dog::Dog(std::string_view name, std::string_view breed, unsigned int age){
    m_name = name;
    m_breed = breed;
    m_age = new unsigned int{age};
    DisplayObjectAddress();
}

void Dog::DisplayObjectAddress(){
    std::cout << "The dog object with name " << m_name << " was constructed at : " << this << std::endl;
}

//changed mutator functions to return pointer to the object for chaining statements

Dog * Dog::SetName(std::string_view m_name){
    //normally if you tried to name an input parameter the same as a member variable you'd override access to the outer scope member variable
    //confusion would ensue as you tried to assign m_name to m_name, however, the below use of 'this' allows you to access outter scope
    this->m_name = m_name;
    //I still wouldnt do the above, but this just shows it CAN be done.

    return this; //support chaining
}

Dog * Dog::SetBreed(std::string_view breed){
    m_breed = breed;
    return this; //support chaining
}

Dog * Dog::SetAge(unsigned int age){
    *m_age = age;
    return this; //support chaining
}

//destructor definition
Dog::~Dog(){ //class scope resolution goes on LEFT side of ~ destructor opperator
    delete m_age; //object will now call delete of m_age's dynamically allocated memory when the object dies!
    std::cout << "Destructor for " << m_name << " called!" << std::endl;
}
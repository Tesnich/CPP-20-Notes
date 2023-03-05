#ifndef ADD_STRUCT_H
#define ADD_STRUCT_H
#include <cstring>
#include <memory>

template<typename ValueType>
struct AddStruct
{
    ValueType a_{}, b_{};
    AddStruct() = default;
    AddStruct(ValueType a, ValueType b)
        :a_{a}, b_{b} {
            std::cout << "Template Constructor Called()\n";
        }
    ~AddStruct() = default;

    ValueType Add() const {
        return a_+b_;
    }

    void RedHerring(){
        std::cout << "Red Herring\n";
    }
};

//template specialization for the AddClass using type char *
//__________
  template<> 
//^^^^^^^^^^
//               _______,-- Remember with specialization you need to provide the type value on declaration/definition
struct AddStruct <char*>
//               ^^^^^^^
{
    char * a_{}; //specialization is its own class, you don't have to follow the setup from the template
    char * b_{};
    std::unique_ptr<char> ptrResult_{};
    AddStruct() = default;
    AddStruct(char * a, char * b)
        :a_{a}, b_{b} {
            std::cout << "Specialized Constructor Called()\n";
        }
    ~AddStruct() = default;

    char* Add(); //can't be a const because we are altering ptrResult_

    //IMPORTANT!
    // void RedHerring(){
    //     std::cout << "Red Herring\n";
    // }

    //The above method RedHerring() is a member implemented on the AddStruct template, but not here
    //on the struct/class specialization of char*

    //This is because the specialization doesnt have to match the template, it is simply a different
    //class all together. That is a little confusing, but think of it as an overload that has precedence over
    //the template. (may need to re-vist this point later)
};

//specialization for char* version of Add (stand alone)

//template<> //<---actually it looks like this isn't even needed (thats different than what I thought in 140...)
//                 MORE UNDERSTANDING: Basically template<> indicates that something is a template specialization,
//                 simple and done. The below ISNT a template specialization. It is simply the definition of the
//                 method declared in the struct template specialization AddStruct<char*>
//
//                 In 140. I was specializing template methods on the template class in that lecture. Thus, 
//                 the template specialization identifier 'template<>' was needed. Beautiful.
//
//                 I have taken some many notes out of order. May god have mercy on my soul if I ever need to
//                 read a bunch of this...
inline char* AddStruct<char *>::Add() {
    //so this is a bad example...
    //  return strcat(a_, b_);
    //What the original template was doing was non destructive to the objects passed in
    //a_ and b_ as ints are copies. The original data is not upset and a completely new int
    //is created and returned on calling add()

    //with char* however, what strcat(a_, b_) does is append b_ to a_
    //This is a terrible example if we are trying to preserve the behavior of how it works with ints

    //Aside from creating an array of char on the heap and returning that, we have no good choice here

    //Just a peculiar example given in this lecture...

    //you know what, I'm going to change it... new result array!
    ptrResult_.reset(new char[100]{});
    strcat(ptrResult_.get(), a_);
    strcat(ptrResult_.get(), b_);
    return ptrResult_.get();

    //I know there is probably a better way to do this (maybe a specialization of std::shared_ptr<char>)
    //doing something like that would atleast allow for a handoff of who is incharge of destroying the
    //resulting char array
}


#endif
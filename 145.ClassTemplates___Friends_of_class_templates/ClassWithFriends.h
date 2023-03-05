#ifndef CLASS_WITH_FRIENDS
#define CLASS_WITH_FRIENDS
#include <iostream>

template<typename ValueType>
class ClassWithFriends
{
    //Any function taking in a class template must also be templates themselves (definition for why)
    //
    //                             ___________                                         ___________
    //friend std::ostream& operator<<<ValueType>(std::ostream& os, const ClassWithFriends<ValueType>& classWithFriends);
    //                             ^^^^^^^^^^^                                         ^^^^^^^^^^^
    //Since a template can't be a friend, only a function, we have to specify which version of the functions
    //it creates is elegible for friendship with the classes that this the class template makes
    //
    //Above you will see that the template function operator<< is provided 'ValueType' as a template parameter
    //which is ofcourse the template parameter for this class template. In addition the input parameter
    //for this function ClassWithFriends is given said same template argument

    //In short, if we have a ClassWithFriends class generated with ValueType of 'int',
    //the only friend of said class with be an opperator<< generated with that same type, 'int', that
    //takes in a const reference to a ClassWithFriends class generated with 'int' 

    //Its a little mind bendy, but I imagine I'll be quick to create these with a little practice

    //actully, because templates dont need to explicitly have their template params input if they can
    //be deduced, I bet I could leave out <ValueType> on the operator<< friend declaration... lets see

    //      friend std::ostream& operator<<(std::ostream& os, const ClassWithFriends<ValueType>& classWithFriends);

    //I am wrong, but not completely! 
    //It looks like friends of a class template are enforced to be declared clearly as a template. We can simply 
    //use an empty <> on opperator<< (DO NOT CONFUSE WITH 'template<>' format of template specialization)
    //                             __
    friend std::ostream& operator<<<>(std::ostream& os, const ClassWithFriends<ValueType>& classWithFriends);
    //                             ^^
    //Works, nice!

    private:
        ValueType value_{};
    public:
        ClassWithFriends() = delete;
        ClassWithFriends(ValueType value)
            :value_{value} {}
        ~ClassWithFriends() = default;
};

//functions taking in any class template must be templates themselves,
//taking in enough template parameters to define the class template they reference
//____________________
  template<typename T> // <-------------------------------------.
//^^^^^^^^^^^^^^^^^^^^                                          |___ (used to define class template here)
std::ostream& operator<<(std::ostream& os, const ClassWithFriends<T>& classWithFriends){
//                                                               ^^^
    return os << classWithFriends.value_;
}


//FYI, remember that in header files the order of class definition matters...
//that means the below operator<< overload couldn't be placed above the template ClassWithFriends
//because it references that template name. If you wanted to do that you'd have to forward declare
//the template.... ie

//  template<typename ValueType>
//  class TemplateClass;

//In addition you wouldn't be able to reference any member functions. So Idk why you'd do that.

//This is 1:1 the first two lines of the class template, no need for <ValueType> after 'TemplateClass'
//should be easy to remember.

#endif
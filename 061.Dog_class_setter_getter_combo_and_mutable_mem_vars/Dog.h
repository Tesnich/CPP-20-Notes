#ifndef _DOG_H
#define _DOG_H

#include <string>

class Dog {
    private :   //google recommends trailing underscores for private member variables of a class
        std::string name_;
        std::string breed_;
        int * ptrAge_;
        const unsigned int TABLE_SPACING_{15};
        mutable unsigned int printCount_{0};

    public :
        Dog() = default;
        Dog(const std::string& name, const std::string& breed, int age);
        ~Dog();

        std::string& name(); //getter and setter!           //These both return references to the string memeber variable
        const std::string& name() const;
        std::string& breed(); //getter and setter!          //  This ref can be used to change it (setter)
                                                            //  or to view its value (getter)
        int* ptrAge(); //getter and setter using pointer itself

        //The problem with this sort of functionality is that now we cant specify the getters alone as const for
        void PrintInfo() const; //  use in an instance of dog object that is const

        void ShowConstStatus () const;
        void ShowConstStatus ();
};

#endif
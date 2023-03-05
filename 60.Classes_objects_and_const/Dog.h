#ifndef _DOG_H
#define _DOG_H

#include <string>

class Dog {
    private :   //google recommends trailing underscores for private member variables of a class
        std::string name_;
        std::string breed_;
        int * ptrAge_;
        const unsigned int TABLE_SPACING_ = 15;

    public :
        Dog() = default;
        Dog(const std::string& name, const std::string& breed, int age);
        ~Dog();

        //setter
        void name(const std::string& name); //write getters and setters as overloads of methods with same name as member variable name
        //getter
        //                   allow for name() to execute when an instance of Dog object is declared const
        //                   V
        std::string name() const;

        //setter
        void breed(const std::string& breed);
        //getter
        //                   allow for breed() to execute when an instance of Dog object is declared const
        //                   V
        std::string breed() const;

        //getter
        //             allow for ptrAge() to execute when an instance of Dog object is declared const
        //             V
        int ptrAge() const;

        //                 allow for PrintInfo to execute when an instance of Dog object is declared const
        //                 V
        void PrintInfo() const;

        void ShowConstStatus () const;
        void ShowConstStatus ();
};

#endif
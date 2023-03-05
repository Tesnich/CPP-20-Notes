#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>
#include <iostream>

class Person
{
    private :
        std::string lastName_{}, firstName_{};
        unsigned int * age_{}, tableSpacing_{15};
    public :
        Person() = default;
        Person( std::string_view lastName, std::string_view firstName, unsigned int age);
        Person( std::string_view lastName, std::string_view firstName);
        Person( std::string_view lastName);

        std::string_view lastName() const;
        void lastName(std::string_view lastName);

        std::string_view firstName() const;
        void firstName(std::string_view firstName);
        
        unsigned int age() const;
        void age(unsigned int age);

        void PrintInfo();
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//PersonSmartCopy ///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class PersonSmartCopy
{
    private :
        std::string lastName_{}, firstName_{};
        unsigned int * age_{}, tableSpacing_{15};
    public :
        PersonSmartCopy() = default;
        PersonSmartCopy( std::string_view lastName, std::string_view firstName, unsigned int age);
        PersonSmartCopy( std::string_view lastName, std::string_view firstName);
        PersonSmartCopy( std::string_view lastName);

        //Lecture version of copy constructor
        PersonSmartCopy(const PersonSmartCopy& sourcePerson); //look at .cpp for definition

        //ok my version below worked, but when implementing this version I had to
        //  1.) change the input parameter type from 'PersonSmartCopy' to 'const PersonSmartCopy&'
        //          Answ.)This is because any time you pass by value you are creating a copy of the input argument
        //                The problem here is we are in the middle of defining how said copy can be created. It's a
        //                little difficult to wrap the brain around, but essentially doing so creates a circle of exectution.
        //                ie. manual call of PersonSmartCopy(PersonSmartCopy)
        //                                   calls           ^ PersonSmartCopy(PersonSmartCopy)
        //                                                     calls           ^PersonSmartCopy(PersonSmartCopy) ...
        //      The reason I dont think I had to do that below is because <typename T> will cover all variants of T
        //      Including 'const T&', which the compiler must have been smart enough to deduce for the constructor.
        //      Then again... actually didnt test with instance of self. Passed in Person class. Could be...it would have failed.
        //      WAIT! Ugh im an idiot. I didnt have a copy constructor implemented for the Person class, thus when passed in
        //            I WAS making a pass by value copy. The only reason it worked is because I didnt write a deconstructor for that class yet
        //            If I had set up delete for age the instant I call this method to copy the Person I would be deleting point to int heap
        //            as soon as SmartPersonCopy class constructor ended. Thus priming seg fault as soon as the original was destroyed.
        //            Good thing I took the time to think about this...
        //  2.) change the getters lastName(), firstName(), and age() to const. I think I understand why that was allowed now.
        //      It was because I was passing the Person class by value instead of const, so duh... they didnt need to be const.
        //      The compiler wasnt checking to make sure it was const& because really it wasn't a copy constructor I was writing.
        //
        //  Essentially what I am learning is that the code below worked because it wasnt fully tested + I didnt actually
        //  accomplish what I intended to. This raises the question,
        //              What is the proper way to write a template to copy both Person and SmartPersonCopy class objects
        //              to generate a SmartPersonCopy object. Might not be possible without having a proper copy class for Person?
        //              Without one, if the destructor was properly implemented I'm always going to cause an a memory leak.
        //              Real world situation would be to implement a copy constructor on Person and fix it. Not sure there is much
        //              I could do to... WAIT. I could simply just PASS Person by ref! Better yet, write the template below
        //              such that it ONLY accepted const &T references to the type. That should prevent explosion... let me test.

        // template <typename T>
        // PersonSmartCopy(T personObject)
        //     : PersonSmartCopy (personObject.lastName(), personObject.firstName(), personObject.age()) {}

        //Take 2 on template approach...

        template <typename T>
        PersonSmartCopy(const T& personObject)
            : lastName_(personObject.lastName()), firstName_(personObject.firstName()), age_(new unsigned int {personObject.age()})
            {
                std::cout<< std::endl << " >>Template Constructor Called!<< " << std::endl;
            }

        //still doesnt override the auto generated copy constructor, so uncommenting both works fine for what I wanted now

        ~PersonSmartCopy();

        std::string_view lastName() const;
        void lastName(std::string_view lastName);

        std::string_view firstName() const;
        void firstName(std::string_view firstName);
        
        unsigned int age() const;
        void age(unsigned int age);

        void PrintInfo();
};

#endif
#include <iostream>
#include "Person.h"
#include <iomanip>

void linebreak(std::string_view title = {}){
    std::cout << std::setw(50) << std::setfill('-') << title << std::setfill(' ') << std::endl;
}

int main(int argc, char **argv){

    //Copy constructors!

    //mechanism to define functionality when trying to create a class object from an instance of another object of said class

    //examine person.h and .cpp

    Person james("Hillman", "James");
    james.PrintInfo();

    //without special code, classes auto generate a copy constructor that copies memeber var exactly.
    //Look at the address stored in the age_ pointer... both our objects have pointers to the same location on heap!
    //This is bad!

    Person jamesDefaultCopy(james);
    jamesDefaultCopy.PrintInfo();

    linebreak();

    //However, we can write our own copy constructor to fix this issue
    //NOTE:: look at header and .ccp, attempted lecture version and my own crack at template for accepting both Person and PersonSmartCopy class objects

    PersonSmartCopy brian("Brian", "Hillman", 20);
    brian.PrintInfo();

    PersonSmartCopy brianSmartCopy(brian); //still a default dumb copy call for template?
    brianSmartCopy.PrintInfo();            //duh doy, I think by using the template the compiler doesnt realise its an overload of the copy constructor

    //Well that cinches it, adding the std::cout to the template it is obvious it is not being called.
    //My best guess is copy constructor has precedence over any other functions. Sorta like core behavior, unless
    //overriden in such a distinct copy constructor format as "SmartPersonCopy(const SmartPersonCopy& object";

    //no doubt this should work fine in non destructively copying the original Person object to a SmartPersonCopy object
    //The template would work for any input classes with lastName(), firstName(), and age(), so good multipurpose tool for that.
    //Its just not going to work as a two birds one stone approach to also defining a copy instructor...

    linebreak();
    //testing template with original person class

    Person test("Cave", "Johnson", 99);
    test.PrintInfo();

    PersonSmartCopy smartCopyTest(test);
    smartCopyTest.PrintInfo();

    linebreak();
    //ARRAYS AND COPIES OF OBJECTS

    //Objects in arrays are copies by default!

    //check this out using the bad version of the person class...

    Person pA{"AAAA","AAAA", 1};
    Person pB{"BBBB","BBBB", 2};

    //copies are created and stored in arrays
    Person students[] {pA,pB};

    pA.PrintInfo();
    students[0].PrintInfo();

    pB.PrintInfo();
    students[1].PrintInfo();

    //we can see the age_ pointers for each class point to the same spot as their originals
    //now see how the new version fixes this with use of the custom copy instructor
    linebreak();

    PersonSmartCopy pSCA{"AAAA","AAAA", 1};
    PersonSmartCopy pSCB{"BBBB","BBBB", 2};

    //copies are created and stored in arrays
    PersonSmartCopy students2[] {pSCA,pSCB,PersonSmartCopy("CCCC","CCCC", 3)}; //Note that the compiler is smart enough not to make this object then copy it
                                                                               //The object will be created in place in the array, so no copy function will be called on this last object
    pSCA.PrintInfo();
    students2[0].PrintInfo();

    pSCB.PrintInfo();
    students2[1].PrintInfo();

    //we can even see in the terminal output where the std::cout inside the custom copy constructor is executing

    //The same thing goes for for range loops, we can change this by using references or pointers though, just like any other loop on data

    //pointers to existing objects
    PersonSmartCopy* students3[] {&pSCA,&pSCB}; //references not allowed in arrays so need to use pointers here...
                                                //this is because c++ does not see references as objects, but aliases
                                                //c++ standard declares : 
                                                //      There shall be no references to references, NO ARRAYS OF REFERENCES,
                                                //      and no pointers to references

    //ranged based for loops will also copy, but you should already know that
    //it can be avoided by denoting each element in the range as a ref
    //                       v
    //              for (auto& element : array) {...}
    //                       ^

    //shallow copy (member wise copy) vs deep copy -> wording explanation

    //shallow copy is what the default copy instructor does. A surface level copy of the values in the member variables. (pointer addresses copied)

    //a deep copy is what our manually implemented copy constructor does, allocating new memory for pointers to data (setting the pointer age to a new int on the heap, then setting its value)

    return 0;
}
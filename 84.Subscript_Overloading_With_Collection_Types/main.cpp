#include <iostream>
#include "Scores.h"

int main(int argc, char **argv){

    //Subscript operator overloading with collection types
    //(if you are looking for normal subscript overloading check previous folder)

    BookKeeping::Scores mathScores("Math Class", 20);
    //non-const version of operator[] template overload called
    for(unsigned int i{0}; i<20; ++i)
        mathScores[i] = i*10;

    mathScores.PrintAllScores();

    const BookKeeping::Scores permanentMathScores{mathScores}; //shallow copy, watch your step

    //const version of operator[] overload called here
    for(unsigned int i{0}; i<20; ++i)
        std::cout<<permanentMathScores[i] << " ";
    std::cout<< std::endl;

    
    //overloading the stream insertion operator aka. '<<' so we can print an object
    //implemted on the scores class

    //these are usually set up as non-member functions...explained in .cpp
    std::cout << "result of 'std::cout << permanentMathScores << std::endl; : " << permanentMathScores << std::endl;
    std::cout << "NEWLINE" << std::endl;

    //overloading the input stream operator aka. '>>' so we can take from cin directly into an object
    //implemented on the scores class

    std::cout << "Please enter some numbers :";
    std::cin >> mathScores;
    std::cout << mathScores;

    
    //other arithmatic operations

    //just because you can overload an operator doesn't mean it makes sense. Think in respect to
    //the components you are building. Does it make sense to add, subtract, multiply, or even divide
    //objects of these classes?

    //this can extend to compound arthimetic like +=, -=, *=
    
    //Any of these can be implemented on a class, but what is important is to write such functionality
    //if it is obvious to the user what doing such an operation would do in respect to the class' data.

    return 0;
}
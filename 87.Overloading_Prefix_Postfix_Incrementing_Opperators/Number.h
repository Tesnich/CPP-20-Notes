#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
class Number{
    friend std::ostream& operator<<(std::ostream& os, const Number& number);
    //friend Number& operator++(Number& number);
    //friend Number& operator++(Number& number,int);
    private :
        int intVal_{};
    public :
        Number() = delete;
        Number(int intVal)
            :intVal_{intVal} {}
        
        //prefix overload (remember this is ++var, so it increments then returns updated value)
        Number& operator++(){
            ++intVal_;
            return *this;
        }

        //postfix overload (remember this is var++, so it copys curent state, increments the given object, and returns copy of old state)
        //format is a little wonky... to achieve this overload we need to put in a 'dummy int' as an argument
        //this serves as nothing more than a flag to let the compiler know this is a post fix overload
        //you will just have to remember this since there is no decent logic behind it...
        Number operator++(int){
            Number oldNum(*this); //shallow copy here because no heap data
            ++intVal_; //update passed in value (this doesnt have to match the pattern var++ of post fix since returned value goes unused in this statement, this is faster)
            return oldNum; //return state of object before it was incremented
        }
};

//even though the above are unary operators they could easily be implemented as non-member functions if
//you so desire

//prefix non-member
//in cases of a unary operator with no arguments, what we provide as an argument is just the lhs opperand
//so the reference to the Number instance we are using ++ on in this case
//
// inline Number& operator++(Number& number){ //uncomment friend declaration above!
//     ++number.intVal_;
//     return number;
// }

//postfix non-member
//to implement the post fix unary opperator as a non member the dummy int we supplied above goes as a second argument
//again, a little strange so youll just have to remember this or look it up if you need to implement this overload
//
// inline Number& operator++(Number& number,int){ //uncomment friend declaration above!
//     Number oldNum(number);
//     ++number.intVal_; 
//     return oldNum;
// }

inline std::ostream& operator<<(std::ostream& os, const Number& number){
    os << number.intVal_;
    return os;
}

#endif
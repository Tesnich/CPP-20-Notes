#ifndef DIVIDE_BY_ZERO_EXCEPTION_H
#define DIVIDE_BY_ZERO_EXCEPTION_H
#include <exception>
#include <iostream>
#include <sstream>

template<typename T>
class DivideByZeroException : public std::exception //peak at exception here to see what needs to be implemented in override
{
    protected:
        T a_{}, b_{};
    public:
        DivideByZeroException() = delete;
        DivideByZeroException(T a, T b)
            :a_{a}, b_{b} {}
        ~DivideByZeroException() = default;

        virtual const char* what() const noexcept override{
            std::string msg{"Dividing By Zero :"};
            msg+= (std::to_string(a_) += " / ") += std::to_string(b_); //This is stupid code! 
            return msg.c_str(); //the c_str we return here is going to be pointing to invalid memory, we will get junk
            //really the std::exception class must have counted on literals here
        }

        T a() {return a_;}
        T b() {return b_;}
};

#endif
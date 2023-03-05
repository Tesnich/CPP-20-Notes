#ifndef WRAPPER_H
#define WRAPPER_H
#include<iostream>

template <typename T>
class Wrapper {
    private :
        T wrappedValue_{};
    public :
        Wrapper() = default;
        Wrapper(T wrappedValue)
            :wrappedValue_{wrappedValue} {}
        
        //normal accessor
        T wrappedValue() const{
            return wrappedValue_;
        }
        void wrappedValue(T wrappedValue){
            wrappedValue_ = wrappedValue;
        }

        //operator overloads
        Wrapper& operator= (T replacementValue){
            wrappedValue_ = replacementValue;
            return *this;
        }

        Wrapper& operator+= (T suplementalValue){
            wrappedValue_ += suplementalValue;
            return *this;
        }

        Wrapper operator+ (T suplementalValue) const{
            Wrapper<T> newWrapper(wrappedValue_);
            newWrapper += suplementalValue;
            return newWrapper;
        }

        //      << New This Lecture >>

        //logical operator overloads (old method)
        //these types often return bool, which is expected by most programers
        bool operator< (const Wrapper<T>& wrapperB) const {
            return (wrappedValue_ < wrapperB.wrappedValue_);
        }

        //not really needed with as simple as this class is,
        //but I have the operator<= overload calling the operator< I wrote above
        bool operator<= (const Wrapper<T>& wrapperB) const {
            if (wrappedValue_ == wrapperB.wrappedValue_)
                return true;
            return *this < wrapperB;
        }

        //format above would be fine for setting up for >, >=, ==, !=...
};

//non-member example of == overload

template <typename T>
inline bool operator== (const Wrapper<T>& wrapperA, const Wrapper<T>& wrapperB){
    return wrapperA.wrappedValue() == wrapperB.wrappedValue();
}

template <typename T>
inline std::ostream& operator<< (std::ostream& os, const Wrapper<T>& wrapper){
    os << wrapper.wrappedValue();
    return os;
}

#endif
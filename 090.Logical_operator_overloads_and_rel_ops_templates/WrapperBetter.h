#ifndef WRAPPER_BETTER_H
#define WRAPPER_BETTER_H
#include<iostream>

template <typename T>
class WrapperBetter {
    private :
        T wrappedValue_{};
    public :
        WrapperBetter() = default;
        WrapperBetter(T wrappedValue)
            :wrappedValue_{wrappedValue} {}
        
        //normal accessor
        T wrappedValue() const{
            return wrappedValue_;
        }
        void wrappedValue(T wrappedValue){
            wrappedValue_ = wrappedValue;
        }

        bool operator< (const WrapperBetter<T>& wrapperB) const {
            return (wrappedValue_ < wrapperB.wrappedValue_);
        }

        bool operator== (const WrapperBetter<T>& wrapperB) const {
            return wrappedValue_ == wrapperB.wrappedValue();
        }
};

template <typename T>
inline std::ostream& operator<< (std::ostream& os, const WrapperBetter<T>& wrapper){
    os << wrapper.wrappedValue();
    return os;
}

#endif
#ifndef CONSTRUCTOR_WATCH_H
#define CONSTRUCTOR_WATCH_H
#include <iostream>

template <typename ValueType>
class ConstructorWatch
{
    friend std::ostream& operator<<<>(std::ostream& os, const ConstructorWatch<ValueType>& constructorWatch);

    private:
        ValueType* value_{};
    public:
        ConstructorWatch();
        ConstructorWatch(ValueType value);
        ConstructorWatch(const ConstructorWatch<ValueType>& source);
        //move constructor
        //obviously this is a destructive call so source is not const
        ConstructorWatch(ConstructorWatch<ValueType>&& source);

        ~ConstructorWatch();

        ConstructorWatch<ValueType>& operator= (const ConstructorWatch<ValueType>& source);
        //move assignemnt
        //obviously this is a destructive call so source is not const
        ConstructorWatch<ValueType>& operator= (ConstructorWatch<ValueType>&& source);
        ConstructorWatch<ValueType>& operator+= (const ConstructorWatch<ValueType>& source);
        ConstructorWatch<ValueType> operator+ (const ConstructorWatch<ValueType>& source);
};

template<typename ValueType>
ConstructorWatch<ValueType>::ConstructorWatch()
    :ConstructorWatch(ValueType{}) {}

template<typename ValueType>
ConstructorWatch<ValueType>::ConstructorWatch(ValueType value)
    :value_{new ValueType{value}} {
        std::cout << "ConstructorWatch Constructor Called!\n";
    }

template<typename ValueType>
ConstructorWatch<ValueType>::ConstructorWatch(const ConstructorWatch<ValueType>& source)
    :ConstructorWatch(*source.value_) {
        std::cout << "ConstructorWatch Copy Constructor Called!\n";
    }

//move construction
//obviously this is a destructive call so source is not const
template<typename ValueType>
ConstructorWatch<ValueType>::ConstructorWatch(ConstructorWatch<ValueType>&& source){
    std::cout << "Move Constructor Called!\n";
    //because we are setting up a move assignment, we can leverage that here to
    //facilitate code re-use instead of duplication!
    *this = std::move(source);
}

template<typename ValueType>
ConstructorWatch<ValueType>::~ConstructorWatch() {
    std::cout << "ConstructorWatch Destructor Called! <-----------\n";
};

template<typename ValueType>
ConstructorWatch<ValueType>& ConstructorWatch<ValueType>::operator= (const ConstructorWatch<ValueType>& source){
    *value_ = *source.value_;
    std::cout << "ConstructorWatch (=) Called!\n";
    return *this;
}

//move assignemnt
//obviously this is a destructive call so source is not const
template<typename ValueType>
ConstructorWatch<ValueType>& ConstructorWatch<ValueType>::operator= (ConstructorWatch<ValueType>&& source){
    std::cout << "Move Constructor Called!\n";
    //remember that when creating a move from ones self we would end up voiding
    //data we want to use
    if (this != &source){
        value_ = source.value_; //we avoid a copy of the object held by stealing it
        source.value_ = nullptr; //now the old one has no reference to the object, but that is ok because we expect it to die
    }
    return *this;
}

template<typename ValueType>
ConstructorWatch<ValueType>& ConstructorWatch<ValueType>::operator+= (const ConstructorWatch<ValueType>& source){
    value_ += *source.value_;
    std::cout << "ConstructorWatch (+=) Called!\n";
    return *this;
}

template<typename ValueType>
ConstructorWatch<ValueType> ConstructorWatch<ValueType>::operator+ (const ConstructorWatch<ValueType>& source){
    ConstructorWatch tempConstructorWatch(*this);
    tempConstructorWatch += source;
    std::cout << "ConstructorWatch (+) Called!\n";
    return tempConstructorWatch;
}

template<typename ValueType>
std::ostream& operator<<(std::ostream& os, const ConstructorWatch<ValueType>& constructorWatch){
    os << *constructorWatch.value_;
    return os;
}

#endif
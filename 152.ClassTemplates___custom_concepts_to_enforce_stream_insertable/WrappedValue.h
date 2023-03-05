#ifndef WRAPPED_VALUE_H
#define WRAPPED_VALUE_H
#include <ostream>

template<typename ValueType>
concept CanBeStreamInsertable = requires (std::ostream& os, ValueType value){
    os << value;
};

//in the lecture CanBeStreamInsertable concept is actually used on the operator<< overload...
//(I like it better here because this is where programmers using this class will look!)
//(plus build failure is way shorter ;P )
//template<CanBeStreamInsertable ValueType>
template<typename ValueType>
class WrappedValue
{
    friend std::ostream& operator<<<>(std::ostream& os, const WrappedValue<ValueType>& wrappedValue);

    private:
        ValueType value_{};
    public:
        WrappedValue() = delete;
        WrappedValue(ValueType value)
            :value_{value} {}
        ~WrappedValue() = default;
};

//CanBeStreamInsertable concept used below
template <CanBeStreamInsertable ValueType>
inline std::ostream& operator<<(std::ostream& os, const WrappedValue<ValueType>& wrappedValue){
//         _________________________ Problem if ValueType is custom object that does not overload << operator
    return os << wrappedValue.value_;
//         ^^^^^^^^^^^^^^^^^^^^^^^^^
}

//There is nothing going on in this class, but most importantly << doesnt work with it
class VapidClass{
    public:
        VapidClass() = default;
        ~VapidClass() = default;
};

#endif
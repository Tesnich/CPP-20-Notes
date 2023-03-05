#ifndef MAP_H
#define MAP_H
#include <type_traits>

template <typename T, typename P>
struct Map
{
    //For type trait functions
    //  https://en.cppreference.com/w/cpp/header/type_traits

    // My Code ///////////////////////////////////////
    static_assert(std::is_integral<T>::value, "Map keys must be integral type");
    static_assert(std::is_same<P,std::string>::value == true, "Map values must be std::string type");
    //////////////////////////////////////////////////

    private : 
    
        T m_key;
        P m_value;
    public : 
        Map(T key, P value)
         : m_key(key), m_value(value)
        {}
};

#endif
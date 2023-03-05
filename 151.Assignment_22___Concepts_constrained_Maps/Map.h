#ifndef MAP_H
#define MAP_H
#include <concepts>

template <typename T, typename P>
//// My Code ////////////////////////////////////////////////////////////
requires std::is_integral<T>::value && std::is_same<P,std::string>::value
//// My Code ////////////////////////////////////////////////////////////
struct Map
{
    private : 
        friend std::ostream& operator<< <>  (std::ostream& out, const Map<T,P>& operand);
        T m_key;
        P m_value;
    public : 
        Map(T key, P value)
         : m_key(key), m_value(value)
        {}
};

template < typename T, typename P> 
std::ostream& operator<<(std::ostream& out, const Map<T,P>& operand){
    out << "Map : [" << operand.m_key 
        << "," << operand.m_value << "]";
    return out;
}

#endif
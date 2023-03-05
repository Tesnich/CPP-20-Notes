#ifndef MAP_H
#define MAP_H
#include <ostream>

//I dont understand why people are forward declaring here.
//Is it simply to facilitate good readability?

template <typename T, typename P>
struct Map
{
private : 
    friend std::ostream& operator<< <> (std::ostream&, const Map<T,P>&);

    T m_key;
    P m_value;
public : 
    Map(T key, P value)
     : m_key(key), m_value(value)
    {}
};

//my code ///////////////////////////////////////
template<typename T, typename P>
inline std::ostream& operator<<(std::ostream& os, const Map<T,P>& map){
    return os << "Map : ["<<map.m_key<<","<<map.m_value<<"]";
}
/////////////////////////////////////////////////

#endif
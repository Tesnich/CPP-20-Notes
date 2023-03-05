#ifndef POINT_H
#define POINT_H
#include <ostream>
#include <sstream>

template <typename T = int , unsigned int size = 2>
class Point{
    //my code ///////////////////////////////////////
    friend std::ostream& operator<<<> (std::ostream& os, const Point<T,size>& point);
    /////////////////////////////////////////////////
    protected:
        T m_components[size];
    public :
        unsigned int get_size() const{
            return size;
        }
        void set_value(unsigned int index, T value){
            m_components[index] = value;
        }
};

//my code ///////////////////////////////////////
template<typename T, unsigned int size>
inline std::ostream& operator<< (std::ostream& os, const Point<T,size>& point){
    std::stringstream ss;
    ss << "Point : [ dimension : "<<size<<", components : ";
    for(unsigned int i{}; i < size; ++i){
        ss << point.m_components[i] <<" ";
    }
    ss<<"]";
    return os << ss.str();
}
/////////////////////////////////////////////////

#endif
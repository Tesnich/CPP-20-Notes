#ifndef POINT_H
#define POINT_H
#include <ostream>
#include <type_traits>
#include <initializer_list>
#include <memory>

template<typename ValueType = int>
class Point
{
//  ____________________________________________________________________________________________
    static_assert(std::is_arithmetic_v<ValueType>, "Coordinates of Point can only be numbers.");
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//  Use of static_assert here terminates compilation in the event ValueType is use with a non
//  arithmetic type. (No strings)

    friend std::ostream& operator<<<>(std::ostream& os, const Point<ValueType>& point);

    private:
        long unsigned int DIMENSIONS_{2};
        std::unique_ptr<ValueType[]> ptrValues_{};
    public:
        Point() = delete;
        Point(std::initializer_list<ValueType> valueList)
            :DIMENSIONS_{valueList.size()}, ptrValues_{new ValueType[DIMENSIONS_]{}} {
                for (unsigned int i{}; i< DIMENSIONS_; ++i){
                    ptrValues_[i] = *(valueList.begin()+i);
                }
            }
        ~Point() = default;
};

template<typename ValueType>
inline std::ostream& operator<<(std::ostream& os, const Point<ValueType>& point){
    os << "Point : [ dimension : "<<point.DIMENSIONS_<<", components : ";
    for(unsigned int i{}; i < point.DIMENSIONS_; ++i){
        os << point.ptrValues_[i] <<" ";
    }
    return os<<"]";
}

#endif
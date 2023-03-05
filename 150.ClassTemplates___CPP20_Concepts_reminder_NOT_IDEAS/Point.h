#ifndef POINT_H
#define POINT_H
#include <ostream>
#include <initializer_list>
#include <memory>
#include <concepts> //looks like this will build/fail build with either <concepts> or <type_traits>
                    //however, use of concepts will provide us a pretty failure log for the build
                    //clearly siting that the reason for failure is '10 | requires std::is_arithmetic_v<ValueType>'
template<typename ValueType = int>
//______________________________________CPP TEMPLATE CONCEPTS
requires std::is_arithmetic_v<ValueType>
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
class Point
{

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
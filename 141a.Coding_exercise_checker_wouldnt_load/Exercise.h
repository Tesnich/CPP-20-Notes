#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <memory>
#include <sstream>

//YOUR CODE WILL GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE.

template<typename ValueType, unsigned int DIMENSIONS>
class Point {
    protected:
        std::unique_ptr<ValueType[]> ptrValues_{};
    public:
        Point()
            :ptrValues_{new ValueType[DIMENSIONS]{}} {}
        void set_value(unsigned int index, ValueType value){
            ptrValues_[index] = value;
        }
        void print_info(){
            std::stringstream ss;
            ss << "point [ ";
            for(unsigned int i{}; i < DIMENSIONS; ++i){
                ss << ptrValues_[i]<<" ";
            }
            ss << "]";
            std::cout << ss.str();
        }
        ValueType get_value(unsigned int index){
            if(index > DIMENSIONS -1)
                throw std::out_of_range("Tried to read out of range.");
            return ptrValues_[index];
        }
};

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE

#endif // _EXERCISE_H
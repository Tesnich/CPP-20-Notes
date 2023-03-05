#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>
#include <cstring>

template <typename T>
struct Map
{
	T m_key;
	T m_value;
	Map(T key, T value)
	 : m_key(key), m_value(value)
	{}
	bool compare_to( const Map& other) const{
		return (m_key == other.m_key)&&(m_value == other.m_value);
	}
   
	void print_info() const{
		std::cout << "map [";
		std:: cout << m_key << "," << m_value;
		std::cout << "]";
	}
    
};

//YOUR CODE SHOULD GO BELOW THIS LINE
//DON'T MODIFY ANYTHING ABOVE THIS LINE

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE.
#endif // _EXERCISE_H

#include "exercise.h"
//YOUR CODE WILL GO BELOW THIS LINE - THE INCLUDES YOU NEED WILL SHOW UP BELOW THIS LINE AS WELL
//DON'T MODIFY ANYTHING ABOVE THIS LINE

template<>
bool Map<const char *>::compare_to(const Map<const char*>& other) const {
    return strcmp(m_key, other.m_key) == 0 && strcmp(m_value, other.m_value) == 0;
}

//YOUR CODE WILL GO ABOVE THIS LINE
//DON'T MODIFY ANYTHING BELOW THIS LINE.
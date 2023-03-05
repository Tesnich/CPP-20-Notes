#ifndef COMPARABLE_STRING_H
#define COMPARABLE_STRING_H
#include <cstring>
#include <string>

class ComparableString {
    private :
        std::string strVal_{};
    public :
        ComparableString() = default;
        ComparableString(std::string_view strView)
            :strVal_(strView) {}
        
        //operator overloads

        //we use weak_ordering because we intend on passing back results in reference to string size,
        //not their actual value
        std::weak_ordering operator<=> (const ComparableString& compStringB) const {
            if (strVal_.length() < compStringB.strVal_.length())
                return std::weak_ordering::less;
            else if (strVal_.length() > compStringB.strVal_.length())
                return std::weak_ordering::greater;
            else
                return std::weak_ordering::equivalent; //as long as the size is the same it is equivalent!

            //the above could probably be improved by using std::strong_ordering instead, and changing the above
            //to also include a return of the value std::strong_ordering::equal if the string are identical.

            //Since we don't really care about that though (not planning on changing program from if they are equal)
            //weak_ordering works fine here and conveys the intent that we do not plan on ever checking for
            //the exact same values.
        }

        //remember that in setting up a custom <=> overload, == is not automatically generated for us
        bool operator==(const ComparableString& compStringB) const {
            return (*this <=> compStringB) == std::weak_ordering::equivalent;
        }
};

#endif
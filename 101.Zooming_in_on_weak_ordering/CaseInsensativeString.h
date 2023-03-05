#ifndef CASE_INSENSATIVE_STRING_H
#define CASE_INSENSATIVE_STRING_H
#include <cstring>
#include <string>

class CaseInsensativeString {
    private :
        std::string strVal_{};
        std::string StandardizeToUpperCase(std::string_view strView) const {
            std::string tempString(strView);
            for(auto& c : tempString){
                c = toupper(c);
            }
            return tempString;
        }
    public :
        CaseInsensativeString() = default;
        CaseInsensativeString(std::string_view strView)
            :strVal_(strView) {}
        
        //operator overloads

        //we use weak_ordering because we intend on passing back results in reference to strings' contents regardless of case,
        //not absolute equality
        std::weak_ordering operator<=> (const CaseInsensativeString& caseInsStrB) const {
            auto cmpRes{StandardizeToUpperCase(strVal_).compare(StandardizeToUpperCase(caseInsStrB.strVal_))};
            if (cmpRes < 0) //lexigraphical comparison between standardized characters ie.. 'A' is less than 'B'
                return std::weak_ordering::less;
            else if (cmpRes > 0) //lexigraphical comparison between standardized characters ie.. 'B' is greater than 'A'
                return std::weak_ordering::greater;
            else //lexigraphical comparison between standardized characters turns up no differences
                return std::weak_ordering::equivalent;

            //strong_ordering could be used if we added an additional check for comparison between strVal_ and caseInsStrB.strVal_
        }

        //remember that in setting up a custom <=> overload, == overload is not automatically generated for us
        bool operator==(const CaseInsensativeString& compStringB) const {
            return (*this <=> compStringB) == std::weak_ordering::equivalent;
        }
};

#endif
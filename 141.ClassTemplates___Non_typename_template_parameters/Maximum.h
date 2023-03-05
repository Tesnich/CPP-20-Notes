#ifndef MAXIMUM_H
#define MAXIMUM_H
#include <string>

template<typename ValType, ValType MAX> //<- Non typename parameters dont have to be same type as typename, you could make them ints for all I care
class Maximum {
    protected:
        ValType value_{};
    public:
        Maximum() = default;
        Maximum(ValType value)
            :value_{value} {
                //Non type template parameters are essentially baked into the class as a const
                //You can read them from inside the class
                std::cout<<"MAX : " << MAX << "\n";
                //but there is no way to change them after creating an instance (more specifically a class has been defined from the template)
                //++MAX;
            }
        std::string_view Status(){
            return (value_ > MAX)? "STORED VALUE EXCEEDS MAX" : "Stored Value Under Max Limit";
        }
};

#endif
#ifndef FUNCTOR_CLASS_H
#define FUNCTOR_CLASS_H
#include <string_view>
#include <iostream>

class FunctorClass {
    private :
    public :
        FunctorClass() = default;

        //functor overload for '()' operator is written just like with '+' or any other operator
        //            follows the operator keyword and before input params
        //            |
        //            V
        void operator() (std::string_view input){
            std::cout<<"Functor overload on FunctorClass called with '"<<input<<"'"<<std::endl;
        }

        //This can be overloaded like any other operator with any return type or number of input parameters

        void operator() (std::string_view input, std::string_view input2){
            std::cout<<"Functor overload on FunctorClass called with '"<<input<<"' and '"<< input2 <<"'"<<std::endl;
        }
};

#endif
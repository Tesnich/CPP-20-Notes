#ifndef TEMPLATE_FUNCTIONS_H
#define TEMPLATE_FUNCTIONS_H

#include <string.h>

namespace TemplateFunctions {

    template<typename T>
    using CompareFunction = bool(*)(const T&, const T&); //you can templatize type name aliases...?
    //   essentially what the above has done is defined compare_T as
    //   a template pointer to a function. Given a different T, compare_T
    //   could reference functions comparing anything from bools to doubles..

    //below is a template function called compareItems, where as its return type and inputs are determined by typename T
    template<typename T>
    T compareItems(const T& a, const T& b, CompareFunction<T> compareFunction){
    //as you can see we have made it so that this function takes in two objects of the same type as well as
    //the CompareFunction template pointer with set with the same type.
        return (compareFunction(a, b))? a : b;
    //the compareFunctions we have created are isLarger and isSmaller. These must also be templated inorder for this
    //situation to work. Look below.
    }

    template<typename T>
    bool isLarger(const T& a, const T& b){
        return a > b;
    }

    template<typename T>
    bool isSmaller(const T& a, const T& b){
        return a < b;
    }

    //Since we made the CompareFunction type a template we can make use of these above template comparing functions!

    //SIDE NOTE : I am pretty sure that using a type alias here, while not strickly necessary, helps us format
    //the template function referencing this callback easily without having to define templates within templates
    //cluttering what is really pretty easily read code. Count it as essential formatting for the sake of sanity.

    //specialization of isLarger and isSmaller for strings functionality (comparing string length)
    template<>
    inline bool isLarger<std::string> (const std::string& a, const std::string& b){
        return a.length() > b.length();
    }

    template<>
    inline bool isSmaller<std::string> (const std::string& a, const std::string& b){
        return a.length() < b.length();
    }

}

#endif
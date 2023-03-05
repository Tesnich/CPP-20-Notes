#ifndef FUNCTIONS
#define FUNCTIONS

//maximum template definition
template <typename T> T maximum (T a, T b)
{
    std::cout << "**** Original Template Definition Ran!" << std::endl;
    return (a > b)? a : b;
}

//declaration for a maximum overload
//this template takes precedence over the original maximum when pointer of any kind passed in
//consider this a seperate template than that on line 5, like overloaded functions
template <typename T> T* maximum(T* a, T* b)
{
    std::cout << "**** Overloaded Template Definition Ran!" << std::endl;
    return (*a > *b)? a: b;
}

//declaration for raw overload for maximum, this will take precedence over ANY template with matching type
const char * maximum (const char * a, const char * b);  //so this will be used before the above overloaded template!

//something interesting to note,
//the precedence order is as follows...

//raw overload normal functions -> templated overloads that match -> specialized template that match -> template

//if you do a template specialization on a template that also has a template overload, if the template overload matches
//the given type(s) then it will run regardless if you have writen a matching specialization

//think of it like this

//  LEVEL 1                     TEMPLATE                TEMPLATE OVERLOAD
//  LEVEL 2              TEMPLATE SPECIALIZATION

//specialization resolution happens after the correct template has been selected, if the template overload selected
//has no specialization it goes with the definiton for that template. If the template overload selected HAS specials
//then it will determine if any apply, and subsequently use the specialization definition. 

//I dont really want to deep dive here, but this pecking order is something to keep in mind when 
//dealing writing complex templates

//Refer to this link if you need a refresher : https://stackoverflow.com/questions/7108033/template-specialization-vs-function-overloading/7108123#7108123


#endif //FUNCTIONS
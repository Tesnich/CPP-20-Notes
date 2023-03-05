#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>

void LineBreak(std::string_view title);

void IncreaseAgeBy10Years(unsigned int age); //passing by value
void ImutableAge(const unsigned int age); //passing by const value
void IncreaseAgeBy10YearsWithPointer(unsigned int * age); //passing by pointer (edit value in main scope value)
void IncreaseAgeBy10YearsWithPointerToConst(const unsigned int * age); //passing by pointer to const
void IncreaseAgeBy10YearsWithConstPointerToConst(const unsigned int * const age); //passing by const pointer to const
void IncreaseAgeBy10YearsByReference(unsigned int & age); //passing by reference (edit value in main scope value)
void IncreaseAgeBy10YearsByConstReference(const unsigned int & age); //passing by const reference

int main(){

    //passing by value
    LineBreak("Pass By Value");

    unsigned int age{17};
    std::cout << "age before method : " << age << std::endl;
    IncreaseAgeBy10Years(age); //This pass by value should not change the value of age in the main scope
    std::cout << "age after method  : " << age << std::endl;

    LineBreak("Pass By Const Value");

    ImutableAge(age);

    LineBreak("Pass By Pointer");

    unsigned int * pointerToAge{&age};

    std::cout << "age before method : " << age << std::endl;
    IncreaseAgeBy10YearsWithPointer(&age); //providing the address of age
    //IncreaseAgeBy10YearsWithPointer(pointerToAge); //this would also have worked
    std::cout << "age after method  : " << age << std::endl;

    LineBreak("Pass By Pointer To Const");

    IncreaseAgeBy10YearsWithPointerToConst(&age);
    //IncreaseAgeBy10YearsWithPointer(pointerToAge); //this would also have worked

    LineBreak("Pass By Const Pointer To Const");

    IncreaseAgeBy10YearsWithConstPointerToConst(pointerToAge);

    LineBreak("Pass By Reference");

    std::cout << "age before method : " << age << std::endl;
    IncreaseAgeBy10YearsByReference(age);
    std::cout << "age after method  : " << age << std::endl;

    LineBreak("Pass by Const Reference");

    IncreaseAgeBy10YearsByConstReference(age);

    return 0;
}

void LineBreak(std::string_view title)
{
    std::cout <<std::endl<< std::left << "--" << std::setw(50) << std::setfill('-') << title << std::setfill(' ') << std::right <<std::endl;
}

void IncreaseAgeBy10Years(unsigned int age) //passing by value means that this age here is a COPY of the age we provided
{
    std::cout << "Time is passing..." << std::endl;
    age += 10; // changes to the copy in this scope will NOT change the age in main
    std::cout << "Age in function is now : " << age << std::endl;
}

void ImutableAge(const unsigned int age)
{
    //illegal!
    //age += 10;
    std::cout << "This function can't change the age at all!" << std::endl;
}

void IncreaseAgeBy10YearsWithPointer(unsigned int * age)
{
    std::cout << "Time is passing..." << std::endl;
    *age += 10;
    std::cout << "Age in function is now : " << *age << std::endl;
}

void IncreaseAgeBy10YearsWithPointerToConst(const unsigned int * age) //this is handy for being efficient in memory for things you dont want to edit!
{
    //illegal!
    //*age += 10;
    std::cout << "This function can't change the age at all!" << std::endl;
}

void IncreaseAgeBy10YearsWithConstPointerToConst(const unsigned int * const age) //this is handy for being efficient in memory for things you dont want to edit!
{
    //illegal!
    //*age += 10;
    unsigned int tempInt{15};
    //illegal!
    //age = &tempInt;
    std::cout << "This function can't change age NOR where the pointer pointerToAge points! Read Only bub!" << std::endl;
}

void IncreaseAgeBy10YearsByReference(unsigned int & age) //this age is an alias to the original!
{
    std::cout << "Time is passing..." << std::endl;
    age += 10; // changes to age here are actually changes to age in main!
    std::cout << "Age in function is now : " << age << std::endl;
}

void IncreaseAgeBy10YearsByConstReference(const unsigned int & age) //this is handy for being efficient in memory for things you dont want to edit!
{
    //illegal!
    //age += 10;
    std::cout << "This function can't change the age at all!" << std::endl;
}

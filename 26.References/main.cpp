#include <iostream>

int main(){
    
    //references

    int normalInt {25};
    // VVVV References denoted by & during variable declaration
    int& refToNormalInt {normalInt}; // references need to be initialized at the time of declaration
                                     // You cannot reference nothing!
    std::cout << "Normal Int        : " << normalInt << std::endl;
    std::cout << "Ref to Normal Int : " << refToNormalInt << std::endl;
    std::cout << ">> ref += 5 <<" << std::endl;
    refToNormalInt += 5; //alterations to ref effect the original
    std::cout << "Normal Int        : " << normalInt << std::endl;
    std::cout << "Ref to Normal Int : " << refToNormalInt << std::endl;
    std::cout << ">> normal += 5 <<" << std::endl;
    normalInt += 5; //alterations to the original effect the references
    std::cout << "Normal Int        : " << normalInt << std::endl;
    std::cout << "Ref to Normal Int : " << refToNormalInt << std::endl;
    std::cout << ">> normal += 5 <<" << std::endl;

    //The variables and references made from them SHARE MEMORY LOCATION, essentially just an alias for the original variable name
    std::cout << "Normal Int Address        : " << &normalInt << std::endl;
    std::cout << "Ref to Normal Int Address : " << &refToNormalInt << std::endl;

    //Ref vs Pointers

    //Ref -----------------------------
    //Dont need to dereference pointers to access value
    //Refs cant be changed to reference something else
    //Refs must be initialized at declaration

    //Const references

    const int& constRefNormalInt{normalInt}; //reference to normalInt that you can not edit, its like turning normalInt into const if you only had access to this reference

    const int constNormalInt {12};

    //int& refToConstNormalInt {constNormalInt}; //illegal! if base variable is a const, ref has to match
    const int & constRefToConstNormalInt {constNormalInt};

    //ref are great for modifying values in a range based for loop

    int scores[] {1,2,3,4,5,6,7,8,9};

    for (const int & score : scores)
        std::cout << "-> " << score << std::endl;

    for (int& score : scores)
    {
        score *= 10;
    }

    for (const int & score : scores)
        std::cout << "-> " << score << std::endl;

    return 0;
}
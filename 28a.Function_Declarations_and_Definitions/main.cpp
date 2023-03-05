#include <iostream>

//Function DECLARATION  ...  also known as PROTOTYPE
int max(int a, int b);  //  Having this will allow you to place your method functionality below where it is referenced (in doc), basically tells the compiler it exists and to go look for it
                        //  It is something easy to look at that gives a good idea of what the input arguments are and what the output type is
                        //  If names are selected properly, it becomes its own documentation!

int min(int, int); // Function names are NOT REQUIRED for a declaration, simply the types will do!
                   // HOWEVER, naming them is good practice and recommended to give readers insight into functionality!

int main(){

    //Sometimes it's more flexible to split the function into it's header and body and keep the code ofr each in different places

    int a{3};
    int b{4};
    
    std::cout << "max(" << a <<","<< b <<") : "<< max(a,b) << std::endl;
    std::cout << "min(" << a <<","<< b <<") : "<< min(a,b) << std::endl;

    return 0;
}

//function DEFINITION   ...  implementation
int max(int a, int b)                  //  If the definition is placed before the declaration it serves as both the declaration and definition
{                                       //  There would be no point in having the declaration at that point
    return (a>b)? a : b;
}

int min(int a, int b)
{
    return (a<b)? a : b;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>

void printSum(int a, int b);
void incrementWithReferences(int& a, int& b);
void printSumPointer(int* a, int* b);
void sayMyName(std::string& name);
void sayMyNameStringView(std::string_view name);

int main(){
    
    int a{10}, b{20};
    printSum(a,b);

    double c{30.5}, d{40.5};
    std::cout << "Doubles are " << c << " and " << d << " with sizeof(double) " << sizeof(double) << std::endl;
    //implicit conversion
    printSum(c,d); // doubles are converted implicitly to int parameters of this method
                   // data lost! If this wasnt intended, it can cause problems!

    incrementWithReferences(a,b);
    std::cout << "a : " << a << "  and b : " << b << std::endl;

    //Illegal!!
    //incrementWithReferences(c,d); //compiler error! The reference & for a and b input parameters force match of type
                                  //no known conversion from 'double' to 'int &' 

    //there is no implicit conversion when you have pointers to int, doubles, etc...
    printSumPointer(&a, &b); //This works because we are passing it pointers to places in memory with the size that is expected(int)
    //Illegal!!!
    //printSumPointer(&c, &d); //pointers to doubles do not point to memory of the same size as int, so it is prevented! Otherwise pointer arithmetic would be completely messed up when trying to use the data.
                               //with implicit conversion a temp variable of the proper type is created and data from the other type is converted into it
                               //with a pointer, however, the system has no idea how or what to convert along the chain of pointers (say in an array)
                               //way too messy, if you need to do this you will have to create your own new array of that new type and convert yourself

    std::string name {"James"};
    sayMyName(name); // works because we are giving a string type variable for a reference to be created from
    //Illegal
    //sayMyName("James"); //This is actually a const, character array, to which we are trying to create a non const ref!
    sayMyNameStringView("James"); // This works because string view will accept const and non const input types, then the string view created is const!

    // implicit conversions from std::string_view to std::string
    // if you have a string_view and pass it into a method with the parameter sayMyName(const std::string& name)
    // it will fail at compilation, string view was made to prevent copies

    // if you want to do this you need to provide it as a string ie...
    //sayMyName(std::string{stringViewVariable}); //This will succeed



    return 0;
}

void printSum(int a, int b)
{
    std::cout << std::setw(50) << std::setfill('-') << "printSum()" << std::setfill(' ') << std::endl;
    int sum = a + b;
    std::cout << "sizeof(a)  : " << sizeof(a) << std::endl;
    std::cout << "value of a : " << a << std::endl;
    std::cout << "sizeof(b)  : " << sizeof(b) << std::endl;
    std::cout << "value of b : " << b << std::endl;
    std::cout << "sum is     : " << sum << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
}

void incrementWithReferences(int& a, int& b) //with references there is no conversion! You must pass matched types! ints!
{
    std::cout << std::setw(50) << std::setfill('-') << "incrementWithReferences()" << std::setfill(' ') << std::endl;
    a += 10;
    b += 20;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
}

void printSumPointer(int* a, int* b)
{
    std::cout << std::setw(50) << std::setfill('-') << "printSumPointer()" << std::setfill(' ') << std::endl;
    int sum = *a + *b;
    std::cout << "sizeof(a)  : " << sizeof(a) << std::endl;
    std::cout << "value of a : " << *a << std::endl;
    std::cout << "sizeof(b)  : " << sizeof(b) << std::endl;
    std::cout << "value of b : " << *b << std::endl;
    std::cout << "sum is     : " << sum << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
}

void sayMyName(std::string& name)
{
    std::cout << name << std::endl;
}

void sayMyNameStringView(std::string_view name)
{
    std::cout << name << std::endl;
}
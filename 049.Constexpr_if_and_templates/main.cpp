#include <iostream>

void doubleFunction (double d)
{
    std::cout << "The floating point version was called!" << std::endl;
}

void intFunction (int i)
{
    std::cout << "The integral type version was called!" << std::endl;
}

template<typename T>
void middleMan(T t)
{
    //constexpr is run at compile time
    if constexpr(std::is_integral_v<T>)
        intFunction(t);
    else if constexpr(std::is_floating_point_v<T>) //in a constexpr tree, the failing branches are not included in compilation, thus the corresponding templates are not be created, decreasing final binary size
        doubleFunction(t);
    else
        //when static assert FAILS the condition, the message is sent
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Argument must be integral or floating point!");
}


int main(int argc, char **argv){

    //Constexpr if and template functions
    //clever control of compilation

    int intVal{10};
    middleMan(intVal);

    double doubleVal{10};
    middleMan(doubleVal);

    std::string stringVal{"pizza"};
    middleMan(stringVal); //fails compilation

    //try commenting either int or double call and running this through cppinsights.io to see how the branches 
    //of constexpr are included or not!

    return 0;
}
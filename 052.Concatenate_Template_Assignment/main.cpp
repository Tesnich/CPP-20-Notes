#include <iostream>
#include <string>

//concatenate template assignment!

//Concept
template <typename T>
concept ConvertibleToStdString = requires (T a) {
    std::to_string(a);
};

//Template
template <ConvertibleToStdString T, ConvertibleToStdString P>
std::string concatenate (T a, P b) {
    return std::to_string(a) + std::to_string(b);
}

int main(int argc, char **argv){

    std::cout << "Result : " << concatenate(22.22, 33.33) << std::endl;
    std::cout << "Result : " << concatenate(22, 33) << std::endl;

    return 0;
}
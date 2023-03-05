#include <iostream>
#include <fstream>

void read_from_file(const std::string& filename, int* data, unsigned int size){
    std::ifstream ifstream(filename);
    if(ifstream.fail())
        throw std::runtime_error("Unable open ifstream.");

    int value{};
    int index{};
    while(ifstream >> value){
        std::cout << "Value : " << value << "\n";
        if(index < size){
            data[index++] = value;
        }else{
            throw std::runtime_error("Full file not read.");
        }
    }

    if(!ifstream.eof())
        throw std::runtime_error("End of file not safely reached.");

}

int main(int argc, char **argv){

    //Reading Files (With Exception Safety)
    int data[4];
    read_from_file("numbers.txt",data, std::size(data));

    for(unsigned int i{}; i < std::size(data); ++i)
        std::cout << data[i]<<" ";
    std::cout << "\n";

    return 0;
}
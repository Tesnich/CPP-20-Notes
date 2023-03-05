#include <iostream>
#include <iomanip>

//multi dimensional arrays

int main(){
    
    int packages [4][3]; //occupies 48 bytes in memory

    std::cout << "Size of packages :" << sizeof(packages) << std::endl;

    std::cout << "Element count in packages outer level - std::size(packages) :" << std::size(packages) << std::endl;
    std::cout << "Element count in packages first inner element - std::size(packages[0]) :" << std::size(packages[0]) << std::endl;

    int packages2 [4][3] //this can go on and on to create n number of dimensions
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    for(size_t i{0}; i < std::size(packages2); ++i)
    {
        std::cout << "Level " << i << ":";
        for(size_t n{0}; n < std::size(packages2[i]); ++n)
        {
            std::cout<< std::setw(5) << packages2[i][n] << " ";
        }
        std::cout << std::endl;
    }

    //cannot declare a multidimensional array without specifing the inner sizes
    //AKA below gives the compiler to little information to deduce sizes

    // int illegalArray[][] {
    //     {1,1,1},
    //     {2,2,2},
    //     {3,3,3},
    //     {4,4,4}
    // };

    //however the compiler CAN deduce the outer level!

    const int TUPLE_SIZE{3}; //variables used to define size of an arrays must be declared const

    int legalArray[][TUPLE_SIZE] { // outer level size deduced, this is only for outermost level so [][4][5] is legal too but [][][5] is not
        {1,1,1},
        {2,2,2},
        {3,3,3},
        {4,4,4}
    };

    int defaultInitializationArray[][3] { // outer level size deduced, this is only for outermost level so [][4][5] is legal too but [][][5] is not
        {1,1,1},
        {2}, // this will have the int default value, 0?
        {3,3,3},
        {4,4,4}
    };

    //multidimensional arrays of chars

    const size_t name_length{15};

    char members[][name_length]
    {
        {'J','o','h','n'}, //This and the below will have a null terminator since 15 characters leave enough space
        {'K','y','l','e'} // ^^^
        //There would be a problem with junk data if name used all 15 chars and we tried to print
    };

    char members2[][name_length]
    {
        "James Hillman",
        "Kevin Bradner",
        "Ben Holliday"
        //could also use curly brackets for visibility
        // {"James Hillman"},
        // {"Kevin Bradner"},
        // {"Ben Holliday"}
    };

    //iteration and printing of all characters in the array

    for(size_t i{0}; i < std::size(members2); ++i)
    {
        std::cout << "Level " << i << ":";
        for(size_t n{0}; n < std::size(members2[i]); ++n)
        {
            std::cout<< members2[i][n] << "_";
        }
        std::cout << std::endl;
    }

    //giving the character array to cout will print it all, no need to iterate through

    for(size_t i{0}; i < std::size(members2); ++i)
    {
        std::cout << "Level " << i << ":";
        std::cout<< members2[i];
        std::cout << std::endl;
    }
}
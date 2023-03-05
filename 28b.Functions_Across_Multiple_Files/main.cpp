#include <iostream> //precompiler directive for standard library files
#include "comparisons.h" //format for custom header files (uses "quotes")
#include "operations.h"

//Remember the One Definition Rule: The same function implementation can't show up in the global namespace more than once

// Note that once a declaration is given, the linker will search all .cpp files to find its definition
// This means that a definition doesn't neccesarily need to live in a .cpp file with the same name as the header it is declare in
//      ^ Why would you do that I wonder?

int main(){

    int a{22}, b{37};

    //function definitions in comparisons.cpp!
    std::cout << "max(" << a << "," << b << ") : " << max(a,b) << std::endl;
    std::cout << "min(" << a << "," << b << ") : " << min(a,b) << std::endl;

    //function definitions in operations.cpp!
    std::cout << "incrementAndMultiply(" << a << "," << b << ") : " << incrementAndMultiply(a,b) << std::endl;

    return 0;
}

//a linker error can be caused by the compiler seeing the declaration but not being able to find the .cpp file containing the definition

//The build process is as follows
//  The source files go through pre-processing where all #include directives are processed and content of files referenced are 
//  added to these source files. These new full files are called translation units! These translation units are compiled
//  to create object files. For each source .cpp there is an equivalent object file. Then the object files are linked together
//  and the final program executable is crafted that we can run.


// CPP FILES                Translation Units                   Object Files                       Final Executable!

//   File 1                        TU 1                            ObjF 1                            
//   File 2    PRE-PROCESSING      TU 2          COMPILATION       ObjF 2    LINKING OBJ FILES       program.exe
//   File 3                        TU 3                            ObjF 3                            
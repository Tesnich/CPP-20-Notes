#include <iostream>
#include "Utilities.h"

int main(int argc, char **argv){

    //compiling a program has the following steps

    //  > Preprocessing
    //  > Compilation
    //  > Linking

    //This will contain utilites.h, utilities.cpp, and main.cpp

    //Up till this point I was relying on executing the tasks.json file I configured in vs code.
    //I know how to compile(and link) a program in the terminal using g++, so this may be beneficial.

    //To COMPILE and LINK a program in one statement
    //
    //         '-o' is an option to provide a custom name to resulting executable ('program' here)
    //          |
    //          V
    //  >>  g++ -o program main.cpp utilities.cpp
    //
    //  if you dont want to specify specific files you can use the escape sequence '*\.cpp' to add all
    //      ending in '.cpp' (.json uses */)

    //Only COMPILING the files in g++, creating object files for each src file passed (#includes will handle headers?)
    //
    //         '-c' is an option to tell g++ to only compile the files we provide
    //          |
    //          V
    //  >>  g++ -c main.cpp utilities.cpp
    //
    //  if you dont want to specify specific files you can use the escape sequence '*\.cpp' to add all
    //      ending in '.cpp' (.json uses */)

    //After performing the above we can run the below to LINK our object files
    //
    //         '-o' for all in one compiling and linking you can leave this out and it will return a name of a file
    //          |           can't leave it out here, so supply name!
    //          V
    //  >>  g++ -o program main.o utilities.o
    //
    //  if you dont want to specify specific files you can use the escape sequence '*\.o' to add all
    //      ending in '.o' (.json uses */)

    //Coding time

    std::cout << "result : " << Utilities::Add(10.1,20) << std::endl;

    //So check this...if you have a very large software program and are only altering a few files. You can recompile only those
    //and link all the .o files again! Below I am adding another call to Add, but not recompiling all files.

    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % ++ -c *\.cpp      
    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % g++ -o program *\.cpp
    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % ./program

    //  adding line below...
    std::cout << "result : " << Utilities::Add(10.1,20) << std::endl;

    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % g++ -c main.cpp      
    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % g++ -o program2 *\.o
    //  jameshillman@Jamess-MBP 74.Programs_with_multiple_files_a_closer_look % ./program2

    // program2 works fine! (although technically utilities.cpp is empty...)

    return 0;
}
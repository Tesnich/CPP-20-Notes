#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <iomanip>
#include <string>

namespace UTIL {

    unsigned int LINE_SPACING {50};
    unsigned int HALF_LINE_SPACING {LINE_SPACING/2};
    char FILL_CHAR{'-'};
    char SPACE_CHAR{' '};
    
    void PrintTitleLine(std::string_view title){
        std::cout << std::setw(LINE_SPACING) << std::setfill(FILL_CHAR) << title << std::setfill(SPACE_CHAR) << "\n";
    }

    void PrintEndLine(){
        std::cout << std::setw(LINE_SPACING) << std::setfill(FILL_CHAR) << FILL_CHAR << std::setfill(SPACE_CHAR) << "\n\n";
    }
}

#endif
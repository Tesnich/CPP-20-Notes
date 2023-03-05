#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <iomanip>
#include <string>

namespace UTIL {

    inline unsigned int LINE_SPACING {50};
    inline unsigned int HALF_LINE_SPACING {LINE_SPACING/2};
    inline char FILL_CHAR{'-'};
    inline char SPACE_CHAR{' '};
    
    inline void PrintTitleLine(std::string_view title){
        std::cout << std::setw(LINE_SPACING) << std::setfill(FILL_CHAR) << title << std::setfill(SPACE_CHAR) << "\n";
    }

    inline void PrintEndLine(){
        std::cout << std::setw(LINE_SPACING) << std::setfill(FILL_CHAR) << FILL_CHAR << std::setfill(SPACE_CHAR) << "\n\n";
    }
}

#endif
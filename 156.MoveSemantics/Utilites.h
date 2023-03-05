#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>
#include <iomanip>
#include <string>

namespace Util {

    inline unsigned int LINE_SPACING {50};
    inline unsigned int HALF_LINE_SPACING {LINE_SPACING/2};
    inline char FILL_CHAR{'-'};
    inline char SPACE_CHAR{' '};

    inline void PrintTitleLine(std::string_view title, unsigned int multiplier){
        std::cout << std::setw(LINE_SPACING * multiplier) << std::setfill(FILL_CHAR) << title << std::setfill(SPACE_CHAR) << "\n";
    }

    inline void PrintTitleLine(std::string_view title){
        PrintTitleLine(title, 1);
    }

    inline void PrintEndLine(unsigned int multiplier){
        std::cout << std::setw(LINE_SPACING * multiplier) << std::setfill(FILL_CHAR) << FILL_CHAR << std::setfill(SPACE_CHAR) << "\n\n";
    }

    inline void PrintEndLine(){
        PrintEndLine(1);
    }
}

#endif
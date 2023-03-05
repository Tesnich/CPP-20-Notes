#ifndef UC_GRADUATE_H
#define UC_GRADUATE_H
#include <iostream>
#include <string>
#include <optional>

class UcGraduate {
    friend std::ostream& operator<<(std::ostream& os, const UcGraduate& ucGraduate);
    protected :
        std::string firstName_{}, lastName_{};
    public :
        UcGraduate() {
            std::cout << ">> UcGraduate obj constructed <<" << "\n";
        }
        UcGraduate(std::string_view firstName, std::string_view lastName)
            :firstName_{firstName}, lastName_{lastName} {}
        ~UcGraduate() = default;

        //testing public inheritance of members
        void PublicUcGraduateFunc(){
            std::cout << ">> Public UcGraduate Function Called <<" << "\n";
        }
};

inline std::ostream& operator<<(std::ostream& os, const UcGraduate& ucGraduate) {
    os << "(" << ucGraduate.lastName_ << "," << ucGraduate.firstName_ << ")";
    return os;
}

#endif
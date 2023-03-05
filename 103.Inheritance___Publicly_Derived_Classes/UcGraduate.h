#ifndef UC_GRADUATE_H
#define UC_GRADUATE_H
#include <iostream>
#include <string>
#include <optional>

class UcGraduate {
    friend std::ostream& operator<<(std::ostream& os, const UcGraduate& ucGraduate);
    private :
        std::string firstName_{}, lastName_{};
    public :
        UcGraduate() = default;
        UcGraduate(std::string_view firstName, std::string_view lastName)
            :firstName_{firstName}, lastName_{lastName} {}
        ~UcGraduate() = default;

        //accessors
        std::string_view firstName() const {
            return firstName_;
        }
        void firstName(std::string_view firstName){
            firstName_ = firstName;
        }

        std::string_view lastName() const {
            return lastName_;
        }
        void lastName(std::string_view lastName){
            lastName_ = lastName;
        }
};

inline std::ostream& operator<<(std::ostream& os, const UcGraduate& ucGraduate) {
    os << "(" << ucGraduate.lastName_ << "," << ucGraduate.firstName_ << ")";
    return os;
}

#endif
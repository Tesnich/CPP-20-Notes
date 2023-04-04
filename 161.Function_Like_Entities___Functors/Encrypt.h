#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "Encode.h"

//Encrypt inherits from the abstract class Encode

//final here because I dont want anything inheriting from it? Makes sense rn...
class Encrypt final : public Encode {
    private:
        unsigned int shiftVal_{};

        virtual char encodeChar(const char input) override {
            return input + shiftVal_;
        }

    public:
        Encrypt() = delete;
        Encrypt(unsigned int shiftVal)
            :shiftVal_{shiftVal} {
                std::cout << "Encrypt Functor Constructed!\n";
            }
};

#endif
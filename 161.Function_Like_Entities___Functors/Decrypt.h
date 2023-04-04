#ifndef DECRYPT_H
#define DECRYPT_H

#include "Encode.h"

//Decrypt inherits from the abstract class Encode

//final here because I dont want anything inheriting from it? Makes sense rn...
class Decrypt final : public Encode {
    private:
        unsigned int shiftVal_{};

        virtual char encodeChar(const char input) override {
            return input - shiftVal_;
        }

    public:
        Decrypt() = delete;
        Decrypt(unsigned int shiftVal)
            :shiftVal_{shiftVal} {
                std::cout << "Decrypt Functor Constructed!\n";
            }
};

#endif
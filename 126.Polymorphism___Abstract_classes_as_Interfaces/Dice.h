#ifndef DICE_H
#define DICE_H
#include "StreamInsertable.h"

//class Dice is built off the interface StreamInsertable
class Dice final : public StreamInsertable
{
    public :
        Dice() {
            std::srand(time(0));
        };
        ~Dice() = default;

        //stream insertable a pure virtual method called InsertStream being
        //overriden below
        void InsertStream(std::ostream& os) const override {
            os << (rand()%6 + 1);
        }
};

#endif
#ifndef ITEM_H
#define ITEM_H
#include <memory>
#include <iostream>
#include <iomanip>

class Item{
        friend std::ostream& operator<<(std::ostream& os, const Item& item);
    private :
        inline static unsigned int count{};
        unsigned int instanceId_{};
        std::unique_ptr<int> ptrVal_{std::make_unique<int>()}; //unique pointer!
    public :
        Item() = delete;
        Item(const Item& itemSource)
            :Item(*itemSource.ptrVal_) {}
        Item(int val)
            :instanceId_{++count}, ptrVal_{std::make_unique<int>(val)} {}

        std::strong_ordering operator<=> (const Item& itemB) const {
            return *ptrVal_ <=> *itemB.ptrVal_;
        }
};

std::ostream& operator<<(std::ostream& os, const Item& item){
    os << std::setw(10) << "Item : " << item.instanceId_ << "\n";
    os << std::setw(10) << "ptrVal_ : " << item.ptrVal_ << "\n";
    os << std::setw(10) << "*prtVal_ : " << *item.ptrVal_ << "\n";
    return os;
}

#endif
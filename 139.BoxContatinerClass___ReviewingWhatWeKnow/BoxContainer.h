#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H
#include <memory>
#include <iostream>
#include <cmath>

//for ease of change later, the int type here is given a type alias
//so that we dont have to go through the whole class changing ints to doubles if needed
using ValueType = int; // (personally I'd make this a template class but we havent gotten there yet)

class BoxContainer
{
    friend std::ostream& operator<< (std::ostream& os, const BoxContainer& boxContainer);

    inline static const unsigned int DEFAULT_CAPACITY_{30}; //this class stores objects in arrays, need default initialization size

    protected:
        unsigned int capacity_{};
        unsigned int size_{0};
        std::unique_ptr<ValueType[]> ptrValues_;
    public:
        BoxContainer(unsigned int capacity = DEFAULT_CAPACITY_);
        BoxContainer(const BoxContainer& source);
        ~BoxContainer() = default;

        //Ambiguity in design, what is this class used for?
        //If we add item by its value, what do we remove by? Value or index? Does order matter? I'm guessing no, based on lecture.
        void AddItem(ValueType value);  //  It mentioned something weird where the last element would be moved into removed elements spot
        void RemoveItem(ValueType value);
        void RemoveAll();
        ValueType At(unsigned int index) const;

        //opperator overloads += and +
        BoxContainer& operator+= (const BoxContainer& tool);
        BoxContainer operator+ (const BoxContainer& tool) const;

        //opperator overload for spaceship <=>
        std::strong_ordering operator<=> (const BoxContainer& boxContainer2) const;
        bool operator== (const BoxContainer& boxContainer2) const;

        //member accessors
        unsigned int capacity() const; //{return capacity_;}
        unsigned int size() const; //{return size_;}

};

inline std::ostream& operator<< (std::ostream& os, const BoxContainer& boxContainer){
    for(unsigned int i{}; i< boxContainer.size_; ++i)
        os<<boxContainer.ptrValues_[i] << " ";
    return os;
}

#endif
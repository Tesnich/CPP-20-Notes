#include "BoxContainer.h"
#include <algorithm>
#include <exception>
#include <iostream>

BoxContainer::BoxContainer(unsigned int capacity)
            :capacity_{capacity}, ptrValues_{new ValueType[capacity_]{}} {}

BoxContainer::BoxContainer(const BoxContainer& source)
    :BoxContainer(source.capacity_){
        *this += source;
        std::cout<<"BoxContainer Copy Constructor Called!\n";
    }

void BoxContainer::AddItem(ValueType value){
    if (size_ < capacity_){
        ptrValues_[size_++] = value;
    } else {
        throw std::out_of_range("Attempted to exceed BoxContainer Capacity");
    }
}

//removes all instances of item with value match, placing the last stored element in each removed elements place
//and reducing size
void BoxContainer::RemoveItem(ValueType value){
    auto ptrBeginSearch = ptrValues_.get();
    auto searchResult{std::find(ptrBeginSearch, ptrValues_.get()+size_, value)};
    while(searchResult != (ptrValues_.get()+size_)){
        *searchResult = *(ptrValues_.get() + --size_);
        ptrBeginSearch = searchResult;
        searchResult = std::find(ptrBeginSearch, ptrValues_.get()+size_, value);
    }
}

//clears the data structure
void BoxContainer::RemoveAll(){
    ptrValues_.reset(new ValueType[capacity_]{});
    size_ = 0;
}

ValueType BoxContainer::At(unsigned int index) const {
    if(index < size_){
        return ptrValues_[index];
    }else{
        throw std::out_of_range("Attempted to retrieve past BoxContainer Contents");
    }
}

BoxContainer& BoxContainer::operator+= (const BoxContainer& tool){
    //if we wanted to make this work properly we should create 
    //a new method to "resize" the array that takes in int. Call it here before
    //adding a ton of items. Maybe make it public... idk this is weird. We should just use vectors

    //Actually it might even make more sense to manually put them all in here to side step
    //int increment of size_. Eh... I'll keep it in mind for future projects but I'm not terribly
    //concerned about the efficiency of some code I wrote while following a lecture
    for(unsigned int i{}; i< tool.size_; ++i){
        AddItem(tool.ptrValues_[i]);
    }
    return *this;
}

BoxContainer BoxContainer::operator+ (const BoxContainer& tool) const {
    BoxContainer newBoxContainer{*this};
    newBoxContainer += tool;
    return newBoxContainer;
}

std::strong_ordering BoxContainer::operator<=> (const BoxContainer& boxContainer2) const {        
    unsigned int i{};
    while(i< std::min(size_, boxContainer2.size_)){
        std::strong_ordering result{ptrValues_[i] <=> boxContainer2.ptrValues_[i]};
        if(result != 0){
            return result;
        }
        ++i;
    }
    //if shared indexes all match, comparison is determined by which boxContatiner has additional members
    if(size_ < boxContainer2.size_)
        return std::strong_ordering::less;
    if(size_ > boxContainer2.size_)
        return std::strong_ordering::greater;
    //box containers are equivalent if contained values are the same
    //equal if the above AND capacity matches
    if(capacity_ == boxContainer2.capacity_){
        return std::strong_ordering::equal;
    }else{
        std::cout<<"EQUIVALENT\n";
        return std::strong_ordering::equivalent;
    }
}

bool BoxContainer::operator== (const BoxContainer& boxContainer2) const{
    return (*this <=> boxContainer2) == 0;
}

unsigned int BoxContainer::capacity() const {
    return capacity_;
}

unsigned int BoxContainer::size() const {
    return size_;
}
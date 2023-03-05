#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H
#include <memory>
#include <iostream>
#include <cmath>
#include <string>

//WHEN WRITING CLASS TEMPLATE, DEFINITIONS SHOULD BE SPECIFIED IN TEMPLATE BLUEPRINT!

template<typename T>
class BoxContainer
{
    //operator<< can't be a friend for some reason, will be explained later I hope? (change it to use public accessors)
    //friend std::ostream& operator<< (std::ostream& os, const BoxContainer& boxContainer);

    inline static const unsigned int DEFAULT_CAPACITY_{30}; 

    protected:
        unsigned int capacity_{};
        unsigned int size_{0};
        std::unique_ptr<T[]> ptrValues_;
    public:
        BoxContainer(unsigned int capacity = DEFAULT_CAPACITY_)
            :capacity_{capacity}, ptrValues_{new T[capacity_]{}} {}
        BoxContainer(const BoxContainer& source)
            :BoxContainer(source.capacity_){
                *this += source;
                std::cout<<"BoxContainer Copy Constructor Called!\n";
            }
        ~BoxContainer() = default;

        
        void AddItem(T value){
            if (size_ < capacity_){
                ptrValues_[size_++] = value;
            } else {
                throw std::out_of_range("Attempted to exceed BoxContainer Capacity");
            }
        }

        void RemoveItem(T value){
            auto ptrBeginSearch = ptrValues_.get();
            auto searchResult{std::find(ptrBeginSearch, ptrValues_.get()+size_, value)};
            while(searchResult != (ptrValues_.get()+size_)){
                *searchResult = *(ptrValues_.get() + --size_);
                ptrBeginSearch = searchResult;
                searchResult = std::find(ptrBeginSearch, ptrValues_.get()+size_, value);
            }
        }

        void RemoveAll(){
            ptrValues_.reset(new T[capacity_]{});
            size_ = 0;
        }

        T At(unsigned int index) const; //DECLARED!!!! LOOK BELOW FOR HOW TO DEFINE TEMPLATE CLASS METHOD

        //opperator overloads += and +
        BoxContainer& operator+= (const BoxContainer& tool){
            for(unsigned int i{}; i< tool.size_; ++i){
                AddItem(tool.ptrValues_[i]);
            }
            return *this;
        }

        BoxContainer operator+ (const BoxContainer& tool) const {
            BoxContainer newBoxContainer{*this};
            newBoxContainer += tool;
            return newBoxContainer;
        }

        //opperator overload for spaceship <=>
        std::strong_ordering operator<=> (const BoxContainer& boxContainer2) const {        
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

        bool operator== (const BoxContainer& boxContainer2) const{
            return (*this <=> boxContainer2) == 0;
        }

        //member accessors
        unsigned int capacity() const; //DECLARED HERE, LOOK BELOW FOR DEFINITION

        unsigned int size() const {
            return size_;
        }

};

//functions taking in Template Classes need to be templates themselves
//this is because they need to handle all variations of the template class arguments
//this is probably why it cannot be declared as a friend (had to change below method to use public accessors)
template<typename T>
inline std::ostream& operator<< (std::ostream& os, const BoxContainer<T>& boxContainer){
    for(unsigned int i{}; i< boxContainer.size(); ++i)
        os<<boxContainer.At(i) << " ";
    return os;
}

//FYI so you know this is possible, If you want to declare methods in class template but define them below
//you can do so. Just remember that they need to be templates to specify that they are definitions for a template class

template<typename T> // <---define typename for use in defining return values, but most importantly
//                       ,--for scope resolution of the class method we are defining
//       _______________/
inline T BoxContainer<T>::At(unsigned int index) const {
    if(index < size_){
        return ptrValues_[index];
    }else{
        throw std::out_of_range("Attempted to retrieve past BoxContainer Contents");
    }
}
//my guess is that if functionality was different enough we could specify the T type manually and return
//different functionality based on which version of the template the method was used on (think int or string...)
//actually lets try this...

//I wonder which have precedence? Nevermind thats stupid. Templates are only used to create a class if
//an existing method doesn't already exist. By giving the concrete types int and string, no templated version
//of capacity will be created to compete with them.

//looks like it wont allow use to specialize unless we place 'template<>' infront of them
//good to know!

template<>
inline unsigned int BoxContainer<int>::capacity() const {
    std::cout<< "int version of capacity called : ";
    return capacity_;
}

template<>
inline unsigned int BoxContainer<std::string>::capacity() const {
    std::cout<< "string version of capacity called : ";
    return capacity_;
}

template<typename T>
inline unsigned int BoxContainer<T>::capacity() const {
    std::cout<< "template version of capacity called : ";
    return capacity_;
}

#endif
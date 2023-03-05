#include "Person.h"
#include <iostream>

Person::Person(std::string_view name)
    :name_{name} {}

Person::~Person(){
    std::cout<< "Person object (" << name_ << ") destructed!" << std::endl;
}

std::string_view Person::Name(){
    return name_;
}

void Person::SetFriend(const std::shared_ptr<Person>& theirFriend){
    theirFriend_ = theirFriend;
}

void Person::ReadFriend(){
    std::cout<<name_ <<"'s friend is " << theirFriend_->Name() << std::endl;
}
#include "PersonImproved.h"
#include <iostream>

PersonImproved::PersonImproved(std::string_view name)
    :name_{name} {}

PersonImproved::~PersonImproved(){
    std::cout<< "PersonImproved object (" << name_ << ") destructed!" << std::endl;
}

std::string_view PersonImproved::Name(){
    return name_;
}

void PersonImproved::SetFriend(const std::shared_ptr<PersonImproved>& theirFriend){
    theirFriend_ = theirFriend;
}

void PersonImproved::ReadFriend(){
    //only change to call function on weak pointer is to create a shared pointer in its place!
    //                                    ________________________________                   _
    std::cout<<name_ <<"'s friend is " << std::shared_ptr<PersonImproved>{theirFriend_.lock()}->Name() << std::endl;
    //                                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^                   ^
}
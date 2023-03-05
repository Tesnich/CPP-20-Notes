#ifndef PERSON_IMPROVED_H
#define PERSON_IMPROVED_H

#include <memory>
#include <string>
#include <string_view>

class PersonImproved {
    private :
        std::string name_{};
        //memory leak fixed with use of weak_ptr!
        std::weak_ptr<PersonImproved> theirFriend_{};
        //look in definition of ReadFriend() to see how use changed
    public :
        PersonImproved() = delete;
        PersonImproved(std::string_view name);
        ~PersonImproved();
        
        std::string_view Name();
        void SetFriend(const std::shared_ptr<PersonImproved>& theirFriend);
        void ReadFriend();

};

#endif
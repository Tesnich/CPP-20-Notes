#ifndef PERSON_H
#define PERSON_H

#include <memory>
#include <string>
#include <string_view>

class Person {
    private :
        std::string name_{};
        std::shared_ptr<Person> theirFriend_{};
    public :
        Person() = delete;
        Person(std::string_view name);
        ~Person();
        
        std::string_view Name();
        void SetFriend(const std::shared_ptr<Person>& theirFriend);
        void ReadFriend();

};

#endif
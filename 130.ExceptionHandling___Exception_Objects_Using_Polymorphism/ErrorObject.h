#ifndef ERROR_OBJECT_H
#define ERROR_OBJECT_H
#include <string>

//abstract class from What();
class ErrorObject
{
    protected:
        std::string message_{};
    public:
        ErrorObject() = delete;
        ErrorObject(std::string_view message)
            :message_{message} {}

        //Remember that thrown objects must implement a copy constructor
        //We really don't need to implement one here because we are not copying pointers to heap data
        //But I need practice on copy constructor inheritance chains...
        ErrorObject(const ErrorObject& source)
            :ErrorObject(source.message_) {}

        virtual ~ErrorObject() = default;

        virtual std::string Severity() const = 0;

        std::string Message(){
            return message_;
        }

        //pure virutual function
        std::string What() const {
            return (Severity() += " Error : ") += message_ + "\n";
        };
};


#endif
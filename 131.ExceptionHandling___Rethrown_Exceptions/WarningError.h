#ifndef WARNING_ERROR
#define WARNING_ERROR
#include "ErrorObject.h"

class WarningError final : public ErrorObject
{
    public:
        WarningError() = delete;
        WarningError(std::string_view message)
            :ErrorObject(message) {}

        //Remember that thrown objects must implement a copy constructor
        //We really don't need to implement one here because we are not copying pointers to heap data
        //But I need practice on copy constructor inheritance chains...
        WarningError(const WarningError& source)
            :ErrorObject(source){}

        virtual ~WarningError() = default;

        std::string Severity() const override{
            return "Warning";
        }
};

#endif
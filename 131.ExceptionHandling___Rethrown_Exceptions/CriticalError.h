#ifndef CRITICAL_ERROR
#define CRITICAL_ERROR
#include "ErrorObject.h"

class CriticalError final : public ErrorObject
{
    public:
        CriticalError() = delete;
        CriticalError(std::string_view message)
            :ErrorObject(message) {}

        //Remember that thrown objects must implement a copy constructor
        //We really don't need to implement one here because we are not copying pointers to heap data
        //But I need practice on copy constructor inheritance chains...
        CriticalError(const CriticalError& source)
            :ErrorObject(source) {}

        virtual ~CriticalError() = default;

        std::string Severity() const override{
            return "CRITICAL";
        }
};

#endif
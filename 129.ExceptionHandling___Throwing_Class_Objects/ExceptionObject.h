#ifndef EXCEPTION_OBJECT_H
#define EXCEPTION_OBJECT_H
#include "OutputStreamObject.h"

template<typename T>
class ExceptionObject : public OutputStreamObject
{
private:
    inline static unsigned int constructionCount{};
    unsigned int instance_{};
    T errorValue_{};
public:
    ExceptionObject()
        :ExceptionObject(T{}) {}
    ExceptionObject(T errorValue)
        :instance_{++constructionCount}, errorValue_{errorValue} {
        std::cout << "Exception Object (" << instance_ << ") Constructed\n";
    }

    ExceptionObject(const ExceptionObject& source)
        :ExceptionObject(source.errorValue_) {
            std::cout<< "Exception Object (" << source.instance_ << ") Copied To Create Exception Object (" << constructionCount <<")\n";
            //This body runs after the construction of the new ExceptionObject, no need to increment -------------^
        }

    ~ExceptionObject(){
        std::cout << "Exception Object (" << instance_ << ") Destructed\n";
    };

    virtual std::ostream& OutputStreamOverload(std::ostream& os) const override {
        return os << errorValue_;
    }
};


#endif
#ifndef DEFAULT_TEMPLATE_H
#define DEFAULT_TEMPLATE_H

template <typename ValueType = int>
struct DefaultTemplate
{
    ValueType value_{};

    DefaultTemplate() = default;

    std::string Type(){
        return typeid(ValueType).name();
    }
};


#endif
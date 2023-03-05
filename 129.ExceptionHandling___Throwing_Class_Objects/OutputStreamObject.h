//interface to add easy output stream functionality to a class
#ifndef OUTPUT_STREAM_ENABLED_H
#define OUTPUT_STREAM_ENABLED_H
#include <iostream>

class OutputStreamObject
{
    //remember it doesn't matter where you list friend classes
    friend std::ostream& operator<< (std::ostream& os, const OutputStreamObject& outputStreamObject);

    public:
        OutputStreamObject() = default;
        ~OutputStreamObject() = default;

        //placed in public because why not allow people to give an ostream to it and fill it up?
        virtual std::ostream& OutputStreamOverload(std::ostream& os) const = 0;
};

inline std::ostream& operator<< (std::ostream& os, const OutputStreamObject& outputStreamObject){
    return outputStreamObject.OutputStreamOverload(os);
}

#endif
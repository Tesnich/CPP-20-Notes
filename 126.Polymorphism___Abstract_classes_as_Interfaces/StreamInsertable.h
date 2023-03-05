#ifndef STREAM_INSERTABLE_H
#define STREAM_INSERTABLE_H
#include <iostream>

//class StreamInsertable is considered an interface because it only
//has pure virtual functions and no member variables
class StreamInsertable 
{
    //below a binary overload of the << operator is declared a friend. Just as if this were any standard class
    //this overload takes in the output stream as the first argument, and the object itself as the class...
    friend std::ostream& operator<< (std::ostream& os, const StreamInsertable& StreamInsertable);

    private:
        //The below is the pure virtual function derived classes must implement,
        //the idea behind this is that any non abstract class derived from StreamInsertable can override
        //the below method and pipe their output to the output stream object
        virtual void InsertStream(std::ostream& os) const = 0;
};

inline std::ostream& operator<< (std::ostream& os, const StreamInsertable& streamInsertable){
    //This operator<< overload leverages polymorphism.
    //If any object derived from the streamInsertable interface is the rh opperand of << with an output
    //stream this method will be called!
    
    //Since this method is declared a friend of StreamInsertable, it is able to call the
    //private method InsertStream and through polymorphism get the override in the Dice class.
    streamInsertable.InsertStream(os);
    //There we pump os reference with whatever we want written to the stream, and below we return it.
    return os;
}

#endif
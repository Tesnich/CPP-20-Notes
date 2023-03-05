#ifndef DES_WAT_HOLDER_H
#define DES_WAT_HOLDER_H

#include <memory>
#include "DestructorWatch.h"

//class that can hold two DestructorWatch objects

class DesWatHolder{
    private :
        std::unique_ptr<DestructorWatch> DesWatA_{};
        std::unique_ptr<DestructorWatch> DesWatB_{};
    public :
        DesWatHolder() = delete;
        //I see two ways going about constructor design. The first being how I would naturally write the constructor...

        /////////////My Way//////////////

        //  DesWatHolder(std::unique_ptr<DestructorWatch>& DesWatA, std::unique_ptr<DestructorWatch>& DesWatB)
        //      :DesWatA_{std::move(DesWatA)}, DesWatB_{std::move(DesWatB)} {}

        //With this the user calls the constructor like below...

        //      DesWatHolder desWatHolder(DesWatA, DesWatB);

        //On construction the DestructorWatch unique_ptrs are passed by ref, where an list initalization
        //is used in conjunction with the std::move() call to give "ownership" of the objects to the
        //private unique_ptrs in the holder class

        //at first I thought this would be the optimal way to go about this because the user would have to
        //type less when constructing the holder class. However, on second thought I re-examined a quiz and
        //the instructor's answer and believe it to be supperior. Using that method we would write the below... 

        /////////////Instructor Method////////////////
            DesWatHolder(std::unique_ptr<DestructorWatch> DesWatA, std::unique_ptr<DestructorWatch> DesWatB)
        :DesWatA_{std::move(DesWatA)}, DesWatB_{std::move(DesWatB)} {}

        //The corresponding call to the constructor would be written like this...

        //DesWatHolder desWatHolder(std::move(DesWatA), std::move(DesWatB));

        //Looking at this setup I first thought, "Why is he doing this? My way would only require one copy operation".
        //And while that is true, the cost isn't significant because they are simple pointers.
        //It doesnt matter how large or complex class T is in the template std::unique_ptr<T>. At the end of
        //the day it will be the same size of an address in memory. Doing one copy or two has a negligble impact.

        //That said, the main reason why I think he wrote it this way is to make it obvious to the programmer,
        //who has control of the DestructorWatch objects allocated in memory and who is in charge of dealing with them.

        //By writing the constructor pass by reference, we force the person using the class to use 
        //std::move(). We know from experimentation in the last section that the copy constructor is
        //deleted and compilation error will occur if called. By making them use the move constructor
        //it is 100% obvious that the wrapper class we are calling the constructor for is now in charge of
        //managing the unique_ptrs for these objects.

        //Not to say there is anything wrong with my method in terms of functionality.
        //The unique_ptrs are going to manage the memory regardless of how it is implemented.
        //But honestly that isnt enough. Intent has to be clear so OTHERS can easily understand
        //and use your code.

        //In addition, this is important to keep in mind when using traditional pointers. Since traditional
        //pointers don't do garbage collection, the programmer needs to know at a glance whether the
        //method they are implementing has to take care of any loose ends. The analogy falls apart a bit
        //because traditional points dont have deleted copy constructors but the heart of the message
        //stays the same.  
};

#endif
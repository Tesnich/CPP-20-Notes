#include <iostream>
#include "WrappedValue.h"

int main(int argc, char **argv){

    //In some cases we may write templates that store an object then at some
    //point use said object in an output stream. If our template class is large enough it may not
    //be imediately evident when we pass in an object with no such functionality.

    //We can define our own concept in such cases so that it will be clear as day when compilation
    //fails

    WrappedValue intWrapped{10};
    std::cout << "<<intWrapped : " << intWrapped << "\n";

    //problem because VapidClass doesnt have an overload for << defined
    WrappedValue vapidWrapped{VapidClass{}};
    std::cout << "<<vapidWrapped : " << vapidWrapped << "\n";

    //literally the first error tells us that we need << on VapidClass but I digress... it would be helpful
    //to see the list of requirements on a class template at the top so this doesnt happen...



    return 0;
}
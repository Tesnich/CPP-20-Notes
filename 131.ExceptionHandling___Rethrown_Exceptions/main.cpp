#include <iostream>
#include "CriticalError.h"
#include "WarningError.h"

void ProcessData(unsigned int i){
    if(i == 5)
        //throw warning, iteration failed but the rest of run is still good
        throw WarningError((std::string{__func__} +="() iteration ") += std::to_string(i) += " failed!");
    if(i == 7)
        //throw critical, this should never happen! Dont process any more data!
        throw CriticalError(std::string{__func__} += "() remaining data bad!");
    std::cout << i << " processed...\n";
}

int main(int argc, char **argv){

    //Rethrown Exceptions

    //If we catch an error but decide it needs to be handled by a less specialized try catch block we can
    //rethrow it. This will make the program act like it was never caught and traverse up the call stack
    //until another try catch block captures the exception.

    for(unsigned int i{}; i < 10; ++i){
        try{
            try
            {
                ProcessData(i);
            }
            catch (const ErrorObject& errorObject)
            {
                if ( typeid(errorObject) == typeid(CriticalError))
                    throw;
                //the above line is a re-throw of the copied parameter we originally captured, in this case the CriticalError object...

                //IMPORTANT! If we were to rethrow the error using the below we would run into a few issues.
                //
                //      throw errorObject;
                //
                //      The first, in my specific case, ErrorObject is an abstract object. EVERY TIME throw is used
                //      with an argument, that argument is copied. We can't create an instance of an errorObject, so
                //      compilation will fail. (begining to see abstract as a great failsafe...)
                //
                //      Second, if ErrorObject was not abstract, we would be only be calling the copy constructor on
                //      the reference to the base ErrorObject class and not the CriticalError we threw. For all it can
                //      tell, there is an ErrorObject at the end of the reference. It has no idea we are leveraging
                //      polymorphism to observe a CriticalError. 
                //      Importantly, this means all details of the derived class will be sliced off during copy. 
                //      The next catch block would have no idea this error was originally a CriticalError obj.
                //
                //      This is why it is important to use 'throw;' rethrow an exception. You want the next catch
                //      clause to see the full object thrown originally. 
                
                std::cout << errorObject.What();
            }
        }
        catch (const ErrorObject& errorObject)
        {
            std::cout << errorObject.What();
            std::cout << "break;\n";
            break;
        }
    }

    return 0;
}
#include <iostream>
#include "ExceptionObject.h"
#include "Utilites.h"

void DoSomething(unsigned int i){
    if(i==3)
        throw ExceptionObject(i);
    std::cout<< "DoSomething i : " << i << "\n";
}

void DoSomething2(unsigned int i){
    if(i==3){
        ExceptionObject ex(i);
        throw ex;
    }
    std::cout<< "DoSomething i : " << i << "\n";
}

ExceptionObject<unsigned int>& RefOutOfScopeObject(){
    ExceptionObject<unsigned int> exceptionObject{5};
    return exceptionObject;
}

int main(int argc, char **argv){

    //Throwing class objects as exceptions

    //I created a template class called ExceptionObject which wraps around a type
    ExceptionObject exceptionObject{int{5}};

    //as a child of OutputStremObject it overrides the OutputStreamOverload() func 
    //to write to output streams
    std::cout << "exceptionObject : "<< exceptionObject << "\n";

    //it also implements a copy constructor, as is required by catch arguments
    ExceptionObject exceptionObject2{exceptionObject};
    std::cout << "exceptionObject2 : "<< exceptionObject2 << "\n\n";

    Util::PrintEndLine(2);
    std::cout << "NOTE: Instances of templates with different T types DO NOT share static variables!\n";
    std::cout << "      If that is the goal, have template inherit from NON template class with static var\n";
    Util::PrintEndLine(2);
    std::cout << "\n";
    Util::PrintTitleLine("Passing Objects To Catch");

    try{
        for(unsigned int i{}; i < 5; ++i){
            DoSomething(i); //<-- runs statement 'throw ExceptionObject(i);'
        }
    } catch (ExceptionObject<unsigned int>& ex){ //because I made ExceptionObject a class template, input arguments of
                                                //of the class require type. This could be solved by using a pointer
                                                //to the type, however, this lesson is about objects being passed as
                                                //catch arguments. Changing this to a pointer to heap memory would
                                                //miss the mark
        std::cout << "Caught Exception ex : " << ex << "\n";

    }

    //So here is the interesting part of the lecture. 
    
    //The teacher is saying that making the input parameter of the catch call a reference
    //to an object will allow the compiler to reference the object we create and throw instead of copying it.

    //This can be seen by adding or removing the & for the catch parameter of ex. What seems a little strange to
    //me is that I was able to get the same functionality in 127. by deleting the copy constructor and relying on
    //compiler optimization to create the object in the catch parameters place (which didnt take a reference).

    //Isn't doing the above more restrictive because now we have no choice but to create the exceptionObject in
    //one statement? If we create the object anywhere else wont the reference in the catch be referencing out of
    //scope memory?

    Util::PrintEndLine();
    try{
        for(unsigned int i{}; i < 5; ++i){
            DoSomething2(i); //<-- runs statement 'throw ex;' where ex was created one line up
        }
    } catch (ExceptionObject<unsigned int>& ex){ //because I made ExceptionObject a class template, input arguments of
                                                //of the class require type. This could be solved by using a pointer
                                                //to the type, however, this lesson is about objects being passed as
                                                //catch arguments. Changing this to a pointer to heap memory would
                                                //miss the mark
        std::cout << "Caught Exception ex : " << ex << "\n";
    Util::PrintTitleLine("bottom of catch body {...}");
    }

    Util::PrintEndLine();

    //Ok fun. I am wrong. The reference to ExceptionObject is working unlike I would expect it to if it were a normal
    //method parameter. It is still making a copy, and that copy is usable. So what is & really doing?

    //My guess is there is some interesting going ons behind the seen for throwing and catching. It could be that
    //c++ is smart enough to ignore the ref and make a copy if an object is about to leave scope and it is used in a throw.

    //If this is the case I see no reason to ever put anything any but a & as a catch parameter. If the compiler
    //is going to make copies of thrown arguments automatically, this prevents us from referencing out of scope data.
    //In addition using & will make the compiler build the argument in place if the throw statement is creating it.

    //Seems like a free win with no downsides. 

    //NOTE:: MORE CONFUSION, it is not as simple as I expected. In removing & above I get the following output...
    /*
        DoSomething i : 0
        DoSomething i : 1
        DoSomething i : 2
        Exception Object (2) Constructed
        Exception Object (3) Constructed
        Exception Object (2) Copied To Create Exception Object (3)
        Exception Object (2) Destructed
        Exception Object (4) Constructed
        Exception Object (3) Copied To Create Exception Object (4)
        Caught Exception ex : 3
        Exception Object (4) Destructed
        Exception Object (3) Destructed
    */

    //As we can trace, the exception object 2 is created in do something on its own.
    //Then a copy is constructed on throwing it.
    //Then ANOTHER copy is created somewhere?! I think not only does throw make a copy of an object, but
    //so does the catch.

    //This is why it is important to use a & in the parameters when catching objects. This allows the catch to 
    //reference the copy throw made, and not make its own. The real question is why isn't it a reference by default?
    //Actually, where the heck does ExceptionObject(3) even live? where is its scope?

    /*
        ------------------------bottom of catch body {...}
        Exception Object (4) Destructed
        Exception Object (3) Destructed
        --------------------------------------------------
    */

    //Ok, so using some cout lines it becomes obvious that throw creates a copy in the catch block that handles it?
    //At this point I'm not even sure if its throw doing this or some weird synergy between the two. Either way
    //the first copy (and second if & isnt used) will die at the end of catch scope. 

    //Again, why isnt catch designed to take in references by default? Seems like a no brainer.

    //////
    //
    //  LONG STORY SHORT!
    //
    //  If the exception object is not created in statement 'throw', A COPY WILL BE MADE.
    //  If the catch does not use a reference & to this object as a parameter, ANOTHER COPY WILL BE MADE.
    //  Use a reference & in the parameter everytime to avoid second copy opperation. 
    //  There seems to be no risk of referencing data out of scope in this particular case unlike a normal function call.
    //
    //////

    //The same can not be said about pointers though. C++ is not going to copy an object at the end of a pointer for
    //you automatically and change said pointer if it references data out of scope. That is on you to keep track of. 

    //Make sure pointers are always referrencing to valid data. Don't coun't on any compiler magic for those bad boys.

    Util::PrintTitleLine("Testing references as input params");
    std::cout << RefOutOfScopeObject() << "\n"; //<-- fyi returning a reference to local data from a standard func
    Util::PrintEndLine();                       //    raises a g++ compiler warning. Run this, and you get a
                                                //    segmentation fault. Just goes to show how different
                                                //    try catch works from a normal func call...


    return 0;
}
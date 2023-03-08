#include <iostream>

template <typename ValueType>
ValueType AddNumbers(ValueType a, ValueType b){
    return a + b;
}

int main(int argc, char **argv){

    //Function Like Entities

    //The first thing this makes me think of is find if predicate. This is a standard library function that takes in
    //a list of elements to search through given a certain search function which is then executed on each individual
    //element. 

    //An exmaple given in a lecture was a function that took in a string and a function where the function would be
    //responsible for the strings encryption. The output would be the encrypted string. Whats neat is that we don't
    //have to write a completely different string modification function to decrypt the string. Instead we can just
    //provide as input a decryption functionality to the same call.

    //This is trivial for simple shift ciphers and the like.

    //Now lets see how we can actually start doing these things...


    //  Function pointers

    //  Function pointers are a mechanism in c++ allowing us to store the address at which a function lives
    //  so that it may be called later.

    //  We create function pointers with a peculiar looking syntax:

//    The return type for the function we are storing.
//    |
//    |           The name of the functionPointer we are creating. Strang syntax requires we wrapp this within
//    |           |    parenthesis and start with the asterisk.
//    |           |
//    |           |                The input parameters of the function we are storing the address for
//    |           |                |
//    |           |                |               The function's name we are associating with this function pointer
//    |           |                |               |        While we are getting the address here with &, this is not
//    V           V                V               V        required! C++ accepts the name alone, but I find this more readable.
    double (*funcPointer) (double, double) = &AddNumbers;


    //Looking at the above this sorta looks more akin to a function declaration than a variable definition.
    //My guess is that inorder to store a function address and use it later the compiler has to have a sense
    //what the input parameters are and what will be returned. Forgive me if I'm wrong but (*funcPointer) is
    //also the syntax for a void pointer right?

    //Actually, taking this a step forward we have seend something similar to the assignment on the back end
    //of this statement. When we don't want anyone to use a default constructor we declare it = delete.
    //  ' Object() = delete; '
    //It could very well mean that behind the scenes we are assigning the constructor the address to a special
    //delete function the compiler knows how to process, preventing compilaton if called. Not particularly
    //helpful, but interesting!

    double (*funcPointer2) (double, double) = AddNumbers;
    //the above shows we dont need to get the address of AddNumbers to assign it to funcPointer

    double (*funcPointer3) (double, double) {&AddNumbers};
    double (*funcPointer4) (double, double) {AddNumbers};
    //in addition we can use list initialization syntax instead of assignment.
    //I wonder if we could do the same with delete....

    //We can even use our magic auto type deduction keyword to create pointers to functions.
    //  auto funcPointer5 = AddNumbers;

    //well, at least we could if I was directly following the lecture and not using a function template.
    //Because of this we gotta tell the compiler we want to associate this with the double version

    auto funcPointer5 = AddNumbers<double>;
    //the auto deduction is smart too, it will come up with the same thing above with all of the below:
    auto funcPointer6 = &AddNumbers<double>;
    auto* funcPointer7 = AddNumbers<double>;
    auto* funcPointer8 = &AddNumbers<double>;

    //Now we can use any of these just like a normal function.

    std::cout << " funcPointer(20,11) : " << funcPointer(20,11) << "\n";

    //Note, for the same reason I was unable to create a function pointer to a function template without
    //specifying the <double> variant, we cannot create auto function pointers to nullptr.
    //It seems, somewhat like references, function pointers MUST BE INITIALIZED with hard coded input and output types.
    //The difference is that as long as another function can meet those same requirements, its address could be
    //assigned over an existing one. Just to confirm this...

    //funcPointer5 = AddNumbers<int>;

    //  error: no matches converting function 'AddNumbers' to type 'double (*)(double, double)'
    //    88 |     funcPointer5 = AddNumbers<int>;
    //       |                    ^~~~~~~~~~~~~~~

    //Eactly what I thought


    //Callback functions


    return 0;
}
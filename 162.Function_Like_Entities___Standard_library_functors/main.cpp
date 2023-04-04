#include <iostream>

double MultiplyByThreeAndAdd(const double x, const double y){
    return x*3 + y*3;
}

template<typename FunctorOrFuncPointer>
double DoSomethingWithXAndY(const double x, const double y, FunctorOrFuncPointer functionality){
    return functionality(x,y);
}

int main(int argc, char **argv){

    //Built in Standard Library Functors

    //There are several functors already built into the C++ Standard Library

    //These include...
    //  std::plus
    //  std::minus
    //  std::greater
    //  etc...

    //  All of the above are templates, and should work well with most standard library types

    //Similar to how we created instances of the functors in the previous lecture, we can do the same with these.

    std::plus<int> plusFunctor;
    std::minus<int> minusFunctor;
    std::greater<int> greaterFunctor;

    //Functors are not limitied in use of the () opperator. They can be overloaded, and in this case you will see
    //that these take in 2 arguments as opposed to the ones we created before with only one.

    std::cout<< "plusFunctor(10,5) : " << plusFunctor(10,5) << "\n";
    std::cout<< "minusFunctor(10,5) : " << minusFunctor(10,5) << "\n";
    std::cout<< "greaterFunctor(10,5) : " << greaterFunctor(10,5) << "\n";
    std::cout<< "greaterFunctor(5,10) : " << greaterFunctor(5,10) << "\n";

    //for more info on what other function objects are included in the standard library consult the
    //documentation...

    //https://en.cppreference.com/w/cpp/utility/functional (scroll down to function objects)


    //This is more related to the folder on functors but I thought I would put this here...

    //By making a function a template to take in a functor type object, one that uses (), we are not locked
    //to using function objects. In fact, we can use that template to create definitions that take in functors AND
    //pointers to functions. As long as either of these compiler under the templates use of () and the return types
    //match, they will work fine!

    //It almost makes you wonder why anyone would go to the effort of writing a callback as an input argument
    //
    //      foo( void (*modifier) (double& doubleInput)) {...}
    //
    //The above is limiting in that the function wont work with functors, just pointers to functions. At least
    //with a template you have the ability to accept both!
    //
    //      template<typename Modifier>
    //      foo(Modifier modifer) {...}
    //

    //Observe!
    std::plus<double> plusFunctorDouble;
    //functor usable (with standard library but will work with cust written ones as well)
    std::cout << "DoSomethingWithXAndY(1,1,plusFunctorDouble) : "<< DoSomethingWithXAndY(1,1,plusFunctorDouble) << "\n";
    //pointer to function usable
    std::cout << "DoSomethingWithXAndY(1,1,MultiplyByThreeAndAdd) : "<< DoSomethingWithXAndY(1,1,MultiplyByThreeAndAdd) << "\n";

    //  ^^^^^ ladies and gentlemen, I give you the power of templates ^^^^^^

    //the next lecture went into how you can expand functors to be constructed with class vars for use
    //I already discovered how this would be useful in my own experimentation with shift ciphering
    //The example they gave was creating a functor IsInBounds that can be constructed with a min and max,
    //clever but nothing I haven't seen so I am skipping taking notes...

    //(in addition you could set up mutators to change the range if you wanted, or even make the values public)

    return 0;
}
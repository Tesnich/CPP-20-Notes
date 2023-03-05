#ifndef FUNCTIONS
#define FUNCTIONS

template <typename T, typename P>
//                    ----------------------//This is trailing return type syntax!
auto maximum(T a, T b)-> decltype((a>b)?a:b)
{//                   ----------------------//  If the return type is not known, or cant be deduced before input arguments
    return (a>b) ? a : b;                   //  are available, using '->' will retroactively set the return type.
}                                           //  This is placed after the (args) and before the {body}

                                            //  This syntax was seen before, in the lecture about lambda functions!!!
                                            //  ie. auto funct = [](a,b)-> double { return a*b; };

//As was seen in lecture, if we called a template function returning auto type and assigned it to and auto variable,
//if the template was seperated in a declaration and definition in seperate files compilation would fail!

//This is because the compiler couldn't wait for linking to give auto the appropriate type! With this change, however,
//we can specify the logic of determining the return type within the declaration itself! Example below!

//1.) Bad auto declaration, failing compilation where called!
//                                ----
template <typename T, typename P> auto maximumBad(T a, P b);
//                                ----

//2.) Good auto declaration, passing compilation where called and proceeding to linker stage!
//                                ----                      ------------------------
template <typename T, typename P> auto maximumGood(T a, P b)->decltype((a>b)? a : b);
//                                ----                      ------------------------


#endif
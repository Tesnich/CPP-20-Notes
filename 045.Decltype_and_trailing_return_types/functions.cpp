#include "functions.h"

//This,(the good one), fails at the linker stage. 

//  I am pretty sure I knew this would happen. I dont think I can put the
//  definitions for templates in different files from where either the declarations are
//  or, at the very least, the location they are called from (ie. in main solution). Is there a good way to do this? 

//For now stick to just writing definitions only for templates...


//Below moved to main and commented out.

// //1.) Bad in declaration!
// //                                ----
// template <typename T, typename P> auto maximumBad(T a, P b)
// {//                               ----
//     return ((a>b)? a : b);
// }

// //2.) Good in declaration!
// //                                ----                      ------------------------
// template <typename T, typename P> auto maximumGood(T a, P b)->decltype((a>b)? a : b)
// {//                               ----                      ------------------------
//     return ((a>b)? a : b);
// }              
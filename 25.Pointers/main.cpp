#include <iostream>
#include <iomanip>

//Pointers!

const unsigned int BREAK_SIZE{50};

void lineBreak ()
{
    std::cout << std::setw(BREAK_SIZE) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
}

int main(){
    
    //pointers point to a variables location in memory, storing that address not the value located there

    //declaring a pointer in c++
    int * pNumber{}; //default initialized to nullptr
    double * pFractionalNumber{}; //default initialized to nullptr

    int * pNumber2{nullptr}; //same as above but more readable and safer if a compiler doesnt default initialize to nullptr
    double * pFractionalNumber2{nullptr}; //same as above but more readable and safer if a compiler doesnt default initialize to nullptr

    //All pointers have the same size in memory (a single address is the same size regardless of data type)
    std::cout << "Size of int    : " << sizeof(int) << std::endl;
    std::cout << "Size of double : " << sizeof(double) << std::endl;
    
    std::cout << "Size of ponter to int     : " << sizeof(pNumber) << std::endl;
    std::cout << "Size of pointer to double : " << sizeof(pFractionalNumber) << std::endl;

    //declaring pointers on same line require the * for each variable, base type (ie int) is the only global modifier
    // VVVVVVVVVVVVVVVVVV
    int * pointerToAnInt, justAnInt;

    int valueA{43};
    int valueB{99};
    int *pointerA{&valueA}; //& is the address opperator on valueA, deriving its position in memmory which we then stor in pointerA

    std::cout << "valueA   : " << valueA << std::endl;
    std::cout << "pointerA : " << pointerA <<std::endl;
    //how to view value that a pointer points to
    //use * to de-reference a pointer
    std::cout << "Value at pointerA : " << *pointerA << std::endl;
    std::cout << ">> Re-assign pointer A <<" << std::endl;
    pointerA = &valueB;
    std::cout << "pointerA : " << pointerA <<std::endl;
    std::cout << "Value at pointerA : " << *pointerA << std::endl;
    std::cout << ">> Re-assign valueB through PointerA <<" << std::endl;
    *pointerA = 11;
    std::cout << "pointerA : " << pointerA <<std::endl;
    std::cout << "Value at pointerA : " << *pointerA << std::endl;

    //pointer to character types
    lineBreak();

    char * pointerCharA {nullptr};
    char charVarA {'A'};
    pointerCharA = &charVarA;

    const char * pointerToCharString { "Hello World!" }; // !!! This is transformed into a pointer to the first char in this literal
    
    //char * pointerToCharString { "Hello World!" };
    //On some compilers this above is illegal because "Hello World!" is baked into memory as a const literal during compile time
    //Suddenly pointerToCharString is now illegaly pointing to a const value! We can't edit that! 
    //To pass this would have to be a pointer to a const char (ie. const char * pointerToCharString)

    std::cout << " pointerToCharString : " << pointerToCharString << std::endl; //char functionality in cout will read from pointer address until null terminator, this is only for char. Not int arrays or others!
    std::cout << "&pointerToCHarString : " << &pointerToCharString << std::endl; //method to get the address to cout
    std::cout << "*pointerToCharString : " << * pointerToCharString << std::endl; //The output is the current char the pointer is pointing to (just 'H')

    //further improving predicition program c style character storage

    const char predictions[][100] //old version using arrays of character arrays! (requires a pre-determined size for second level)
    {
        { "a lot of kinds running in the backyard!'" },
        { "a lot of empty beer bootles on your work table.'" },
        { "you Partying too much with kids wearing weird clothes.'" },
        { "you running away from something really scary'" },
        { "clouds gathering in the sky and an army standing ready for war'" },
        { "dogs running around in a deserted empty city'" },
        { "a lot of cars stuck in a terrible traffic jam'" },
        { "you sitting in the dark typing lots of lines of code on your dirty computer'" },
        { "you yelling at your boss. And oh no! You get fired!'" },
        { "you laughing your lungs out. I've never seen this before.'" }
    };

    //this can be improved if we use * to char instead so we dont have to change that size value everytime we add a string that exceeds size

    const char * predictions2[] //now we have an array of pointers to all these literals, and we dont need to provide the required size limit from before!
    {
        "a lot of kinds running in the backyard!'" , //The space after literal up to size 100 was wasted as a bunch of '\0' null terminators!
        "a lot of empty beer bootles on your work table.'" , // Now no space is wasted on those spots!
        "you Partying too much with kids wearing weird clothes.'" ,
        "you running away from something really scary'" ,
        "clouds gathering in the sky and an army standing ready for war'" ,
        "dogs running around in a deserted empty city'" ,
        "a lot of cars stuck in a terrible traffic jam'" ,
        "you sitting in the dark typing lots of lines of code on your dirty computer'" ,
        "you yelling at your boss. And oh no! You get fired!'" ,
        "you laughing your lungs out. I've never seen this before.'" 
    };

    //compiler doesn't like the {} brackets in this case

    //These c style strings can be accessed just as before thanks to how cout uniquely handles pointers to char

    std::cout << "predictions2[0] : " << predictions2[0] << std::endl;

    lineBreak();
    //Const pointer more info!

    //Pointer to const -> means pointer points to const value and system wont let you change it
    //const int *      -> however, you can still re-assign the variable to point elsewhere

    //Const pointer    -> means the pointer itself cannot be re-assigned to another place in memory
    //int* const       -> however, you can still edit the value corresponding to where that place in memory is!

    //Const pointer to const -> You can not edit the address the pointer points to nor the value at that location!
    //const int * const      ->

    const int constInt{10};
    const int * pointerToConstInt{&constInt}; //VALID!
    //Ilegal! const on base type must match!
    //int * pointerToInt{&constInt}; 

    //Ilegal! const on base type must match!
    //int * const constPointerToInt{&constInt};

    const int * const constPointerToConstInt{&constInt}; //VALID, we just added a new level of const to the outer level of the pointer, has no bearing on matching the base type we point to

    lineBreak();

    //array of const pointer to const char

    const char * students[]
    {
        "Daniel Gray",
        "Tuna Philbe",
        "The Rock",
        "Kumar Singh",
        "Sam Ali",
        "Dave Mahoro"
    };

    for(auto student : students)
        std::cout << "Original Students : " << student << std::endl;

    //so the above is an array of pointers to const char, we can not edit the char's that these pointers point to

    //AKA illegal : *students[0]= 'K';

    //HOWEVER, we can define ANOTHER const character * to another literal and then SWAP THEM

    const char * newStudent{"Jackie Chan"};

    students[0] = newStudent;

    //The list of students has been changed?! Well ofcourse, because we never made the pointers const themselves.
    //They can still point ANYWHERE

    for(auto student : students)
        std::cout << "New Students : " << student << std::endl;

    //To safegaurd against this happening we need to define this array as * const as well!

    const char * const students2[]
    {
        "Daniel Gray",
        "Tuna Philbe",
        "The Rock",
        "Kumar Singh",
        "Sam Ali",
        "Dave Mahoro"
    };

    //the below is now illegal!
    //students2[0] = newStudent;

    lineBreak();

    //relationship between pointers and arrays

    int scores[10] {11,12,13,14,15,16,17,18,19,20};
    int testValue{10};
    int * pointerToTestValue{&testValue}; // With a standard variable you provide the dereference opperator to get address for pointer
    int * pointerScore {scores}; //With and array, simply providing the variable itself will give the address in memory to the first element

    std::cout << "*pointerScore : " << *pointerScore << std::endl;
    std::cout << "pointerScore[0] : " << pointerScore[0] << std::endl; //as you can see, the pointer assigned to an array can be worked 
    std::cout << "pointerScore[0] : " << pointerScore[1] << std::endl; //just as you would an array itself!

    //HOWEVER, you are unable to get the size of the array it points to, it is ONLY a pointer!
    //std::cout << "size(pointerScore) : " << size(pointerScore) << std::endl; // COMPILE ERROR

    //when you assign an array to a pointer it is called POINTER DECAY, because you lose some functionality/info you had in the original data structure

    lineBreak();

    //swaping array data

    int array1 [] {1,2,3,4,5};
    int array2 [] {6,7,8,9,10};

    //how would I do this normally? Create a temp array, copy arr1 into it, then move 2 to 1, and temp to 2
    //TOO MUCH LOOPING! NOT EFFICIENT

    //Instead perhaps we can set up pointers that represent our array?

    int* pArray1 = array1; //turns the array names into modifiable pointers
    int* pArray2 = array2;

    int* temp;

    temp = pArray1;
    pArray1 = pArray2;
    pArray2 = temp;

    //Not sure what kind of point he was trying to make here? We didn't end up with two arrays swapped, just two pointers to arrays swapped?
    //Maybe how easy it is to perform a swap if you are storing your arrays in pointers? Its not like these are equivalent thanks to pointer decay.

    //I do see some usefulness actually, say you needed to process data in one direction from array A to B doing - or something on the elements
    //If this is dynamically done, like sometimes you need to swap the arrays and sometimes you dont 
    //You could do all these opperations on the pointers and then assign the arrays to the pointers as needed

    //still though, temp isnt needed, just assign directly? eh its a lecture not a real program

    lineBreak();

    //pointer arithmetic!

    //incrementing and decrementing a pointer to navigate an array
    // on the system level this works by changing the address in memory by the size of an entire element in that array, for an int ie. 4 bytes

    //we can do this in two ways, either increment the pointer to change where it is located
    std::cout << "*pointerScore     : " << *pointerScore <<std::endl;
    std::cout << "*(++pointerScore) : " << *(++pointerScore)<< std::endl;
    std::cout << "*(--pointerScore) : " << *(--pointerScore) << std::endl;

    //or we can add to the location of the pointer to get the subsequent values without altering its original position at the begining of the array

    for(size_t i{0}; i < std::size(scores); ++i)
        std::cout << "pointerScore + " << i << " : " << *(pointerScore +i) <<std::endl;

    lineBreak();

    //ofcourse this strategy can also be used to edit different values in the array

    *(pointerScore +5) = 9999;

    for(size_t i{0}; i < std::size(scores); ++i)
        std::cout << "pointerScore + " << i << " : " << *(pointerScore +i) <<std::endl;
    
    lineBreak();
    //interestingly enough you can also use the array itself and its pointer to navigate the array, a bit weird but hey it works?
    for(size_t i{0}; i < std::size(scores); ++i)
        std::cout << "pointerScore + " << i << " : " << *(scores +i) <<std::endl;

    //really arrays are pointers that can't be modified to point to a different spot and have more meta data for the array
    //++scores; is illegal

    lineBreak();

    //distance between pointers

    int * pointer1 {scores + 0}; // can also do {&scores[0]}
    int * pointer2 {scores + 8}; // can also do {&scores[8]}

    // there is a special type for distance between pointers, i guess because of different systems having different sizes. This offers consistency.

    std::ptrdiff_t positionDelta = pointer2 - pointer1;
    std::ptrdiff_t positionDeltaNeg = pointer1 - pointer2;

    std::cout << "Position Delta     : " << positionDelta << std::endl;
    std::cout << "Position Detla Neg : " << positionDeltaNeg << std::endl;
    std::cout << "sizeof(PositionDelta : " << sizeof(positionDelta) << std::endl;

    lineBreak();

    //comparing pointers!

    // use >,<,==,etc... as usual, nothing new for how this works

    lineBreak();

    //Dynamic Memory Allocation

    //All of the variables and values used up till this point have had a location on stack memory, this is memory that is controlled by scope and other c++ concepts
    //We can escape this area and store values on the heap if we want, and they will survive (indefinitely?) until we destory them.

    int * pointerToNumber{nullptr};
    pointerToNumber = new int; //This is where we dynamically allocate space for a single int on the heap!

                               // This memory belongs to our program from now on. The system
                               // cant use it for anything else, until we return control.
                               // after this line executes, we will have a valid memory location
                               // allocated. The size of the allocated memory will be such that it
                               // can store the type pointed to by the pointer.

    *pointerToNumber = 77;     // This value is stored on the heap! NOT THE STACK

    //we could also have just done 'int * pointerToNumber{new int {77}};'

    //if the new int was defined in a loop or some other scope that ends, it does not! It lives on!

    //as such we need to make sure we delete it when we are done!

    delete pointerToNumber;
    //since we deleted the int located at pointerToNumber's address that location is now owned by someone else
    pointerToNumber = nullptr; //we need to re-assign our pointer that was pointing there to nullptr, otherwise we could accidently write to it and crash something outside our program!!!!

    //DO NOT DELETE TWICE!!! That will really fuck up someone else's shit.

    //  >>Look out for Dangling Pointers!<<
    //  uninitialized pointers                  -> pointer created without setting it to a location or nullptr
    //  deleted pointer                         -> pointer address still floating around corresponding objected deleted
    //  pointers pointing to the same location  ->(sorta same issue as deleted pointer)

    lineBreak();

    //new can fail if there is not enough space on the heap to store the creation of an object
    //in cases like that we need to know how to properly handle the situation to regain flow of the program

    //Exception

    try
    {
        //int * lots_of_ints { new int[1000000000000000]};   //very large!
        int * dummyPointer{nullptr};
    }
    catch(std::exception& ex)
    {
        std::cout << "Caught exception ourselves : " << ex.what() << std::endl;
    }

    //std::nothrow, will try an opperation but not throw up an exception if it occurs 

    int * lots_of_ints2{nullptr};
    lots_of_ints2 = new(std::nothrow) int[1000000000000000];   //very large!

    if (lots_of_ints2!=nullptr) //we can then manually check whether or not our pointer was populated with a valid address
    {
        std::cout << "Data allocated!" << std::endl;
        delete[] lots_of_ints2; //if you are trying to delete an array you need to denote it as such using brackets in the delete call
    }
    else
    {
        std::cout << "Data allocation failed!" <<std::endl;
    }

    //there is no point in checking if a pointer is nullptr before deleting it
    //deleting a nullptr is a safe opperation

    int *pointerToNullptr{};

    delete pointerToNullptr;

    return 0;
}
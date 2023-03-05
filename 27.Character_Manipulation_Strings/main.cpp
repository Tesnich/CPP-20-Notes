#include <iostream>
#include <cctype> //used for character manipulation functionality
#include <cstring>
#include <iomanip>
#include <string>

int main(){

    char message[] {"Hello! 513-708 is the BEST area^code?!"};
    std::cout << std::left;

    //check if alpha numeric
    std::cout << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::isalnum()";
    for (char character : message)
        std::cout << std::isalnum(character);

    //check if alphabetic
    std::cout << std::endl << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::isalpha()";
    for (char character : message)
        std::cout << std::isalpha(character);

    //check if blank
    std::cout << std::endl << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::isblank()";
    for (char character : message)
        std::cout << std::isblank(character);

    //check if lowercase
    std::cout << std::endl << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::islower()";
    for (char character : message)
        std::cout << std::islower(character);

    //check if uppercase
    std::cout << std::endl << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::isupper()";
    for (char character : message)
        std::cout << std::isupper(character);

    //check if digit
    std::cout << std::endl << std::endl << std::setw(20) << " " << message << std::endl;
    std::cout << std::setw(20) << "std::isdigit()";
    for (char character : message)
        std::cout << std::isdigit(character);

    char newMessage[std::size(message)];

    for(size_t i{0}; i < std::size(message); ++i)
    {
        newMessage[i] = (std::islower(message[i])) ? std::toupper(message[i]) : message[i]; //Change to uppercase!
    }

    std::cout << std::endl << std::endl << std::setw(20) << "New String : " << newMessage << std::endl;
    
    //c-string manipulation!

    const char message1 [] {"The sky is blue."};

    const char* message2 {"The sky is blue."}; //decayed array

    std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;//strlen does not include null terminator in size calculation
    std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl; // size of whole array
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl; // just size of pointer

    std::cout << "std::strcmp(Alabama, Blabama) : " << std::strcmp("Alabama", "Blabama") << std::endl;
    std::cout << "std::strcmp(Blabama, Alabama) : " << std::strcmp("Blabama", "Alabama") << std::endl;
    std::cout << "std::strcmp(Alabama, Alabama) : " << std::strcmp("Alabama", "Alabama") << std::endl;
    std::cout << "std::strncmp(AAAA, AAAB, 3) : " << std::strncmp("AAAA", "AAAB", 3) << std::endl;
    std::cout << "std::strncmp(AAAA, AAAB, 4) : " << std::strncmp("AAAA", "AAAB", 4) << std::endl;
    std::cout << "strchr(Alabama State,'m') : " << std::strchr("Alabama State",'m') << std::endl; // find first occurance! //Actually returns an iterator

    const char * result = std::strchr("Alabama State",'m'); //finds first occurance

    std::cout << "result[0] : " << result[0] << std::endl;

    std::cout << "strchr(m1 m2 m3 m4 b5 b6,'m') : " << std::strrchr("m1 m2 m3 m4 b5 b6",'m') << std::endl; // find last occurance

    //concatonating and copying c strings
    //<cstring> library

    char dest[50] = "Hello ";
    std::cout << "dest : " << dest << std::endl;
    std::cout << "sizeof dest : " << sizeof(dest) << std::endl;
    char src[50] = "World!";

    std::strcat(dest, src); // takes from the src here and appends it to dest if space is available (if there isnt it may screw your memory, some compilers do not like)
    std::strcat(dest, " Goodbye World!"); //can be done with literals as well
    std::cout << "dest : " << dest << std::endl;
    std::cout << "sizeof dest : " << sizeof(dest) << std::endl; //size is unchanged

    char primary[] {"AAAAAAAAAA "};
    std::strncat(primary, "123456789",4);
    std::cout << "primary strncat(x,x,4) : " << primary << std::endl;
    std::strcpy(primary,"123456789");
    std::cout << "primary strcpy(primary,'123456789') : " << primary << std::endl; //clears rest of string with null terminators

    //std::string
    //#include <string>

    std::string fullName{}; //empty string
    std::string planet{"Earth. Where the sky is blue"}; //Initialized with string literal
    std::string preferedPlanet {planet}; //Initialized with another string
    std::string messageStr {"Hello there", 5}; //Initialized with part of another string or literal (first 5 characters)
    std::string weirdMessage{5,'e'}; //Initialized with 5x the character specified "eeeee"
    std::string greeting{"Hello World Program"};
    std::string bestStand{greeting,6,5}; //Initialized with part of existing string

    std::cout << "fullName : " << fullName << std::endl;
    std::cout << "planet : " << planet << std::endl;
    std::cout << "preferedPlanet : " << preferedPlanet << std::endl;
    std::cout << "messageStr : " << messageStr << std::endl;
    std::cout << "weirdMessage : " << weirdMessage << std::endl;
    std::cout << "greeting : " << greeting << std::endl;
    std::cout << "bestStand : " << bestStand << std::endl;

    //concatonating strings

    std::string stringA {"James "};
    std::string stringB {"Hillman "};

    std::string newString {stringA + stringB};

    //the + opperation works on std::string objects only, the literal "Hello" or "World" are c style char arrays despite appearances
    //thus the below will lead to compilation error
    //std::string badString {"Hello" + "World"};
    std::string goodString {stringA + "Hillman"}; //This does work however, because the type of "Hillman" literal is being converted to match the stringA type
    //the above is similar to doubles and ints
    // you could also have done
    std::string anotherGoodString {std::string{"Hello"} + " World"};


    std::cout << newString << std::endl;
    std::cout << goodString << std::endl;
    std::cout << anotherGoodString << std::endl;

    //there is also a namespace that can be included called std::string_literals
    //this allows you to denote literals as strings by appending an s to them

    std::string stringLiteralsString{};
    {
        using namespace std::string_literals; // in this block only, will stop applying after scope ends

        stringLiteralsString = "Hello"s + " World";
    }

    std::cout << stringLiteralsString << std::endl;

    //append method
    stringLiteralsString.append(" Program");
    std::cout << stringLiteralsString << std::endl;

    //append using initialization options for normal strings
    stringLiteralsString.append(5, '?');
    std::cout << stringLiteralsString << std::endl;
    //same goes for selection of parts of strings etc...

    // PS you can also append c style string arrays by just passing it in

    //if you want to add numbers to string you have to convert it to a string first

    std::string lettersAndNumbers{"Letters "};
    lettersAndNumbers = lettersAndNumbers + std::to_string(67); //another way to append to an existing string
    std::cout << lettersAndNumbers << std::endl;

    //similar to arrays you can loop through individual chars in a string using [i] as well as range (char element : stringMessage)

    //something new is that you can actually grab the individual chars using stringMessage.at(i), notation
    //you can go through .at(i) just like[i] to edit the char in a string

    //there is also .front() and .back() to fetch first and last chars

    //you are also able to get to the underlying cstring wrapped in string using .c_str() or .data()!

    const char * constPointerToCharArray {lettersAndNumbers.c_str()}; // const must be used here, will be unable to edit string through pointer

    char * pointerToCharArry {lettersAndNumbers.data()}; //using data lets you modify it though lol, thats a fun little work around

    //you are also able to get the number of characters from a string using the below syntax

    std::string testString1;

    std::string testString2{};

    std::cout << "The number of characters in lettersAndNumbers is : " << lettersAndNumbers.size() << std::endl;
    std::cout << "The number of characters in lettersAndNumbers is : " << lettersAndNumbers.length() << std::endl; // same result as size

    if(lettersAndNumbers.empty())
    {
        std::cout << "lettersAndNumbers is empty!" << std::endl;
    }
    else
    {
        std::cout << "lettersAndNumbers is NOT empty!" << std::endl;
    }

    if(testString1.empty())
    {
        std::cout << "testString1 is empty!" << std::endl;
    }
    else
    {
        std::cout << "testString1 is NOT empty!" << std::endl;
    }

    if(testString2.empty())
    {
        std::cout << "testString2 is empty!" << std::endl;
    }
    else
    {
        std::cout << "testString2 is NOT empty!" << std::endl;
    }

    //.capacity() will provide the size of the current array underlying the string object
    std::string testString3{"The sky is so blue, the grass kinda green. The water is brown. I need to move."};

    std::cout << "TestString3 capacity is : " << testString3.capacity() << std::endl; //size with null terminator
    std::cout << "TestString3 size is : " << testString3.size() << std::endl;

    //more meta data type things
    //.max_size(), for the maximum size that a string can hold on your system
    //.reserve(n), ask for specific array space for the c style string under the string wrapper
    //.shrink_to_fit() if there is more size than needed to fit current string re-allocate smaller array

    testString3.clear();
    std::cout << ">> testString3.clear() <<" << std::endl;
    std::cout << "TestString3 capacity is : " << testString3.capacity() << std::endl; //size with null terminator
    std::cout << "TestString3 size is : " << testString3.size() << std::endl;
    std::cout << ">> testString3 = AAAA <<" << std::endl;

    //inserting characters
    testString3 = "AAAA";
    testString3.insert(1,3,'M'); //string initialization standards after index given AKA... at index 1 insert 3x 'M' characters
    std::cout << testString3 << std::endl;
    testString3.insert(5, "____");
    std::cout << testString3 << std::endl;

    //erasing characters from a string
    testString3.erase(5,testString3.size()-5); //in this case erase the rest of the string after index spot 5
    // this syntax can be used to delete specific sections starting at index n and up to x following characters (n,x);
    std::cout << testString3 << std::endl;

    //string comparison
    //use standard <,>,==,!=,etc... uses lexigraphical(alphabetical) order
    //these can also be used on cstrings provided they are being compared to an std::string
    //make sure those are null terminated tho, because otherwise you may grab more than what we think is stored there until the system hits a '\0' char


    //another way similar to the c style way of std::strcmp()
    //std::string::compare() 
    //-negative value if before
    // 0 if equal
    //+positve if after

    std::string testString4{"AAAAA"};
    std::string testString5{"BBBBB"};

    std::cout << "testString4.compare(testString5) : " << testString4.compare(testString5) << std::endl; 

    std::string testString6{"BBBBBBBBBB"};

    std::cout << "testString5.compare(std::string{testString6,5}) : " << testString5.compare(std::string{testString6,5}) << std::endl; //dont forget you can compare portions of a string aswell if you use std::string{} and provide a length, or provide an index and then a length
    //this compare function actually has its own syntax you can look up online,
    //basically telling it where to start and what to compare by providing values infront of the target for the comparison
    // https://cplusplus.com/reference/string/string/compare/

    std::cout << "testString5.compare(0,5,testString6) : " << testString5.compare(0,5,testString6,0,5) << std::endl; //dont forget you can compare portions of a string aswell if you provide a length, or if you provide an index and then a length
    //essentially the above says start at index 0 and proceed 5 for testString5 and also start at index 0 for testString6 and proceed 5
    //doesnt look like i can just manipulate the target criteria alone but I could always just remember to provide the below if I wanted

    std::cout << "testString5.compare(0,testString5.size(),testString6) : " << testString5.compare(0,testString5.size(),testString6,0,5) << std::endl;
    
    //replacing part of a string
    std::string testString7{"---------------------------"};
    std::string replaceText{"Pizza"};

    std::cout << testString7 << std::endl;
    testString7.replace(2,replaceText.size(),replaceText); //syntax is index, size to replace, and replacement string
    std::cout << testString7 << std::endl;
    testString7.replace(2,replaceText.size()*3,replaceText); //index and size to be replaced doesnt need to equal size of text we replace
    std::cout << testString7 << std::endl;

    char soonToNotBeEmpty[30]{};
    //we can also copy a std::string completely or partially into a c string char array
    testString7.copy(soonToNotBeEmpty,5,0); //seems this if functionality implemented for copying a string into a c style string array (length then index, i know backawards to everything so far)
    std::cout << testString7 << std::endl;
    std::cout << soonToNotBeEmpty << std::endl;

    std::string testString8{"123456789"};
    std::cout <<"testString8 capacity :" << testString8.capacity() << std::endl;
    std::cout <<"testString8 size :" << testString8.size() << std::endl;
    testString8.resize(15,'f'); //resize the size of the char array associated with the string, and pipe in a bunch of the specified characters to fill the gap
    //testString8.resize(50); //resize as above but shortcut for populating with null characters
    //the way that I found explained this is that resize will give you all those elements in your string char array (reflected in size), the CAPACITY is just cleared space including your size of string and beyond in memory
    std::cout <<"testString8 capacity :" << testString8.capacity() << std::endl; //really unless the resize created more elements than capacity it shouldnt change, that what .reserve(n) does, sorta like bulldozing the memory to prepare for expanding the array. We can't use it until we resize the array!
    std::cout <<"testString8 size :" << testString8.size() << std::endl;

    //swapping string values
    std::string stringValueA{"James"};
    std::string stringValueB{"Brian"};
    std::cout << "String A :" << stringValueA << " String B :" << stringValueB << std::endl;
    stringValueA.swap(stringValueB);
    std::cout << "String A :" << stringValueA << " String B :" << stringValueB << std::endl;

    //searching in a string!!!

    //std::string::find
    std::string haystack{"Water was poured in the heater!"};
    std::cout << haystack << std::endl;
    std::cout << "Position where ter was found : " << haystack.find("ter") << std::endl;
    std::cout << "Position where chicken was found : " << haystack.find("chicken") << std::endl; //not found is std::string::npos
    std::cout << "std::string::npos : " << std::string::npos << std::endl; //npos specifies a value not found in a string
    //if(value == std::string::npos) failure!

    //searching forward from an index is another argument after search string
    std::cout << "Position where ter was found : " << haystack.find("ter", 5) << std::endl; //could easily update this value in loop to find multiple instances of a value
    
    //also takes in cstrings + there are tonnnnnnns of different find methods to get different results, REFER TO DOCUMENTATION FOR MORE INFO!


    //numbers to strings!!!

    std::string floatString {std::to_string(22.3f)}; //the others are stoi, stof, stod, etc... with that naming convention (string-> s 'to' float->f)(stof) etc
    float stringToFloat {std::stof(floatString)};

    std::cout << "floatString   : " << floatString << std::endl; //loss of data? 22.29999999
    std::cout << "stringToFloat : " << stringToFloat << std::endl; //regain the data back lol? 22.3

    //escape sequences !!!!

    // mainly use \ to escape the string for the next character
    std::cout << "\tHe said \"Get to the chopper!\"" << std::endl; // \t is for tab, \n for newline, \\ for a backslash,

    //these escapes can be stored in strings aswell, don't forget!

    //note \n will not flush the stream, but std::endl; will which may eat up some performance if that is not what you intend (aka in a loop)

    std::cout << "This cout statement makes a sound! \a" << std::endl; //an audible bell! (that i cant hear for some reason (on mac?)) no its because of the terminal in vs code
    // using ./ main (had to use sudo to give permision) plays a mac beep


    //Raw string literals!
    //raw string literals were introduced in c++11
    std::string rawString {R"(He said "Whats up Dog?"
    Need a sprite cranberry\\\\?)"}; //using the R"( )" syntax you can type whatever text you want and not have to worry about escaping characters
    
    std::cout << rawString << std::endl;

    //this format will work for char arrays aswell

    const char * rawCStyleString {R"(Another Raw "Quote" Literal)"};

    std::cout << rawCStyleString << std::endl;

    // The below is problematic and will not compile becuase c++ is looking for "( and )" to end raw literal
    // std::string sentence1 {R"(The message was "(Stay out of this!)" )"}; 

    //You can expand the key it looks for by putting things in between " and (
    std::string sentence1 {R"---(The message was "(Stay out of this!)" )---"};



    //copies of strings are problematic for efficiency 

    std::string messageAlpha {"Hello World"};
    std::string messageAlpha_copy{messageAlpha}; // double ammount of memory used to store the string!!!!

    std::cout << messageAlpha << std::endl;  
    std::cout << messageAlpha_copy << std::endl;  

    char * p1 = messageAlpha.data();
    char * p2 = messageAlpha_copy.data();

    std::cout << "&messageAlpha :" << &messageAlpha << std::endl; //****** This is the address of the first element in the array
    std::cout << "&messageAlpha[0] :" << &messageAlpha[0] << std::endl; //this gives cout the pointer to which it prints the char array
    std::cout << "p1  :" << p1 << std::endl; //this is the pointer, which passed to cout will print the char array
    std::cout << "&p1 :" << &p1 << std::endl; //this is the address of the pointer itself
    std::cout << "(void*)p1 :" << (void*)p1 << std::endl; //******* prints the pointer to which it points, first element of the array
    std::cout << "(void*)p2 :" << (void*)p2 << std::endl; //(void*) tells the cout to print as adress in memory!! Sorta like a cast

    //anyway the point of the above was to show that the data lives in different locations and that storage is not shared

    //where possible try not to copy strings. Use references or pointers to the data!
    std::string & messageAlpha_reference{messageAlpha}; //this is an alias to the data. If you dont intend to change it from the original this is good (maybe add const too!)



    //std::string_view 

    std::string_view sv {"Hello"};
    std::string_view sv1 {sv}; //view viewing the hello literal, NOT A COPY
    std::string_view sv2 {sv1}; //Another view viewing hello, NOT A COPY

    std::cout << "Size of string_view : " << sizeof(std::string_view) << std::endl;

    std::cout << "sv : " << sv << std::endl;
    std::cout << "sv1 : " << sv1 << std::endl;
    std::cout << "sv2 : " << sv2 << std::endl;

    //these views can be initialized with all kinds of strings, try to avoid non null terminated strings
    //changes to original literal will be seen in all views viewing it

    //THE VIEW OF THE DATA CAN BE MOVED, RESIZED, AND SHIFTED!!

    sv1.remove_prefix(1);
    sv1.remove_suffix(2);

    std::cout << "new resized sv1 view of orginal \"Hello\" literal : " << sv1 << std::endl;
    std::cout << "sv2 : " << sv2 << std::endl;


    // a string view can't outlive the string it is viewing!

    std::string_view sv3;

    {
        std::string stringInScope{"Scoped String"};
        sv3 = stringInScope;
        std::cout << "sv3 with literal in scope : " << sv3 << std::endl;
    }

    //BELOW IS BAD PRACTICE!!
    std::cout << "sv3 with literal out of scope : " << sv3 << std::endl; //once the original data a string view was watching dies it could be looking at anything!! Dangerous!!!
    // (maybe this is sort of a bad example because it looks like it is still pointing at the literal on my run,
    //  but in a more complex program or if a compiler acts differently this could be a disater)

    //sort of in the same line of thinking, string views allow for use of .data(). DO NOT USE if window for data has been modified by editting the prefix or suffix location
    //manipulation or read based on that could have undefined behavior

    //string views also allow for use of string methods like .length() and .front(). The important things is that string views dont copy data and save us memmory!

    //Know this though, string views are READ ONLY. Use them for cases where you would have used const string& !


    return 0;
}
#include <iostream>


int main(int argc, char **argv){

    //Notes on Combining the previous lectures' concepts

    //Lecture 391 goes into depth about how you can use multiple <=> overloads for the same class
    //to facilitate not only comparisons of the same class, but also standard types

    /*ie... in NumberWrap class that holds an int...
    
        std::strong_ordering operator<=> (const NumberWrap& numberWrap) const = default;

        std::strong_ordering operator<=> (int compVal) const {
            return intVal_ <=> compVal;
        }

        bool operator==(int compVal) const {
            return intVal_ == compVal;
        }

    */

    //The above code snipit would generate all logical operator overloads for NumberWrap compared to another NumberWrap
    //The code would also generate all logical operators for NumberWrap compared to int

    //IN ADDITION, because the compiler is smart enough to re-arrange expressions of ==, !=, and <=> from 'a <=> b' to 'b <=> a' as needed,
    //we have also created the inverse of the above NumbWrap comp Int, and covered all Int comp NumbWrap cases

    //Before, we had to overload such opperators as non member functions taking in two arguments of NumbWraper
    //relying on implicit conversion of the int to NumbWrap using a constructor

    //With the above method we have now achieved those comparisons and can mark the said constructor
    //taking in an int as 'explicit' if we want!

    //Even if that bit isn't as important, not having to overload 5 (because == creates !=) operators
    //saves us a ton of room and time

    return 0;
}
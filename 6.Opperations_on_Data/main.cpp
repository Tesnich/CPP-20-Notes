#include <iostream>
#include <ios>
#include <iomanip>
#include <limits>
#include <cmath>

int main(){
    //Precedence and associativity 

    int a{6};
    int b{3};
    int c{8};
    int d{9};
    int e{3};
    int f{2};
    int g{5};

    int result =  a + b * c - d/e -f + g; // 6 + 24 -3 -2 + 5
    std::cout << "result : " << result << std::endl;
    result = a/b*c+d-e+f;
    std::cout << "result : " << result << std::endl;
    result = (a + b)*c - d/e - f +g; // clearer to a reader by highlighting importantance/ forces order on compiler
    std::cout << "result : " << result << std::endl;
    // multiplication and division first
    // full list of order of opperations available below
    // https://en.cppreference.com/w/cpp/language/operator_precedence

    //incrementing 
    std::cout << "a : " << a << std::endl;
    a = a + 1;
    std::cout << "a : " << a << std::endl;
    std::cout << "a++ returns " << a++ << std::endl; //the postfix ++ returns the current value then increments
    std::cout << "a : " << a << std::endl;
    std::cout << "++a returns " << ++a << std::endl; //the prefix ++ increments the value then returns the altered value
    std::cout << "a : " << a << std::endl;

    //compound assignment opperators
    a += 2;
    std::cout << "a += 2 | a : " << a << std::endl;
    a -= 1;
    std::cout << "a -= 1 | a : " << a << std::endl;
    a *= 3;
    std::cout << "a *= 3 | a : " << a << std::endl;
    a /= 3;
    std::cout << "a /= 3 | a : " << a << std::endl;
    a %= 3;
    std::cout << "a %= 3 | a : " << a << std::endl;

    //relational opperators in c++
    // <, <=, >, >=, ==, != 
    std::cout << std::boolalpha;
    // the parenthesis are needed in this section because << has higher precedence than <, we get "<< a"
    std::cout << "a < b  : "<< (a < b) << std::endl;
    std::cout << "a <= b : "<< (a <= b) << std::endl;
    std::cout << "a > b  : "<< (a > b) << std::endl;
    std::cout << "a >= b : "<< (a >= b) << std::endl;
    std::cout << "a == b : "<< (a == b) << std::endl;
    std::cout << "a != b : "<< (a != b) << std::endl;
    // && and, || or

    //Output formating-------------------------------------------------------------
    //#include <ios>
    //#include <iomanip>

    std::cout << "\nOutput formating-------------------------------------------------------------" << std::endl;
    std::cout << "This sentence is \nSeperated by a new line character" << std::endl;
    //std::flush flushes buffer to terminal
    std::cout << "Testing std::setw() ...." << std::endl << std::endl << std::flush;
    //std::setw(), forces text output to be set into a formated character space of (n) length. Good for tables.
    //std::right , forces text to sit in the above cells either to the left or right
    //std::internal, sets the data internal justified meaning the sign (-) of data will sit apart from the text/value
    //std::setfill('-'), fills the empty space of the above mentioned cells with a character
    //std::boolalpha, bools cout as True or False
    //std::noboolalpha, bools cout as 1 or 0
    //std::showpos, shows the + sign for values
    //std::noshowpos, default format for positive values
    //std::dec, output values in decimal
    //std::hex, output values in hexidecimal
    //std::oct, output values in octal
    //std::showbase, show the base for integral types. Think 0x for hex and 0 for oct
    //std::scientific, E-10 etc...
    //std::fixed, 2006.0000
    //std::setprecision(), sets the precision . (significant digits) Limited by the type of variable and size
    //std::showpoint and std::noshowpoint, 12.0 vs 12

    //The above and more have indepth explanations and syntax at
    //https://en.cppreference.com/w/cpp/io/manip
    
    int columnWidth1 = 10;
    int columnWidth2 = 20;
    //the std::setw() needs to be set directly before the string being output, EVERY TIME
    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << "Ohio" << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << "South Carolina" << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << "California" << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << "California" << std::endl << std::endl; 

    std::cout << std::left;

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << "Ohio" << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << "South Carolina" << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << "California" << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << "California" << std::endl << std::endl; 

    std::cout << std::setfill('_');

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << "Ohio" << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << "South Carolina" << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << "California" << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << "California" << std::endl << std::endl;

    std::cout << std::setfill(' ');
    std::cout << std::internal;

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << - 10 << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << 20 << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << -1.009 << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << 35 << std::endl << std::endl; 

    std::cout << std::showpos;

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << - 10 << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << 20 << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << -1.009 << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << 35 << std::endl << std::endl; 

    //std::cout << std::fixed; //comented out to make numerical limits nicer

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << - 10 << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << 20 << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << -1.009 << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << 35 << std::endl << std::endl; 

    //fixed does not apply to ints, but by changing them to doubles below...

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << -10. << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << 20. << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << -1.009 << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << 35. << std::endl << std::endl; 

    //comented out to make numerical limits nicer
    //std::setprecision(10); // I think this is fighting with std::fixed

    std::cout << std::setw(columnWidth1) << "James" << std::setw(columnWidth1) << "Hillman" << std::setw(columnWidth2) << -10. << std::endl;
    std::cout << std::setw(columnWidth1) << "Ben" << std::setw(columnWidth1) << "Holiday" << std::setw(columnWidth2) << 20. << std::endl;
    std::cout << std::setw(columnWidth1) << "Kevin" << std::setw(columnWidth1) << "Bradner" << std::setw(columnWidth2) << -1.009 << std::endl; 
    std::cout << std::setw(columnWidth1) << "Jessica" << std::setw(columnWidth1) << "Kropveld" << std::setw(columnWidth2) << 35. << std::endl << std::endl; 

    //Numerical Limits! -------------------------------------------------------------
    std::cout << std::setw(80) << std::left << std::setfill('-') << "Numerical Limits" << std::endl << std::endl;

    //use #include <limits>, to output limits
    std::cout << std::setfill(' ');
    std::cout << std::setw(40) << "The range for int is from " << std::numeric_limits<int>::min() << " to " << std::numeric_limits<int>::max()<< std::endl;
    std::cout << std::setw(40) << "The range for unsigned int is from " << std::numeric_limits<unsigned>::min() << " to " << std::numeric_limits<unsigned>::max() <<std::endl;
    std::cout << std::setw(40) << "The range for double is from " << std::numeric_limits<double>::min() << " to " << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::setw(40) << "The range for double long is from " << std::numeric_limits<double long>::min() << " to " << std::numeric_limits<double long>::max() << std::endl;
    std::cout << std::setw(40) << "The range for float is from " << std::numeric_limits<float>::min() << " to " << std::numeric_limits<float>::max() <<std::endl <<std::endl;

    //Math Functions! -------------------------------------------------------------
    std::cout << std::setw(80) << std::left << std::setfill('-') << "Math Functions" << std::endl << std::endl;

    //#include <cmath>
    double weight {7.7};
    std::cout << std::noshowpos << std::setfill(' ');
    std::cout << std::setw(25) << "Weight is " << weight << std::endl;
    std::cout << std::setw(25) << "Floor of weight is " << std::floor(weight) << std::endl;
    std::cout << std::setw(25) << "Ceiling of weight is " << std::ceil(weight) << std::endl;
    double negative {-30};
    std::cout << std::setw(25) << "Negative number is " << negative << std::endl;
    std::cout << std::setw(25) << "Abs of negative is " << std::abs(negative) << std::endl;
    std::cout << std::setw(25) << "The exp of 10 is " << std::exp(10) << std::endl;
    std::cout << std::setw(25) << "3^4 is " << std::pow(3,4) <<std::endl;
    std::cout << std::setw(25) << "Log2 of 8 is " << std::log2(8) <<std::endl;
    std::cout << std::setw(25) << "Round of 6.4 is " << std::round(6.4) <<std::endl;
    std::cout << std::setw(25) << "Round of 6.5 is " << std::round(6.5) <<std::endl;
    // tons more for exp, log, sin, cos etc
    // check out the link below for more information...
    // https://en.cppreference.com/w/cpp/header/cmath

    return 0;
}
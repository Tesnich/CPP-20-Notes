#include <iostream>
#include <iomanip>
#include <bitset>

const unsigned int short maskBit0 {0b00000001};
const unsigned int short maskBit1 {0b00000010};
const unsigned int short maskBit2 {0b00000100};
const unsigned int short maskBit3 {0b00001000};
const unsigned int short maskBit4 {0b00010000};
const unsigned int short maskBit5 {0b00100000};
const unsigned int short maskBit6 {0b01000000};
const unsigned int short maskBit7 {0b10000000};

void use_options_v0 (bool flag0, bool flag1, bool flag2, bool flag3,
      bool flag4, bool flag5, bool flag6, bool flag7){
          
    std::cout << "Flag0 is : " << flag0 << ", do something with it." <<  std::endl;
    std::cout << "Flag1 is : " << flag1 << ", do something with it."<<  std::endl;
    std::cout << "Flag2 is : " << flag2 << ", do something with it." <<  std::endl;
    std::cout << "Flag3 is : " << flag3 << ", do something with it."<<  std::endl;
    std::cout << "Flag4 is : " << flag4 << ", do something with it."<<  std::endl;
    std::cout << "Flag5 is : " << flag5 << ", do something with it."<<  std::endl;
    std::cout << "Flag6 is : " << flag6 << ", do something with it."<<  std::endl;
    std::cout << "Flag7 is : " << flag7 << ", do something with it."<<  std::endl;
    return;
}

void useMaskOptions (unsigned char options)
{
    std::cout << "Flag0 is : " << ((options & maskBit0) >> 0) << ", do something with it." <<  std::endl;
    std::cout << "Flag1 is : " << ((options & maskBit1) >> 1) << ", do something with it."<<  std::endl;
    std::cout << "Flag2 is : " << ((options & maskBit2) >> 2) << ", do something with it." <<  std::endl;
    std::cout << "Flag3 is : " << ((options & maskBit3) >> 3) << ", do something with it."<<  std::endl;
    std::cout << "Flag4 is : " << ((options & maskBit4) >> 4) << ", do something with it."<<  std::endl;
    std::cout << "Flag5 is : " << ((options & maskBit5) >> 5) << ", do something with it."<<  std::endl;
    std::cout << "Flag6 is : " << ((options & maskBit6) >> 6) << ", do something with it."<<  std::endl;
    std::cout << "Flag7 is : " << ((options & maskBit7) >> 7) << ", do something with it."<<  std::endl;

    return;
}



int main(){
    // Implicit Data Conversions - Automatic

    // int + int - int * int (opperands must be same type for arithmetic) double + double - double * double
    // conversions always go in favor of the largest data type (size in memory)

    double price {45.6};
    int units {10};

    auto totalPrice = price * units; //int units is turned into a double 

    std::cout << std::setw(50) << std::setfill('-') << "Implicit Data Conversions" << std::setfill(' ') << std::endl;
    std::cout << std::setw(25) << "Size of price : " << sizeof(price) << std::endl;
    std::cout << std::setw(25) << "Size of units : " << sizeof(units) << std::endl;
    std::cout << std::setw(25) << "Size of totalPrice : " << sizeof(totalPrice) << std::endl;
    // below chart can be used to predict conversion direction when not doing an assignment
    // >>int>>unsigned int >> long >> unsigned long >> long long >> unsigned long long >> float >> double >> long double

    int x;
    double y {45.44};
    x = y; //narrowing implicit conversion on assignement (data lost in transfering from the right (double) to left (int)

    //Explicit Data Conversions - Manual

    double x2 {12.5};
    double y2 {34.6};

    auto sum = static_cast<int>(x) + static_cast<int>(y); //c++ casts, checked by compiler incase there is an issue
    auto sum2 = static_cast<int> (x + y);
    std::cout << std::setw(50) << std::setfill('-') << "Explict Data Conversions" << std::setfill(' ') << std::endl;
    std::cout << std::setw(25) << "Size of x2 : " << sizeof(x2) << std::endl;
    std::cout << std::setw(25) << "Size of y2 : " << sizeof(y2) << std::endl;
    std::cout << std::setw(25) << "Size of sum : " << sizeof(sum) << std::endl;
    std::cout << std::setw(25) << "Size of sum2 : " << sizeof(sum2) << std::endl;

    //Older style c casts (more dangerous, use the above)
    double pi {3.14};
    auto intPi = (int)(pi); // not intuative, may cause reading issues
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    std::cout << std::setw(25) << "Size of pi : " << sizeof(pi) << std::endl;
    std::cout << std::setw(25) << "Size of intPi : " << sizeof(intPi) << std::endl;

    //underflow and overflow

    unsigned char charVar {55};
    unsigned char val1 {130};
    unsigned char val2 {131};
    charVar = val1 + val2;
    std::cout << std::setw(50) << std::setfill('-') << "UnderFlow Overflow" << std::setfill(' ') << std::endl;
    std::cout << std::setw(25) << "char var print : " << charVar << std::endl;
    std::cout << std::setw(25) << "char var val : " << static_cast<int>(charVar) << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    charVar = 253;
    for (int i = 0; i < 5; ++i )
    {
        ++charVar;
        std::cout << std::setw(25) << "char var print : " << charVar << std::endl;
        std::cout << std::setw(25) << "char var val : " << static_cast<int>(charVar) << std::endl;
    }

    std::cout << std::setw(50) << std::setfill('-') << "Bitwise Operators" << std::setfill(' ') << std::endl;
    //Bitwise Operators (everything below this point works on intgers, NOT DOUBLES)
    //#include <bitset>
    unsigned short int data {0b11111110};
    std::cout << std::left;
    std::cout << std::setw(25) << "Data in decimal" << ":" << std::dec << data << std::endl;
    std::cout << std::setw(25) << "Data in hexidecimal" << ":" << std::hex << data << std::endl;
    std::cout << std::setw(25) << "Data in octal" << ":" << std::oct << data << std::endl;
    std::cout << std::setw(25) << "Data in binary" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    //shifting bits left doesnt loop, bits are padded with 0 and shifting bits back does not bring back a 1
    // shifting accommplished with (value << n)or (value >> n)
    data = static_cast<unsigned short int>(data >> 1); //when shifting bits you dont need to cast the data back into the appropriate type for storage, it is done implicitly, but for understanding we need to realize that it becomes an int then we mash it back into a short in this case
    std::cout << std::setw(25) << "Data in binary shift +1" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl; // bit shifting cut it in half!
    data = data >> 1;
    std::cout << std::setw(25) << "Data in binary shift +1" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl; // almost cut in half, truncating it because not equally divisable
    data = data << 1; //shift to the left
    std::cout << std::setw(25) << "Data in binary shift -1" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    data = data << 2; //shift to the left
    std::cout << std::setw(25) << "Data in binary shift -2" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    data = data << 7; //shift to the left
    std::cout << std::setw(25) << "Data in binary shift -7" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    data = data << 1; //shift to the left
    std::cout << std::setw(25) << "Data in binary shift -1" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    data = data >> 1; //shift to the left
    std::cout << std::setw(25) << "Data in binary shift +1" << ":" << std::setw(25) << std::bitset<16>(data) << std::dec << data <<std::endl;
    //bit shifting is not supported for types smaller than int
    //result of (data >> n ) or (data << n) is upgraded to int! then we cast it back into data using an explicit conversion
    std::cout << std::right << std::setw(50) << std::setfill('-') << "Logical Bitwise Operators" << std::setfill(' ') << std::left << std::endl;
    //a&b is true only if both a and b are ture
    //a|b is true if either a or b is true
    //~a is true only in cases where a if false regardless of b state
    //a^b (XOR) is true only if a and b are in different states
    unsigned short int dataA {0b00000011};
    unsigned short int dataB {0b00000101};
    std::cout << std::setw(25) << "dataA" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    std::cout << std::setw(25) << "dataB" << ":" << std::setw(25) << std::bitset<8>(dataB) << std::setw(25) << std::dec << dataB <<std::endl;
    std::cout << std::setw(25) << "dataA & dataB" << ":" << std::setw(25) << std::bitset<8>(dataA & dataB) << std::setw(25) << std::dec << (dataA & dataB) <<std::endl;
    std::cout << std::right << std::setw(100) << std::setfill('-') << " " << std::setfill(' ') << std::left << std::endl;

    std::cout << std::setw(25) << "dataA" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    std::cout << std::setw(25) << "dataB" << ":" << std::setw(25) << std::bitset<8>(dataB) << std::setw(25) << std::dec << dataB <<std::endl;
    std::cout << std::setw(25) << "dataA | dataB" << ":" << std::setw(25) << std::bitset<8>(dataA | dataB) << std::setw(25) << std::dec << (dataA | dataB) <<std::endl;
    std::cout << std::right << std::setw(100) << std::setfill('-') << " " << std::setfill(' ') << std::left << std::endl;

    std::cout << std::setw(25) << "dataA" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    std::cout << std::setw(25) << "dataB" << ":" << std::setw(25) << std::bitset<8>(dataB) << std::setw(25) << std::dec << dataB <<std::endl;
    std::cout << std::setw(25) << "~dataA" << ":" << std::setw(25) << std::bitset<8>(~dataA) << std::setw(25) << std::dec << (~dataA) <<std::endl;
    std::cout << std::setw(25) << "~dataA (unsign int cast)" << ":" << std::setw(25) << std::bitset<8>(~dataA) << std::setw(25) << std::dec << static_cast<unsigned int>(~dataA) <<std::endl;
    std::cout << std::right << std::setw(100) << std::setfill('-') << " " << std::setfill(' ') << std::left << std::endl;
    
    std::cout << std::setw(25) << "dataA" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    std::cout << std::setw(25) << "dataB" << ":" << std::setw(25) << std::bitset<8>(dataB) << std::setw(25) << std::dec << dataB <<std::endl;
    std::cout << std::setw(25) << "dataA ^ dataB (XOR)" << ":" << std::setw(25) << std::bitset<8>(dataA ^ dataB) << std::setw(25) << std::dec << (dataA ^ dataB) <<std::endl;
    
    //std::bitset<n> ONLY EFFECTS DISPLAY, it will not change the result of bitwise logical opperations (i was incorrectly thinking larger bitset would pad more 1s on flip, not true) 
    std::cout << std::right << std::setw(50) << std::setfill('-') << "Compound Bitwise Operators" << std::setfill(' ') << std::left << std::endl;
    //>>=, <<=, &=, ^=, |= 
    //no compund for ~ bitwise becuse it is a uniary opperator
    //essentially the same as the above but assigns result back into the variable, like +=
    std::cout << std::setw(25) << "dataA" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    dataA <<= 1;
    std::cout << std::setw(25) << "dataA after <<=" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;
    dataA &= dataB;
    std::cout << std::setw(25) << "dataA after &= dataB" << ":" << std::setw(25) << std::bitset<8>(dataA) << std::setw(25) << std::dec << dataA <<std::endl;  

    std::cout << std::right << std::setw(50) << std::setfill('-') << "Masks" << std::setfill(' ') << std::left << std::endl;

    //Masks highlight position for bit of interest with a 1, all other positions set to 0
    //can be used in tandem with logical bitwise operators to toggle bits
    unsigned int short dummyVal {0b01101001};

    // masks moved to global scope for use methods outside main
    // const unsigned int short maskBit0 {0b00000001};
    // const unsigned int short maskBit1 {0b00000010};
    // const unsigned int short maskBit2 {0b00000100};
    // const unsigned int short maskBit3 {0b00001000};
    // const unsigned int short maskBit4 {0b00010000};
    // const unsigned int short maskBit5 {0b00100000};
    // const unsigned int short maskBit6 {0b01000000};
    // const unsigned int short maskBit7 {0b10000000};

    //setting particular bit position in dummy to 1
    std::cout << std::setw(25) << "maskBit1" << ":" << std::setw(25) << std::bitset<8>(maskBit1) << std::setw(25) << std::dec << maskBit1 <<std::endl;
    std::cout << std::setw(25) << "dummyVal" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;
    dummyVal |= maskBit1; // | or bit operator keeps integrity of full dummyval except for the one we are interested in because the rest of the bits in the mask are 0
    std::cout << std::setw(25) << "dummyVal |= maskBit1" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;

    //&=(~mask) reversing the mask and then doing and ( this achieves setting one particular bit to 0, opposite of the above)
    std::cout << std::right << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::left << std::endl;
    std::cout << std::setw(25) << "maskBit1" << ":" << std::setw(25) << std::bitset<8>(maskBit1) << std::setw(25) << std::dec << maskBit1 <<std::endl;
    std::cout << std::setw(25) << "dummyVal" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;
    dummyVal &= (~maskBit1); // | or bit operator keeps integrity of full dummyval except for the one we are interested in because the rest of the bits in the mask are 0
    std::cout << std::setw(25) << "dummyVal &= (~maskBit1)" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;

    //multiple masks can be used at once, logic heavy haha
    std::cout << std::right << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::left << std::endl;
    std::cout << std::setw(25) << "maskBit1" << ":" << std::setw(25) << std::bitset<8>(maskBit1) << std::setw(25) << std::dec << maskBit1 <<std::endl;
    std::cout << std::setw(25) << "maskBit2" << ":" << std::setw(25) << std::bitset<8>(maskBit2) << std::setw(25) << std::dec << maskBit2 <<std::endl;
    std::cout << std::setw(25) << "dummyVal" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;
    dummyVal |= (maskBit1 | maskBit2); //basically using 0b00000110 for mask .. | can be chained for n masks
    std::cout << std::setw(25) << "dummyVal |= (mb1 | mb2)" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;

    //fancy way to get the state of any bit positon
    //do an & against the mask for that position, then shift >> by the position for the set bit of said mask, resulting int from implicit conversion will either be 0 or 1 based on if the position in the checked variable had a 0 or 1 in that spot
    std::cout << std::right << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::left << std::endl;
    std::cout << std::setw(25) << "dummyVal" << ":" << std::setw(25) << std::bitset<8>(dummyVal) << std::setw(25) << std::dec << dummyVal <<std::endl;
    std::cout << "The bit at position 0 is " << ((dummyVal & maskBit0) >> 0) << std::endl;
    std::cout << "The bit at position 6 is " << std::boolalpha << static_cast<bool>((dummyVal & maskBit6) >> 6) << std::endl;
    std::cout << "The bit at position 7 is " << static_cast<bool>((dummyVal & maskBit7) >> 7) << std::endl;

    std::cout << std::right << std::setw(50) << std::setfill('-') << "Memmory Efficient Arguments Using Masks" << std::setfill(' ') << std::left << std::endl;
    //EXAMINE METHODS AT TOP OF FILE

    use_options_v0(0,1,0,1,0,1,0,1); //uses 8 booleans, 8 bytes of memory!
    unsigned char maskOptions{0b11110000};
    std::cout << std::right << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::left << std::endl;
    useMaskOptions(maskOptions); //uses one char, (one byte?, whatever it is way less!)

    std::cout << std::right << std::setw(50) << std::setfill('-') << "Using Masks To Get RGB from hex" << std::setfill(' ') << std::left << std::endl;
    const unsigned int red_mask {0xFF000000};
    const unsigned int green_mask {0x00FF0000};
    const unsigned int blue_mask {0x0000FF00};
    const unsigned int alpha_mask {0x000000FF};

    unsigned int newColor {0xAABCDE00};

    std::cout << std::setw(25) << "Red is " << ((newColor & red_mask)>>24) << std::endl; //a shift is also required by 8 bits per position: because color is represented by 0-255, which is the size of a char, which fits in 8 bits,which are stacked onto one another to get full color hex code. Beautiful
    std::cout << std::setw(25) << "Green is " << ((newColor & green_mask)>>16) << std::endl;
    std::cout << std::setw(25) << "Blue is " << ((newColor & blue_mask)>>8) << std::endl;
    std::cout << std::setw(25) << "Alpha is " << ((newColor & alpha_mask)>>0) << std::endl;
    return 0;
}
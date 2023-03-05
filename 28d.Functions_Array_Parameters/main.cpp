#include <iostream>

double sumArray(double array[], size_t count); //declaration, array parameters just use the brackets[] after the name you give them
//fyi, you can supply a size for the array argument ie below...
//double sumArray(double array[5], size_t count); 
//This does absolutely nothing. It will accept arrays of smaller and greater sizes!
//Do this only if you think it helps you keep track, but remember it has no functional impact what so ever. Recommended that you don't put a value there!

int main(){
    //passing arrays as function parameters

    double array[] {10.0, 20.0, 30.0, 40.0, 50.0};

    double resultSum {sumArray(array,std::size(array))};            //calling a function that has an array parameter is as easy as just giving the name of the array
    std::cout << "Sum of the array : " << resultSum << std::endl;   //note though, that in use in the function it will practically be an decayed pointer to an array

    return 0;
}

double sumArray(double array[], size_t count)
{
    //array passed into function decays into a pointer
    std::cout << "size of pointer array decays into : " << sizeof(array) << std::endl; //compiler actually nails the point home here with a warning

    //you can effect the source array BECAUSE you have a pointer to the array, THE ORIGINAL DATA
    //array[1] = 70.0;

    double sum{0};

    for (size_t i{0}; i < count; ++i)
        sum += array[i]; //this action is being done on a pointer to an array, don't forget

    return sum;
}